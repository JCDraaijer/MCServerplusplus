//
// Created by jona on 2019-06-13.
//

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
