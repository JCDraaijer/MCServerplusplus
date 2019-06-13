//
// Created by jona on 2019-06-13.
//

#include "Entity.hpp"

namespace server {

    Entity::Entity(UUID uuid, Position position, Vector3D velocity) : uuid(uuid), position(position),
                                                                      velocity(velocity) {

    }
}