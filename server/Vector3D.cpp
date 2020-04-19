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


#include "Vector3D.hpp"

namespace server {
    Vector3D::Vector3D(float xVel, float yVel, float zVel) : xVel(xVel), yVel(yVel), zVel(zVel) {

    }

    Vector3D Vector3D::add(Vector3D other) {
        xVel += other.xVel;
        yVel += other.yVel;
        zVel += other.zVel;
        return *this;
    }

    Vector3D Vector3D::add(float xAdd, float yAdd, float zAdd) {
        xVel += xAdd;
        yVel += yAdd;
        zVel += zAdd;
        return *this;
    }

    Vector3D Vector3D::subtract(Vector3D other) {
        return add(-other.xVel, -other.yVel, -other.zVel);
    }

    Vector3D Vector3D::subtract(float xSub, float ySub, float zSub) {
        return add(-xSub, -ySub, -zSub);
    }

    Vector3D Vector3D::multiply(float mult) {
        xVel *= mult;
        yVel *= mult;
        zVel *= mult;
        return *this;
    }
}
