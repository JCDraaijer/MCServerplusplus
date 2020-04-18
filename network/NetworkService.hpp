//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_NETWORKSERVICE_HPP
#define MCSERVER_NETWORKSERVICE_HPP

#include <list>
#include "Connection.hpp"

namespace network {
    class NetworkService {
    private:
        bool running;
        int socketFd;
        std::list<Connection> connections;
        int port;
        server::Server *server;
    public:
        explicit NetworkService(server::Server *server, int port);

        void start();

        void stop();

        static void *startService(void *);

    };

}

#endif //MCSERVER_NETWORKSERVICE_HPP
