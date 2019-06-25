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
#include "../protocol/out/PacketOutStatusPong.hpp"
#include "../protocol/in/PacketInHandshake.hpp"
#include "../protocol/in/PacketInStatusPing.hpp"
#include "../protocol/in/PacketInLoginStart.hpp"
#include "../protocol/out/PacketOutLoginLoginSuccess.hpp"
#include "../protocol/out/PacketOutLoginDisconnect.hpp"
#include "../protocol/out/PacketOutLoginEncryptionRequest.hpp"
#include "../protocol/PacketParser.hpp"
#include "../protocol/out/PacketOutPlayJoinGame.hpp"
#include "../protocol/out/PacketOutPlayChunkData.hpp"
#include "../protocol/out/PacketOutPlayPlayerPositionLook.hpp"
#include "../protocol/out/PacketOutHandshakeLegacyPingResponse.hpp"

namespace network {
    Connection::Connection(int socketFileDescriptor, uint32_t bufferSize) : socketFd(socketFileDescriptor),
                                                                            rxBufferSize(bufferSize),
                                                                            authenticated(false), encrypted(false),
                                                                            state(protocol::HANDSHAKING),
                                                                            packetTx(0), packetRx(0),
                                                                            publicKeyLength(0),
                                                                            publicKey(nullptr), packetErrors(0),
                                                                            teleportId(0) {
        rxBuffer = (uint8_t *) malloc(sizeof(uint8_t) * bufferSize);
        packetSerializer = new protocol::PacketSerializer(bufferSize);
        packetParser = new protocol::PacketParser();
    }

    Connection::~Connection() {
        free(rxBuffer);
        delete packetSerializer;
        delete packetParser;
    }

    void Connection::run() {
        while (true) {
            protocol::PacketInBase *current;
            try {
                current = readPacket();
                std::printf("Read a packet with ID: %d\n", current->getId());
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
            delete current;
        }
        close();
    }

    void Connection::handlePacket(protocol::PacketInBase *packet) {
        if (getState() == protocol::HANDSHAKING) {
            if (packet->getType() == protocol::HANDSHAKE) {
                auto *handshake = (protocol::PacketInHandshake *) packet;
                state = handshake->getNextState();
            } else if (packet->getType() == protocol::LEGACY_PING) {
                protocol::PacketOutHandshakeLegacyPingResponse response = protocol::PacketOutHandshakeLegacyPingResponse();
                sendPacket(&response);
            }
        } else if (getState() == protocol::STATUS) {
            if (packet->getType() == protocol::STATUS_REQUEST) {

            } else if (packet->getType() == protocol::PING) {
                auto *packetInPing = (protocol::PacketInStatusPing *) packet;
                sendPacket(new protocol::PacketOutStatusPong(packetInPing->getValue()));
            }
        } else if (getState() == protocol::LOGIN) {
            if (packet->getType() == protocol::LOGIN_START) {
                auto *start = (protocol::PacketInLoginStart *) packet;
                std::string username = start->getName();
                server::UUID uuid = server::UUID::randomUuid();
                state = protocol::PLAY;
                authenticated = true;

                protocol::PacketOutLoginLoginSuccess sendLoginSuccess = protocol::PacketOutLoginLoginSuccess(uuid,
                                                                                                             username);
                std::printf("%s logged in with UUID %s\n", username.c_str(), uuid.toString().c_str());

                sendPacket(&sendLoginSuccess);

                protocol::PacketOutPlayJoinGame joinGame = protocol::PacketOutPlayJoinGame(1323, 0, 0, 1, 255,
                                                                                           "default", false);
                sendPacket(&joinGame);
            } else if (packet->getType() == protocol::LOGIN_PLUGIN_RESPONSE) {

            }
        } else if (getState() == protocol::PLAY) {
            if (packet->getType() != protocol::TELEPORT_CONFIRM) {
                protocol::PacketOutPlayPlayerPositionLook look = protocol::PacketOutPlayPlayerPositionLook(0, 64, 0, 31,
                                                                                                           0,
                                                                                                           0,
                                                                                                           teleportId++);
                sendPacket(&look);
            } else {
                auto *chunk = new server::Chunk(0, 0);
                protocol::PacketOutPlayChunkData data = protocol::PacketOutPlayChunkData(chunk, false);
                sendPacket(&data);
                delete chunk;
            }
        }
    }

    void Connection::close() {
        ::close(this->socketFd);
        std::printf("Closed connection  %d.\n", socketFd);
        pthread_exit(nullptr);
    }

    void *Connection::start(void *connectionPointer) {
        Connection theConnection = *(Connection *) connectionPointer;
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
        std::printf("Sent packet with id 0x%02X\n", packet->getId());
        send(socketFd, data, size, 0);
        return true;
    }

    void Connection::setRxBufferSize(uint32_t newSize) {
        rxBuffer = (uint8_t *) realloc(rxBuffer, sizeof(uint8_t) * newSize);
        rxBufferSize = newSize;
    }


}