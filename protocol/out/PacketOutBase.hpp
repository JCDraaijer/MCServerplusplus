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


#ifndef MCSERVER_PACKETOUTBASE_HPP
#define MCSERVER_PACKETOUTBASE_HPP

#include "../PacketBase.hpp"
#include "../PacketSerializer.hpp"

namespace protocol {

    class PacketSerializer;

    class PacketOutBase : public PacketBase {
    private:
        const OutPacketType type;
    public:
        explicit PacketOutBase(OutPacketType type);

        const OutPacketType getType();

        std::string toString() override;

        virtual void serialize(PacketSerializer *packetSerializer) = 0;

        virtual ~PacketOutBase();
    };
}


#endif //MCSERVER_PACKETOUTBASE_HPP
