//
// Created by jona on 2019-06-13.
//

#ifndef MCSERVER_VECTOR3D_HPP
#define MCSERVER_VECTOR3D_HPP


namespace server {
    class Vector3D {
    private:
        float xVel;
        float yVel;
        float zVel;
    public:
        Vector3D(float xVel, float yVel, float zVel);

        Vector3D add(Vector3D other);

        Vector3D add(float xAdd, float yAdd, float zAdd);

        Vector3D subtract(Vector3D other);

        Vector3D subtract(float xSub, float ySub, float zSub);

        Vector3D multiply(float mult);
    };

}

#endif //MCSERVER_VECTOR3D_HPP
