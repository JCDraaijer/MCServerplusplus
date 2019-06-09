//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_CONNECTION_H
#define MCSERVER_CONNECTION_H

#include <string>
#include "packet/in/InBase.h"
#include "packet/in/Handshake.h"
#include "State.h"
#include "packet/out/OutBase.h"


namespace networking {
    class Connection {
    public:

        explicit Connection(int);

        bool handShake();

        void close();

        packet::in::InBase *readPacket();

        bool sendPacket(packet::out::OutBase *packet);

        bool isAuthenticated();

        State getState();

        static void *start(void *);

    private:
        int socketFd;
        unsigned char buffer[1024] = {};
        bool authenticated = false;
        State state = HANDSHAKING;
        int packetsRx = 0;
        int packetsTx = 0;
    };

}

#endif //MCSERVER_CONNECTION_H
