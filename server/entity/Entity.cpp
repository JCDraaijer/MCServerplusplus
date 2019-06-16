//
// Created by jona on 2019-06-13.
//

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