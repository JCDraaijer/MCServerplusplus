//
// Created by jona on 2019-06-02.
//

#include <unistd.h>
#include <netinet/in.h>

#include "Connection.hpp"

#include "../server/UUID.hpp"
#include "../protocol/exception/Exception.hpp"
#include "../protocol/exception/UnknownPacketException.hpp"

#include "../protocol/in/PacketInBase.hpp"
#include "../protocol/out/PacketOutBase.hpp"
#include "../protocol/out/PacketStatusOutPong.hpp"
#include "../protocol/in/PacketHandshakeIn.hpp"
#include "../protocol/in/PacketStatusInPing.hpp"
#include "../protocol/in/PacketInLoginStart.hpp"
#include "../protocol/out/PacketLoginOutLoginSuccess.hpp"
#include "../protocol/out/PacketLoginOutDisconnect.hpp"
#include "../protocol/out/PacketLoginOutEncryptionRequest.hpp"
#include "../protocol/PacketParser.hpp"
#include "../protocol/out/PacketPlayOutJoinGame.hpp"

namespace network {
    Connection::Connection(int socketFileDescriptor, uint32_t bufferSize) : socketFd(socketFileDescriptor),
                                                                            rxBufferSize(bufferSize),
                                                                            authenticated(false), encrypted(false),
                                                                            state(protocol::HANDSHAKING),
                                                                            packetTx(0), packetRx(0),
                                                                            publicKeyLength(0),
                                                                            publicKey(nullptr), packetErrors(0) {
        rxBuffer = (uint8_t *) malloc(sizeof(uint8_t) * bufferSize);
        packetSerializer = new protocol::PacketSerializer(bufferSize);
        packetParser = new protocol::PacketParser();
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
            } catch (protocol::UnknownPacketException &ex) {
                std::printf("%s\n", ex.what());
                packetErrors++;
                if (packetErrors > 10) {
                    break;
                }
                continue;
            }

            if (!this->isAuthenticated()) {
                switch (state) {
                    case protocol::PLAY:
                        close();
                    case protocol::UNDEFINED:
                        close();
                        return;
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
        if (getState() == protocol::HANDSHAKING) {
            if (packet->getType() == protocol::HANDSHAKE) {
                auto *handshake = (protocol::PacketHandshakeIn *) packet;
                state = handshake->getNextState();
            }
        } else if (getState() == protocol::STATUS) {
            if (packet->getType() == protocol::STATUS_REQUEST) {

            } else if (packet->getType() == protocol::PING) {
                auto *packetInPing = (protocol::PacketStatusInPing *) packet;
                sendPacket(new protocol::PacketStatusOutPong(packetInPing->getValue()));
                free(packetInPing);
            }
        } else if (getState() == protocol::LOGIN) {
            if (packet->getType() == protocol::LOGIN_START) {
                auto *start = (protocol::PacketInLoginStart *) packet;
                std::string username = start->getName();
                server::UUID uuid = server::UUID(0, 0);
                state = protocol::PLAY;
                authenticated = true;
                protocol::PacketOutBase *toSend = new protocol::PacketLoginOutLoginSuccess(uuid, username);
                sendPacket(toSend);
                toSend = new protocol::PacketPlayOutJoinGame(1323, 0, 0, 1, 255, "default", false);
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
        uint32_t length = packetParser->readVarInt(this->socketFd, &headerLength);
        uint8_t idLength = 0;
        uint32_t packetId = packetParser->readVarInt(this->socketFd, &idLength);

        length -= idLength;

        if (length > rxBufferSize) {
            setRxBufferSize(length);
        }

        int bytesRead = read(this->socketFd, rxBuffer, length);
        if (bytesRead != length) {
            throw protocol::Exception("Did not read the correct amount of bytes. ");
        }

        protocol::PacketInBase *packet = packetParser->parse(this->state, packetId, rxBuffer, length);
        std::printf("%s\n", packet->toString().c_str());
        return packet;
    }

    bool Connection::isAuthenticated() {
        return this->authenticated;
    }

    protocol::ConnectionState Connection::getState() {
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