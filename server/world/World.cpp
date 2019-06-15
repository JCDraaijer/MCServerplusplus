//
// Created by jona on 2019-06-13.
//

#include "World.hpp"
namespace server {

    void World::tickEntities() {

    }

    Block World::getBlockAt(Location location) {
        return Block(Material(), BlockLocation(0,0,0));
    }

    Block World::getBlockAt(BlockLocation location) {
        return Block(Material(), BlockLocation(0,0,0));
    }
}