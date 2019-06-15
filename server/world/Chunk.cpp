//
// Created by jona on 2019-06-13.
//

#include "Chunk.hpp"

namespace server {
    Block Chunk::getBlockAt(server::Location location) {
        return getBlockAt(location.toBlockLocation());
    }

    Block Chunk::getBlockAt(server::BlockLocation location) {
        return blocks[location.getX()][location.getY()][location.getZ()];
    }

    bool Chunk::isLoaded(){
        return this->loaded;
    }

}
