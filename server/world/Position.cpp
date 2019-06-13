//
// Created by jona on 2019-06-02.
//

#include "Position.hpp"

namespace server {

    double Position::getX() const {
        return x;
    }

    void Position::setX(double newX) {
        this->x = newX;
    }

    double Position::getY() const {
        return y;
    }

    void Position::setY(double newY) {
        this->y = newY;
    }

    double Position::getZ() const {
        return z;
    }

    void Position::setZ(double newZ) {
        this->z = newZ;
    }
}