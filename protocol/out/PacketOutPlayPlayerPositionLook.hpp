/*
MCpp, a Minecraft Server implementation in C++.
Copyright (C) 2019, 2020 Johannes Draaijer

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

#ifndef MCSERVER_PACKETOUTPLAYPLAYERPOSITIONLOOK_HPP
#define MCSERVER_PACKETOUTPLAYPLAYERPOSITIONLOOK_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutPlayPlayerPositionLook : public PacketOutBase {
    private:
        double x;
        double y;
        double z;
        float yaw;
        float pitch;
        uint8_t flags;
        int32_t teleportId;
    public:
        PacketOutPlayPlayerPositionLook(double x, double y, double z, float yaw, float pitch, uint8_t flags, int32_t teleportId);

        ~PacketOutPlayPlayerPositionLook() override;

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETOUTPLAYPLAYERPOSITIONLOOK_HPP
