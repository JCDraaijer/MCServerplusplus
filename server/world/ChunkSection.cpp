//
// Created by jona on 2019-06-16.
//

#include "ChunkSection.hpp"

namespace server {
    Block *ChunkSection::getBlock(uint32_t x, uint32_t y, uint32_t z) {
        return &blocks[x][y][z];
    }

    bool ChunkSection::isEmtpy() {
        for (auto & x : blocks){
            for (auto & y : x){
                for (auto & block : y){
                    if (block.getMaterial() != AIR){
                        return false;
                    }
                }
            }
        }
        return true;
    }
}