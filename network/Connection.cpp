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
#include "../protocol/out/PacketOutDisconnect.hpp"

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
                std::printf("%s\n", ex.what());
                packetErrors++;
                if (packetErrors > 10) {
                    break;
                }
                continue;
            }
            packetErrors = 0;
            std::printf("%s\n", current->toString().c_str());
            handlePacket(current);
        }
        close();
    }

    void Connection::handlePacket(PacketInBase *packet) {
        if (getState() == HANDSHAKING) {
            if (packet->getType() == HANDSHAKE) {
                auto *handshake = (PacketInHandshake *) packet;
                state = handshake->getNextState();
                if (state == LOGIN) {
                    try {
                        handlePacket(readPacket());
                    } catch (Exception &ex) {
                        std::printf("Auth failed. %s\n", ex.what());
                        close();
                    }
                }
            }
        } else if (getState() == STATUS) {
            if (packet->getType() == REQUEST) {
                //TODO send response packet
            } else if (packet->getType() == PING) {
                auto *packetInPing = (PacketInPing *) packet;
                sendPacket(new PacketOutPong(packetInPing->getValue()));
            }
        } else if (getState() == LOGIN) {
            std::printf("%s\n", packet->toString().c_str());
            sendPacket(new PacketOutDisconnect("You a bitch"));
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
        std::printf("Reallocated the buffer.\n");
    }


}