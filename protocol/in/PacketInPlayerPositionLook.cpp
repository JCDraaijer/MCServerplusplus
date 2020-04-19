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

#include <sstream>
#include "PacketInPlayerPositionLook.hpp"

namespace protocol {

    PacketInPlayerPositionLook::PacketInPlayerPositionLook(double x, double feetY, double z, float yaw, float pitch,
                                                           bool onGround) : PacketInBase(SERVER_PLAYER_POSITION_LOOK) {
        this->x = x;
        this->feetY = feetY;
        this->z = z;
        this->yaw = yaw;
        this->pitch = pitch;
        this->onGround = onGround;
    }

    PacketInPlayerPositionLook::PacketInPlayerPositionLook() : PacketInPlayerPositionLook(0, 0, 0, 0, 0, false) {

    }

    void PacketInPlayerPositionLook::parse(PacketParser *parser) {
        this->x = parser->readDouble();
        this->feetY = parser->readDouble();
        this->z = parser->readDouble();
        this->yaw = parser->readFloat();
        this->pitch = parser->readFloat();
        this->onGround = parser->readBoolean();
    }

    std::string PacketInPlayerPositionLook::toString() {
        std::ostringstream stringStream;
        stringStream << "Player Position Look Packet. ID: " << this->getId() << ". (X, Y, Z): ("
                     << std::to_string(x) << ", " << std::to_string(feetY) << ", " << std::to_string(z) << "). Yaw: " << yaw << ". Pitch: " << pitch;
        return stringStream.str();
    }
}