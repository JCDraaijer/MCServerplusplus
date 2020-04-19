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


#ifndef MCSERVER_PACKETINPLAYUPDATESTRUCTUREBLOCK_HPP
#define MCSERVER_PACKETINPLAYUPDATESTRUCTUREBLOCK_HPP

#include "../../server/world/Location.hpp"
#include "PacketInBase.hpp"

namespace protocol {
    class PacketInPlayUpdateStructureBlock : public PacketInBase {
    private:
        server::Location location;
        int32_t action;
        int32_t mode;
        std::string name;
        int8_t offsetX;
        int8_t offsetY;
        int8_t offsetZ;
        int8_t sizeX;
        int8_t sizeY;
        int8_t sizeZ;
        int32_t mirror;
        int32_t rotation;
        std::string metadata;
        float integrity;
        int64_t seed;
        uint8_t flags;

    public:

        PacketInPlayUpdateStructureBlock(server::Location location, int32_t action, int32_t mode, std::string name,
                                         int8_t offsetX, int8_t offsetY, int8_t offsetZ, int8_t sizeX, int8_t sizeY,
                                         int8_t sizeZ, int32_t mirror, int32_t rotation, std::string metadata,
                                         float integrity, int64_t seed, uint8_t flags);

        PacketInPlayUpdateStructureBlock();

        void parse(PacketParser *packetParser) override;

        std::string toString() override;

    };
}


#endif //MCSERVER_PACKETINPLAYUPDATESTRUCTUREBLOCK_HPP
