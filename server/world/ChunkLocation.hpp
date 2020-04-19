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

#ifndef MCSERVER_CHUNKLOCATION_HPP
#define MCSERVER_CHUNKLOCATION_HPP

#include <cstdint>

namespace server {
    class ChunkLocation {
    private:
        uint32_t x;
        uint32_t z;
    public:
        ChunkLocation(uint32_t x, uint32_t z);

        const uint32_t &getX() const;
        const uint32_t &getZ() const;
    };
}


#endif //MCSERVER_CHUNKLOCATION_HPP
