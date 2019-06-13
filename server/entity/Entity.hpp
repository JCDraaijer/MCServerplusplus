//
// Created by jona on 2019-06-13.
//

#ifndef MCSERVER_ENTITY_HPP
#define MCSERVER_ENTITY_HPP

#include "../world/Position.hpp"
#include "../Vector3D.hpp"
#include "../UUID.hpp"

namespace server {
    class Entity {
    private:
        UUID uuid;
        Position position;
        Vector3D velocity;
    public:
        Entity(UUID uuid, Position position, Vector3D velocity);
    };
}


#endif //MCSERVER_ENTITY_HPP
