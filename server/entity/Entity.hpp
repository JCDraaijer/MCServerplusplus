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
#ifndef MCSERVER_ENTITY_HPP
#define MCSERVER_ENTITY_HPP

#include "../world/Location.hpp"
#include "../Vector3D.hpp"
#include "../UUID.hpp"

namespace server {
    class Entity {
    private:
        UUID uuid;
        Location position;
        Vector3D velocity;
    public:
        Entity(const UUID& uuid, Location position, Vector3D velocity);

        const Location &getPosition() const;

        void setPosition(const Location &newPosition);

        Vector3D &getVelocity();

        void setVelocity(const Vector3D &newVelocity);

        virtual void tick() = 0;

    };
}


#endif //MCSERVER_ENTITY_HPP
