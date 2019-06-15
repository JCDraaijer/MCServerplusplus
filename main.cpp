#include <iostream>
#include "network/Service.hpp"
#include "server/Server.hpp"

int main() {

    auto *theServer = new server::Server();

    pthread_t threadId;
    pthread_create(&threadId, nullptr, server::Server::startServer, theServer);

    network::Service network(25565);
    network.start();
    return 0;
}
