//
// Created by jona on 2019-06-13.
//

#include "Vector3D.hpp"

namespace server {
    Vector3D::Vector3D(float xVel, float yVel, float zVel) : xVel(xVel), yVel(yVel), zVel(zVel) {

    }

    Vector3D Vector3D::add(Vector3D other) {
        xVel += other.xVel;
        yVel += other.yVel;
        zVel += other.zVel;
        return *this;
    }

    Vector3D Vector3D::add(float xAdd, float yAdd, float zAdd) {
        xVel += xAdd;
        yVel += yAdd;
        zVel += zAdd;
        return *this;
    }

    Vector3D Vector3D::subtract(Vector3D other) {
        return add(-other.xVel, -other.yVel, -other.zVel);
    }

    Vector3D Vector3D::subtract(float xSub, float ySub, float zSub) {
        return add(-xSub, -ySub, -zSub);
    }

    Vector3D Vector3D::multiply(float mult) {
        xVel *= mult;
        yVel *= mult;
        zVel *= mult;
        return *this;
    }
}
