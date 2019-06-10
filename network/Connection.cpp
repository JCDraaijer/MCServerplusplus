//
// Created by jona on 2019-06-02.
//

#include <unistd.h>
#include <netinet/in.h>

#include "Connection.hpp"
#include "Util.hpp"
#include "packet/in/Request.hpp"
#include "packet/out/Response.hpp"

namespace networking {
    Connection::Connection(int socketFileDescriptor, int bufferSize) : socketFd(socketFileDescriptor),
                                                                       bufferSize(bufferSize) {
        this->buffer = (unsigned char *) malloc(sizeof(unsigned char) * bufferSize);
    }

    Connection::~Connection() {
        free(buffer);
    }

    void Connection::close() {
        ::close(this->socketFd);
        std::printf("Closed connection  %d.\n", socketFd);
    }

    void *Connection::start(void *connectionPointer) {
        Connection theConnection = *static_cast<Connection *>(connectionPointer);
        if (!theConnection.handShake()) {
            theConnection.close();
            std::printf("Handshake failed. Closed the connection.\n");
            pthread_exit(nullptr);
        }
        return nullptr;
    }

    bool Connection::handShake() {
        packet::in::InBase *toPrint = readPacket();
        if (toPrint != nullptr) {
            std::printf("%s\n", toPrint->toString().c_str());
        }
        toPrint = readPacket();
        if (toPrint != nullptr) {
            std::printf("%s\n", toPrint->toString().c_str());
        }
        delete toPrint;
        return false;
    }

    packet::in::InBase *Connection::readPacket() {
        int headerLength = 0;
        int packetIdLength = 0;
        int length = Util::readVarInt(this->socketFd, &headerLength);
        int packetId = Util::readVarInt(this->socketFd, &packetIdLength);
        length = length - headerLength;

        unsigned char *bufferToUse;

        if (length <= 1024) {
            bufferToUse = this->buffer;
        } else {
            bufferToUse = (unsigned char *) malloc(sizeof(unsigned char) * length);
        }

        int readData = read(this->socketFd, buffer, length);

        if (readData == -1 || readData < (length - headerLength)) {
            std::printf("Error while reading a packet. (Code: %d, Expected Length: %d, Actual length: %d)\n", errno,
                        length, readData);
            return nullptr;
        }

        packet::in::InBase *toReturn = nullptr;

        if (packetId == 0 && this->getState() == HANDSHAKING) {
            packet::in::Handshake *packetHandshakeRequest;
            packetHandshakeRequest = new packet::in::Handshake();
            packetHandshakeRequest->parse(bufferToUse, length);
            if (packetHandshakeRequest->getNextState() != UNDEFINED) {
                this->state = packetHandshakeRequest->getNextState();
            } else {
                std::printf("Received invalid Handshake request packet!\n");
                return nullptr;
            }
            toReturn = packetHandshakeRequest;
        } else if (packetId == 0 && this->getState() == STATUS) {
            packet::in::Request *requestPacket;
            requestPacket = new packet::in::Request();
            toReturn = requestPacket;
        }

        if (length > 1024) {
            free(bufferToUse);
        }
        packetsRx++;
        return toReturn;
    }

    bool Connection::isAuthenticated() {
        return this->authenticated;
    }

    networking::State Connection::getState() {
        return this->state;
    }

    bool Connection::sendPacket(packet::out::OutBase *packet) {
        return true;
    }

}