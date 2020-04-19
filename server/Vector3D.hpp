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


#ifndef MCSERVER_VECTOR3D_HPP
#define MCSERVER_VECTOR3D_HPP


namespace server {
    class Vector3D {
    private:
        float xVel;
        float yVel;
        float zVel;
    public:
        Vector3D(float xVel, float yVel, float zVel);

        Vector3D add(Vector3D other);

        Vector3D add(float xAdd, float yAdd, float zAdd);

        Vector3D subtract(Vector3D other);

        Vector3D subtract(float xSub, float ySub, float zSub);

        Vector3D multiply(float mult);
    };

}

#endif //MCSERVER_VECTOR3D_HPP
