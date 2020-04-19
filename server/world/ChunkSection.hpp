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

#ifndef MCSERVER_CHUNKSECTION_HPP
#define MCSERVER_CHUNKSECTION_HPP

#include "Block.hpp"

namespace server {
    class ChunkSection {
    public:
        Block blocks[16][16][16];

    public:

        explicit ChunkSection();

        bool isEmtpy();

        Block *getBlock(uint32_t x, uint32_t y, uint32_t z);
    };
}


#endif //MCSERVER_CHUNKSECTION_HPP
