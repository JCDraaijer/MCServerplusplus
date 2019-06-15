//
// Created by jona on 2019-06-02.
//

#include <cmath>
#include "Location.hpp"

namespace server {

    double Location::getX() const {
        return x;
    }

    void Location::setX(double newX) {
        this->x = newX;
    }

    double Location::getY() const {
        return y;
    }

    void Location::setY(double newY) {
        this->y = newY;
    }

    double Location::getZ() const {
        return z;
    }

    void Location::setZ(double newZ) {
        this->z = newZ;
    }

    BlockLocation Location::toBlockLocation() {
        return {(int32_t) round(x), (int32_t) round(y), (int32_t) round(z)};
    }
}