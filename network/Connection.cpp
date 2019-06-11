//
// Created by jona on 2019-06-02.
//

#include <unistd.h>
#include <netinet/in.h>

#include "Connection.hpp"
#include "util/Util.hpp"
#include "../protocol/in/PacketInBase.hpp"
#include "../protocol/out/PacketOutBase.hpp"
#include "util/Exception.hpp"
#include "../protocol/in/PacketInHandshake.hpp"
#include "../protocol/in/PacketInRequest.hpp"
#include "../protocol/out/PacketOutResponse.hpp"
#include "../protocol/out/PacketOutPong.hpp"
#include "../protocol/in/PacketInPing.hpp"
#include "../protocol/out/PacketPlayOutDisconnect.hpp"
#include "../protocol/out/PacketOutLoginSuccess.hpp"
#include "../protocol/in/PacketInLoginStart.hpp"

namespace network {
    Connection::Connection(int socketFileDescriptor, uint32_t bufferSize) : socketFd(socketFileDescriptor),
                                                                            packetSerializer(
                                                                                    PacketSerializer(bufferSize)),
                                                                            rxBufferSize(bufferSize) {
        rxBuffer = (uint8_t *) malloc(sizeof(uint8_t) * bufferSize);
    }

    Connection::~Connection() {
        free(rxBuffer);
    }

    void Connection::run() {
        while (true) {
            PacketInBase *current;
            try {
                current = readPacket();
            } catch (Exception &ex) {
                packetErrors++;
                if (packetErrors > 10) {
                    break;
                }
                continue;
            }

            if (!this->isAuthenticated()) {
                switch (current->getType()) {
                    case HANDSHAKE:
                    case REQUEST:
                    case PING:
                    case LOGIN_START:
                    case ENCRYPTION_RESPONSE:
                    case LOGIN_PLUGIN_RESPONSE:
                        break;
                    default:
                        break;
                }
            }
            packetErrors = 0;
            handlePacket(current);
        }
        close();
    }

    void Connection::handlePacket(PacketInBase *packet) {
        if (getState() == HANDSHAKING) {
            if (packet->getType() == HANDSHAKE) {
                auto *handshake = (PacketInHandshake *) packet;
                state = handshake->getNextState();
            }
        } else if (getState() == STATUS) {
            if (packet->getType() == REQUEST) {

            } else if (packet->getType() == PING) {
                auto *packetInPing = (PacketInPing *) packet;
                sendPacket(new PacketOutPong(packetInPing->getValue()));
            }
        } else if (getState() == LOGIN) {
            if (packet->getType() == LOGIN_START) {
                auto *start = (PacketInLoginStart *) packet;
                std::string username = start->getName();
                server::UUID uuid = server::UUID(0, 0);
                state = PLAY;
                sendPacket(new PacketOutLoginSuccess(uuid, username));
                sendPacket(new PacketPlayOutDisconnect("Fuk off bitch"));
            } else if (packet->getType() == LOGIN_PLUGIN_RESPONSE) {

            }
        }
    }

    void Connection::close() {
        ::close(this->socketFd);
        std::printf("Closed connection  %d.\n", socketFd);
    }

    void *Connection::start(void *connectionPointer) {
        Connection theConnection = *static_cast<Connection *>(connectionPointer);
        theConnection.run();
        return nullptr;
    }

    bool Connection::handShake() {
        return false;
    }

    protocol::PacketInBase *Connection::readPacket() {
        uint8_t headerLength = 0;
        uint32_t length = Util::readVarInt(this->socketFd, &headerLength);
        uint8_t idLength = 0;
        uint32_t packetId = Util::readVarInt(this->socketFd, &idLength);

        length -= idLength;

        if (length > rxBufferSize) {
            setRxBufferSize(length);
        }

        int bytesRead = read(this->socketFd, rxBuffer, length);
        if (bytesRead != length) {
            throw Exception("Did not read the correct amount of bytes. ");
        }

        protocol::PacketInBase *packet = PacketParser::parse(this->state, packetId, rxBuffer, length);
        return packet;
    }

    bool Connection::isAuthenticated() {
        return this->authenticated;
    }

    network::State Connection::getState() {
        return this->state;
    }

    bool Connection::sendPacket(protocol::PacketOutBase *packet) {
        uint32_t size = 0;
        uint8_t *data = packetSerializer.serialize(packet, &size);
        send(socketFd, data, size, 0);
        return true;
    }

    void Connection::setRxBufferSize(uint32_t newSize) {
        rxBuffer = (uint8_t *) realloc(rxBuffer, sizeof(uint8_t) * newSize);
        rxBufferSize = newSize;
    }


}