//
// Created by jona on 2019-06-02.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#include "Service.hpp"


namespace network {

    Service::Service(int port) {
        this->port = port;
        running = false;
        socketFd = -1;
    }

    void Service::start() {
        std::printf("Started networking service.\n");
        running = true;
        if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            std::printf("Error! Could not create socket.\n");
            return;
        }

        struct sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = htonl(INADDR_ANY);
        address.sin_port = htons(port);

        int one = 1;
        if (setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one)) < 0) {
            std::printf("Could not set socket options!\n");
            return;
        }

        std::printf("Set socket options.\n");

        if ((bind(socketFd, (sockaddr *) &address, sizeof(address))) < 0) {
            std::printf("Error! Could not bind. (%d)\n", errno);
            return;
        }

        if (listen(socketFd, 20) < 0) {
            std::printf("Could not listen.\n");
            return;
        }

        while (running) {

            struct sockaddr clientAdress{};
            socklen_t len = sizeof(clientAdress);
            int connectionFd = accept(socketFd, (sockaddr *) &clientAdress, &len);
            if (connectionFd < 0) {
                std::printf("Error! Could not accept Connection! %d", errno);
                close(connectionFd);
                continue;
            }
            std::printf("Accepted Connection %d.\n", connectionFd);
            auto *aConnection = new Connection(connectionFd, 1024);
            this->connections.push_back(*aConnection);
            pthread_t threadId;
            pthread_create(&threadId, nullptr, Connection::start, aConnection);
        }
        close(socketFd);

    }

    void Service::stop() {
        running = false;
        for (auto &connect : connections) {
            connect.close();
        }

    }

    void *Service::startService(void *service) {
        auto theService = (Service *) service;
        theService->start();
        return nullptr;
    }
}