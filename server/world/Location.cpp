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


#include <cmath>
#include "Location.hpp"

namespace server {

    double Location::getX() const {
        return x;
    }

    void Location::setX(double newX) {
        this->x = newX;
    }

    double Location::getY() const {
        return y;
    }

    void Location::setY(double newY) {
        this->y = newY;
    }

    double Location::getZ() const {
        return z;
    }

    void Location::setZ(double newZ) {
        this->z = newZ;
    }

    BlockLocation Location::toBlockLocation() {
        return {(int32_t) round(x), (int32_t) round(y), (int32_t) round(z)};
    }
}