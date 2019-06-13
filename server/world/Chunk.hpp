//
// Created by jona on 2019-06-13.
//

#ifndef MCSERVER_CHUNK_HPP
#define MCSERVER_CHUNK_HPP

#include "../Block.hpp"

namespace server {
    class Chunk {
        Block blocks[16][256][16];
    };
}


#endif //MCSERVER_CHUNK_HPP
