/*
MCpp, a Minecraft Server implementation in C++.
Copyright (C) 2019, 2020 Johannes Draaijer

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <csignal>
#include "network/NetworkService.hpp"
#include "server/Server.hpp"
#include "nbt/NBTTagCompound.hpp"
#include "nbt/NBTTagInt.hpp"

void stopServices(int signal);

bool running = true;
server::Server *theServer;
network::NetworkService *theNetwork;


int main() {

/*    FILE *theFile = std::fopen("/home/jona/bigtest.nbt", "r");

    nbt::NBTTagCompound compound = nbt::NBTTagCompound();

    uint8_t firstTag;

    std::fread(&firstTag, 1, 1, theFile);

    compound.parsePayload(theFile, true);*/

    theServer = new server::Server();

    pthread_t serverThreadId;
    pthread_create(&serverThreadId, nullptr, server::Server::startServer, theServer);

    pthread_t networkThreadId;

    theNetwork = new network::NetworkService(theServer, 25565);
    pthread_create(&networkThreadId, nullptr, network::NetworkService::startService, theNetwork);

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
