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

#ifndef MCSERVER_LOCATION_HPP
#define MCSERVER_LOCATION_HPP

#include "BlockLocation.hpp"

namespace server {
    class Location {
    private:
        double x;
        double y;
        double z;
    public:
        double getX() const;

        void setX(double newX);

        double getY() const;

        void setY(double newY);

        double getZ() const;

        void setZ(double newZ);

        BlockLocation toBlockLocation();
    };
}


#endif //MCSERVER_LOCATION_HPP
