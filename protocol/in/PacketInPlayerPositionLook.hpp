/* 
MCpp, a Minecraft Server implementation in C++.
Copyright (C) 2020 Johannes Draaijer

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef MCSERVER_PACKETINPLAYERPOSITIONLOOK_HPP
#define MCSERVER_PACKETINPLAYERPOSITIONLOOK_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketInPlayerPositionLook : public PacketInBase {
    private:
        double x;
        double feetY;
        double z;
        float yaw;
        float pitch;
        bool onGround;
    public:
        PacketInPlayerPositionLook(double x, double feetY, double z, float yaw, float pitch, bool onGround);

        PacketInPlayerPositionLook();

        void parse(PacketParser *parser) override;

        std::string toString() override;

    };
}


#endif //MCSERVER_PACKETINPLAYERPOSITIONLOOK_HPP
