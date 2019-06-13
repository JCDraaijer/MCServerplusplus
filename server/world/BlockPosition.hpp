//
// Created by jona on 2019-06-13.
//

#ifndef MCSERVER_BLOCKPOSITION_HPP
#define MCSERVER_BLOCKPOSITION_HPP

#include <cstdint>

namespace server {
    class BlockPosition {
    private:
    public:
        int32_t getX() const;

        void setX(int32_t newX);

        int32_t getY() const;

        void setY(int32_t newY);

        int32_t getZ() const;

        void setZ(int32_t newZ);

    private:
        int32_t x;
        int32_t y;
        int32_t z;

    };
}


#endif //MCSERVER_BLOCKPOSITION_HPP
