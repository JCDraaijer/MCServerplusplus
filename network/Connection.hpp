//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_CONNECTION_HPP
#define MCSERVER_CONNECTION_HPP

#include <string>
#include "State.hpp"
#include "../protocol/in/PacketInBase.hpp"
#include "../protocol/out/PacketOutBase.hpp"

namespace network {
    class Connection {
    private:
        int socketFd;

        uint32_t rxBufferSize;
        uint8_t *rxBuffer;

        bool authenticated;
        bool encrypted;

        uint8_t publicKeyLength;
        uint8_t *publicKey;

        State state;

        int packetRx;
        int packetTx;

        int packetErrors;

        protocol::PacketSerializer packetSerializer;

        void run();

        void handlePacket(protocol::PacketInBase *packet);

    public:

        explicit Connection(int, uint32_t);

        ~Connection();

        bool handShake();

        void close();

        protocol::PacketInBase *readPacket();

        bool sendPacket(protocol::PacketOutBase *packet);

        bool isAuthenticated();

        State getState();

        static void *start(void *);

        void setRxBufferSize(uint32_t newSize);
    };

}

#endif //MCSERVER_CONNECTION_HPP
