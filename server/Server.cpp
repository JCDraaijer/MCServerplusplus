//
// Created by jona on 2019-06-13.
//

#include "Server.hpp"

namespace server {

    void Server::tick() {
        for (World world: worlds) {
            world.tickEntities();
        }
    }

    void Server::start() {
        std::printf("Started server.\n");
    }

    void *Server::startServer(void *server) {
        auto actualServer = (Server *) server;
        actualServer->start();
        return nullptr;
    }

    void Server::stop() {

    }
}