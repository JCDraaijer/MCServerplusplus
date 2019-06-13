//
// Created by jona on 2019-06-13.
//

#include "BlockPosition.hpp"

namespace server {

    int32_t BlockPosition::getX() const {
        return x;
    }

    void BlockPosition::setX(int32_t newX) {
        BlockPosition::x = newX;
    }

    int32_t BlockPosition::getY() const {
        return y;
    }

    void BlockPosition::setY(int32_t newY) {
        BlockPosition::y = newY;
    }

    int32_t BlockPosition::getZ() const {
        return z;
    }

    void BlockPosition::setZ(int32_t newZ) {
        BlockPosition::z = newZ;
    }
}