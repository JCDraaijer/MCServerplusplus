#include <iostream>
#include <signal.h>
#include "network/Service.hpp"
#include "server/Server.hpp"

void stopServices(int signal);

server::Server *theServer;
network::Service *theNetwork;


int main() {

    signal(15, &stopServices);
    signal(9, &stopServices);

    theServer = new server::Server();

    pthread_t threadId;
    pthread_create(&threadId, nullptr, server::Server::startServer, theServer);

    theNetwork = new network::Service(25565);
    theNetwork->start();
    return 0;
}


void stopServices(int signal) {
    std::printf("Stopping services...");
    theServer->stop();
    theNetwork->stop();
    exit(signal);
}
