//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_CONNECTION_HPP
#define MCSERVER_CONNECTION_HPP

#include <string>
#include "State.hpp"
#include "packet/in/InBase.hpp"
#include "packet/in/Reader.hpp"
#include "packet/out/OutBase.hpp"
#include "packet/out/Builder.hpp"

namespace networking {
    class Connection {
    public:

        explicit Connection(int, int);

        ~Connection();

        bool handShake();

        void close();

        packet::in::InBase *readPacket();

        bool sendPacket(packet::out::OutBase *packet);

        bool isAuthenticated();

        State getState();

        static void *start(void *);

    private:
        int socketFd;
        const int bufferSize;
        unsigned char *buffer;
        bool authenticated = false;
        State state = HANDSHAKING;
        packet::in::Reader inPacketReader;
        packet::out::
    };

}

#endif //MCSERVER_CONNECTION_HPP
