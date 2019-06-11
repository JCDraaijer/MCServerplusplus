//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_CONNECTION_HPP
#define MCSERVER_CONNECTION_HPP

#include <string>
#include "State.hpp"
#include "../protocol/in/PacketInBase.hpp"
#include "../protocol/out/PacketOutBase.hpp"
#include "PacketParser.hpp"
#include "PacketSerializer.hpp"

namespace network {
    class Connection {
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

    private:
        int socketFd;

        uint32_t rxBufferSize;
        uint8_t *rxBuffer;

        bool authenticated = false;

        State state = HANDSHAKING;

        int packetRx = 0;
        int packetTx = 0;

        int packetErrors = 0;

        PacketSerializer packetSerializer;

        void run();

        void handlePacket(PacketInBase *packet);
    };

}

#endif //MCSERVER_CONNECTION_HPP
