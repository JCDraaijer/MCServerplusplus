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

#include "Entity.hpp"

namespace server {

    Entity::Entity(const UUID& uuid, Location position, Vector3D velocity) : uuid(uuid), position(position),
                                                                      velocity(velocity) {

    }

    const Location &Entity::getPosition() const {
        return position;
    }

    void Entity::setPosition(const Location &newPosition) {
        this->position = newPosition;
    }

    Vector3D &Entity::getVelocity() {
        return velocity;
    }

    void Entity::setVelocity(const Vector3D &newVelocity) {
        this->velocity = newVelocity;
    }
}