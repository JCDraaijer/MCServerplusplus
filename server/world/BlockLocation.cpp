//
// Created by jona on 2019-06-13.
//

#include "BlockLocation.hpp"

namespace server {

    int32_t BlockLocation::getX() const {
        return x;
    }

    void BlockLocation::setX(int32_t newX) {
        BlockLocation::x = newX;
    }

    int32_t BlockLocation::getY() const {
        return y;
    }

    void BlockLocation::setY(int32_t newY) {
        BlockLocation::y = newY;
    }

    int32_t BlockLocation::getZ() const {
        return z;
    }

    void BlockLocation::setZ(int32_t newZ) {
        BlockLocation::z = newZ;
    }

    BlockLocation::BlockLocation(int32_t x, int32_t y, int32_t z) : x(x), y(y), z(z) {

    }

}