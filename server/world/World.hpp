//
// Created by jona on 2019-06-13.
//

#ifndef MCSERVER_WORLD_HPP
#define MCSERVER_WORLD_HPP

#include <list>
#include "Chunk.hpp"
#include "../entity/Entity.hpp"
#include "BlockLocation.hpp"

namespace server {
    class World {
    private:
        std::list<Entity> entities;
        std::list<Chunk> chunks;

        float gravity;

    public:
        void tickEntities();

        Block getBlockAt(Location location);

        Block getBlockAt(BlockLocation location);
    };
}


#endif //MCSERVER_WORLD_HPP
