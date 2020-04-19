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

#include "BlockLocation.hpp"

namespace server {

    int32_t BlockLocation::getX() const {
        return x;
    }

    void BlockLocation::setX(int32_t newX) {
        BlockLocation::x = newX;
    }

    int32_t BlockLocation::getY() const {
        return y;
    }

    void BlockLocation::setY(int32_t newY) {
        BlockLocation::y = newY;
    }

    int32_t BlockLocation::getZ() const {
        return z;
    }

    void BlockLocation::setZ(int32_t newZ) {
        BlockLocation::z = newZ;
    }

    BlockLocation::BlockLocation(int32_t x, int32_t y, int32_t z) : x(x), y(y), z(z) {

    }

}