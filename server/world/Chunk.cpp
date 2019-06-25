//
// Created by jona on 2019-06-13.
//

#include <cstdio>
#include "Chunk.hpp"

namespace server {
    bool Chunk::isLoaded() {
        return this->loaded;
    }

    Block *Chunk::getBlock(uint32_t x, uint32_t y, uint32_t z) {
        uint32_t sectionNum = y / 16;
        return sections[sectionNum].getBlock(x, y - ((y / 16) * 16), z);
    }

    const ChunkLocation &Chunk::getChunkLocation() const {
        return location;
    }

    ChunkSection *Chunk::getSections() {
        return &sections[0];
    }

    Chunk::Chunk(uint32_t x, uint32_t z) : location(ChunkLocation(x, z)) {
        for (int i = 0; i < 4; i++) {
            ChunkSection *currentSection = &sections[i];
            for (int currentX = 0; currentX < 16; currentX++) {
                for (int y = 0; y < 8; y++) {
                    for (int currentZ = 0; currentZ < 16; currentZ++) {
                        auto currentBlock = currentSection->getBlock(currentX, y, currentZ);
                        currentBlock->setMaterial(DIRT);
                    }
                }
            }
        }
        int airCount = 0;
        int dirtCount = 0;
        for (auto &section : sections) {
            for (auto &cx : sections->blocks) {
                for (auto &y : cx) {
                    for (auto &block : y) {
                        if (block.getMaterial() == DIRT) {
                            dirtCount++;
                        } else if (block.getMaterial() == AIR) {
                            airCount++;
                        }
                    }
                }
            }
        }
        std::printf("Air: %d, Dirt: %d\n", airCount, dirtCount);
        loaded = true;
    }

}
