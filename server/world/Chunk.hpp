//
// Created by jona on 2019-06-13.
//

#ifndef MCSERVER_CHUNK_HPP
#define MCSERVER_CHUNK_HPP

#include "Block.hpp"
#include "Location.hpp"
#include "BlockLocation.hpp"

namespace server {
    class Chunk {
    private:
        Block blocks[16][256][16];
        bool loaded;

    public:
        Block getBlockAt(Location location);
        
        Block getBlockAt(BlockLocation location);

        bool isLoaded();
    };
}


#endif //MCSERVER_CHUNK_HPP
