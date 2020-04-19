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

#include "PacketOutPlayPlayerPositionLook.hpp"

namespace protocol {
    void PacketOutPlayPlayerPositionLook::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeDouble(x);
        packetSerializer->writeDouble(y);
        packetSerializer->writeDouble(z);
        packetSerializer->writeFloat(yaw);
        packetSerializer->writeFloat(pitch);
        packetSerializer->writeUnsignedByte(flags);
        packetSerializer->writeVarInt(teleportId);
    }

    PacketOutPlayPlayerPositionLook::PacketOutPlayPlayerPositionLook(double x, double y, double z, float yaw,
                                                                     float pitch, uint8_t flags, int32_t teleportId)
            : PacketOutBase(CLIENT_PLAYER_POSITION_LOOK) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->yaw = yaw;
        this->pitch = pitch;
        this->flags = flags;
        this->teleportId = teleportId;

    }
}
