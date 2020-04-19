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
#ifndef MCSERVER_BLOCKLOCATION_HPP
#define MCSERVER_BLOCKLOCATION_HPP

#include <cstdint>

namespace server {
    class BlockLocation {
    private:
        int32_t x;
        int32_t y;
        int32_t z;
    public:

        BlockLocation(int32_t x, int32_t y, int32_t z);

        int32_t getX() const;

        void setX(int32_t newX);

        int32_t getY() const;

        void setY(int32_t newY);

        int32_t getZ() const;

        void setZ(int32_t newZ);

    };
}


#endif //MCSERVER_BLOCKLOCATION_HPP
