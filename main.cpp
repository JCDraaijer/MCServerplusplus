#include <iostream>
#include "network/Service.hpp"
#include "network/util/Util.hpp"

int main() {

    network::Service network(25565);
    network.start();
    return 0;
}
