//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_LOCATION_HPP
#define MCSERVER_LOCATION_HPP

#include "BlockLocation.hpp"

namespace server {
    class Location {
    private:
        double x;
        double y;
        double z;
    public:
        double getX() const;

        void setX(double newX);

        double getY() const;

        void setY(double newY);

        double getZ() const;

        void setZ(double newZ);

        BlockLocation toBlockLocation();
    };
}


#endif //MCSERVER_LOCATION_HPP
