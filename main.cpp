#include <iostream>
#include "network/Service.hpp"
#include "server/Server.hpp"

int main() {

    server::Server Server;

    network::Service network(25565);
    network.start();
    return 0;
}
