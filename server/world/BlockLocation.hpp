//
// Created by jona on 2019-06-13.
//

#ifndef MCSERVER_BLOCKLOCATION_HPP
#define MCSERVER_BLOCKLOCATION_HPP

#include <cstdint>

namespace server {
    class BlockLocation {
    private:
        int32_t x;
        int32_t y;
        int32_t z;
    public:

        BlockLocation(int32_t x, int32_t y, int32_t z);

        int32_t getX() const;

        void setX(int32_t newX);

        int32_t getY() const;

        void setY(int32_t newY);

        int32_t getZ() const;

        void setZ(int32_t newZ);

    };
}


#endif //MCSERVER_BLOCKLOCATION_HPP
