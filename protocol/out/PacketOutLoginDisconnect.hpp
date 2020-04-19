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

#ifndef MCSERVER_PACKETOUTLOGINDISCONNECT_HPP
#define MCSERVER_PACKETOUTLOGINDISCONNECT_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutLoginDisconnect : public PacketOutBase {
    private:
        //TODO Change this to JSON/Chat
        std::string reason;
    public:
        explicit PacketOutLoginDisconnect(std::string reason);

        ~PacketOutLoginDisconnect() override;

        const std::string &getReason() const;

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETOUTLOGINDISCONNECT_HPP
