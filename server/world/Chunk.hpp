/*
MCpp, a Minecraft Server implementation in C++.
Copyright (C) 2019, 2020 Johannes Draaijer

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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
