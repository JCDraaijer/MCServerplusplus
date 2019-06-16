//
// Created by jona on 2019-06-16.
//

#include "ChunkLocation.hpp"

namespace server {

    const uint32_t &ChunkLocation::getX() const {
        return x;
    }

    const uint32_t &ChunkLocation::getZ() const {
        return z;
    }

    ChunkLocation::ChunkLocation(uint32_t x, uint32_t z) : x(x), z(z) {
    }
}