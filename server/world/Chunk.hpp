//
// Created by jona on 2019-06-13.
//

#ifndef MCSERVER_CHUNK_HPP
#define MCSERVER_CHUNK_HPP

#include "Location.hpp"
#include "BlockLocation.hpp"
#include "ChunkSection.hpp"
#include "ChunkLocation.hpp"

namespace server {
    class Chunk {
    private:
        ChunkSection sections[16];
        bool loaded;
        ChunkLocation location;

    public:

        Chunk(uint32_t x, uint32_t z);

        Block *getBlock(uint32_t x, uint32_t y, uint32_t z);

        bool isLoaded();

        const ChunkLocation &getChunkLocation() const;

        ChunkSection *getSections();
    };
}


#endif //MCSERVER_CHUNK_HPP
