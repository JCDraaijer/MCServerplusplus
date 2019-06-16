//
// Created by jona on 2019-06-16.
//

#ifndef MCSERVER_CHUNKSECTION_HPP
#define MCSERVER_CHUNKSECTION_HPP

#include "Block.hpp"

namespace server {
    class ChunkSection {
    private:
        Block blocks[16][16][16];

    public:

        bool isEmtpy();

        Block *getBlock(uint32_t x, uint32_t y, uint32_t z);
    };
}


#endif //MCSERVER_CHUNKSECTION_HPP
