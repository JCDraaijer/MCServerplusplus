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

#include "PacketInPlayUpdateStructureBlock.hpp"

namespace protocol {

    PacketInPlayUpdateStructureBlock::PacketInPlayUpdateStructureBlock(server::Location location, int32_t action,
                                                                       int32_t mode, std::string name, int8_t offsetX,
                                                                       int8_t offsetY, int8_t offsetZ, int8_t sizeX,
                                                                       int8_t sizeY, int8_t sizeZ, int32_t mirror,
                                                                       int32_t rotation, std::string metadata,
                                                                       float integrity, int64_t seed, uint8_t flags)
            : PacketInBase(UPDATE_STRUCTURE_BLOCK) {
        this->location = location;
        this->action = action;
        this->mode = mode;
        this->name = std::move(name);
        this->offsetX = offsetX;
        this->offsetY = offsetY;
        this->offsetZ = offsetZ;
        this->sizeX = sizeX;
        this->sizeY = sizeY;
        this->sizeZ = sizeZ;
        this->mirror = mirror;
        this->rotation = rotation;
        this->metadata = std::move(metadata);
        this->integrity = integrity;
        this->seed = seed;
        this->flags = flags;
    }

    PacketInPlayUpdateStructureBlock::PacketInPlayUpdateStructureBlock() : PacketInPlayUpdateStructureBlock(
            server::Location(), 0, 0, "", 0, 0, 0, 0, 0, 0, 0, 0, "", 0, 0, 0) {

    }

    void PacketInPlayUpdateStructureBlock::parse(PacketParser *packetParser) {

    }

    std::string PacketInPlayUpdateStructureBlock::toString() {
        return std::string();
    }
}

