//
// Created by jona on 2019-06-02.
//

#include <unistd.h>
#include <netinet/in.h>

#include "Connection.hpp"
#include "../protocol/in/PacketInBase.hpp"
#include "../protocol/out/PacketOutBase.hpp"
#include "../protocol/util/Exception.hpp"
#include "../protocol/out/PacketOutPong.hpp"
#include "../protocol/in/PacketInHandshake.hpp"
#include "../protocol/in/PacketInPing.hpp"
#include "../protocol/in/PacketInLoginStart.hpp"
#include "../server/UUID.hpp"
#include "../protocol/out/PacketOutLoginSuccess.hpp"
#include "../protocol/out/PacketLoginOutDisconnect.hpp"
#include "../protocol/out/PacketOutEncryptionRequest.hpp"
#include "../protocol/util/Util.hpp"
#include "PacketParser.hpp"

namespace network {
    Connection::Connection(int socketFileDescriptor, uint32_t bufferSize) : socketFd(socketFileDescriptor),
                                                                            rxBufferSize(bufferSize),
                                                                            authenticated(false), encrypted(false),
                                                                            state(HANDSHAKING),
                                                                            packetTx(0), packetRx(0),
                                                                            publicKeyLength(0),
                                                                            publicKey(nullptr), packetErrors(0) {
        rxBuffer = (uint8_t *) malloc(sizeof(uint8_t) * bufferSize);
        packetSerializer = new PacketSerializer(bufferSize);
    }

    Connection::~Connection() {
        free(rxBuffer);
        free(packetSerializer);
    }

    void Connection::run() {
        while (true) {
            protocol::PacketInBase *current;
            try {
                current = readPacket();
            } catch (protocol::Exception &ex) {
                packetErrors++;
                if (packetErrors > 10) {
                    break;
                }
                continue;
            }

            if (!this->isAuthenticated()) {
                switch (current->getType()) {
                    case protocol::HANDSHAKE:
                    case protocol::REQUEST:
                    case protocol::PING:
                    case protocol::LOGIN_START:
                    case protocol::ENCRYPTION_RESPONSE:
                    case protocol::LOGIN_PLUGIN_RESPONSE:
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

    void Connection::handlePacket(protocol::PacketInBase *packet) {
        std::printf("%s\n", packet->toString().c_str());
        if (getState() == HANDSHAKING) {
            if (packet->getType() == protocol::HANDSHAKE) {
                auto *handshake = (protocol::PacketInHandshake *) packet;
                state = handshake->getNextState();
            }
        } else if (getState() == STATUS) {
            if (packet->getType() == protocol::REQUEST) {

            } else if (packet->getType() == protocol::PING) {
                auto *packetInPing = (protocol::PacketInPing *) packet;
                sendPacket(new protocol::PacketOutPong(packetInPing->getValue()));
            }
        } else if (getState() == LOGIN) {
            if (packet->getType() == protocol::LOGIN_START) {
                auto *start = (protocol::PacketInLoginStart *) packet;
                std::string username = start->getName();
                server::UUID uuid = server::UUID(0, 0);
                state = PLAY;
                PacketOutBase *toSend = new PacketOutLoginSuccess(uuid, username);
                sendPacket(toSend);
                free(toSend);
            } else if (packet->getType() == protocol::LOGIN_PLUGIN_RESPONSE) {

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
        uint32_t length = protocol::Util::readVarInt(this->socketFd, &headerLength);
        uint8_t idLength = 0;
        uint32_t packetId = protocol::Util::readVarInt(this->socketFd, &idLength);

        length -= idLength;

        if (length > rxBufferSize) {
            setRxBufferSize(length);
        }

        int bytesRead = read(this->socketFd, rxBuffer, length);
        if (bytesRead != length) {
            throw protocol::Exception("Did not read the correct amount of bytes. ");
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
        uint8_t *data = packetSerializer->serializePacket(packet, &size);
        send(socketFd, data, size, 0);
        return true;
    }

    void Connection::setRxBufferSize(uint32_t newSize) {
        rxBuffer = (uint8_t *) realloc(rxBuffer, sizeof(uint8_t) * newSize);
        rxBufferSize = newSize;
    }


}