//
// Created by jona on 2019-06-13.
//

#include "Chunk.hpp"

namespace server {
    bool Chunk::isLoaded() {
        return this->loaded;
    }

    Block *Chunk::getBlock(uint32_t x, uint32_t y, uint32_t z) {
        //uint32_t sectionNum = y / 16;
        //return sections[sectionNum].getBlock(x, y - ((y / 16) * 16), z);
        if (y <= 64) {
            return new Block(DIRT, BlockLocation(x, y, z));
        } else {
            return new Block(AIR, BlockLocation(x, y, z));
        }
    }

    const ChunkLocation &Chunk::getChunkLocation() const {
        return location;
    }

    ChunkSection *Chunk::getSections() {
        return &sections[0];
    }

    Chunk::Chunk(uint32_t x, uint32_t z) : location(ChunkLocation(x, z)) {
        for (auto & section : sections) {
            section = ChunkSection();
        }
        loaded = true;
    }

}
