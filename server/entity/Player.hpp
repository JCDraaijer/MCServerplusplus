//
// Created by jona on 2019-06-16.
//

#ifndef MCSERVER_PLAYER_HPP
#define MCSERVER_PLAYER_HPP

#include "Entity.hpp"

namespace server {
    class Player : public Entity {
    public:
        void tick() override;
    };
}


#endif //MCSERVER_PLAYER_HPP
