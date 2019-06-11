//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_SERVICE_HPP
#define MCSERVER_SERVICE_HPP

#include <list>
#include "Connection.hpp"

namespace network {
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

#endif //MCSERVER_SERVICE_HPP
