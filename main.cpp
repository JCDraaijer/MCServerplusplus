#include <iostream>
#include <signal.h>
#include "network/Service.hpp"
#include "server/Server.hpp"
#include "nbt/NBTTagCompound.hpp"
#include "nbt/NBTTagInt.hpp"

void stopServices(int signal);

bool running = true;
server::Server *theServer;
network::Service *theNetwork;


int main() {

    FILE *theFile = std::fopen("/home/jona/bigtest.nbt", "r");

    nbt::NBTTagCompound compound = nbt::NBTTagCompound();

    uint8_t firstTag;

    std::fread(&firstTag, 1, 1, theFile);

    compound.parsePayload(theFile, true);

    theServer = new server::Server();

    pthread_t serverThreadId;
    pthread_create(&serverThreadId, nullptr, server::Server::startServer, theServer);

    pthread_t networkThreadId;

    theNetwork = new network::Service(25565);
    pthread_create(&networkThreadId, nullptr, network::Service::startService, theNetwork);

    signal(15, &stopServices);
    signal(1, &stopServices);
    signal(2, &stopServices);
    signal(3, &stopServices);
    signal(4, &stopServices);
    signal(6, &stopServices);


    std::string inputData;
    while (running) {
        std::cin >> inputData;
        if (inputData == "stop") {
            stopServices(0);
            break;
        }
    }

    return 0;
}


void stopServices(int signal) {
    std::printf("Stopping services...\n");
    running = false;
    theServer->stop();
    theNetwork->stop();
    exit(1);
}
