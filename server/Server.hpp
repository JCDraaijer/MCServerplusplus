//
// Created by jona on 2019-06-13.
//

#ifndef MCSERVER_SERVER_HPP
#define MCSERVER_SERVER_HPP

#include "world/World.hpp"

namespace server {
    class Server {
    private:
        std::list<World> worlds;
        std::list<Entity> entities;
    public:
        void tick();
        void start();

        static void *startServer(void *server);
    };


}


#endif //MCSERVER_SERVER_HPP
