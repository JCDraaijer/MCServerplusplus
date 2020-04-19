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

#ifndef MCSERVER_PACKETINBASE_HPP
#define MCSERVER_PACKETINBASE_HPP

#include <string>
#include "../PacketBase.hpp"
#include "../PacketParser.hpp"

namespace protocol {

    class PacketParser;

    class PacketInBase : public PacketBase {
    private:
        const InPacketType type;
    public:
        explicit PacketInBase(InPacketType type);

        virtual ~PacketInBase();

        virtual void parse(PacketParser *packetParser) = 0;

        InPacketType getType();

    };
}

#endif //MCSERVER_PACKETINBASE_HPP
