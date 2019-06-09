//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_SERVICE_H
#define MCSERVER_SERVICE_H

#include <list>
#include "Connection.h"

namespace networking {
    class Service {
    private:
        bool running;
        int socketFd;
        std::list<Connection> connections;
        int port;
    public:
        explicit Service(int);

        void start();

        void stop();
    };

}

#endif //MCSERVER_SERVICE_H
