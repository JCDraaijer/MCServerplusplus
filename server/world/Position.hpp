//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_POSITION_HPP
#define MCSERVER_POSITION_HPP

namespace server {
    class Position {
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
    };
}


#endif //MCSERVER_POSITION_HPP
