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


#ifndef MCSERVER_PACKETINPLAYTELEPORTCONFIRM_HPP
#define MCSERVER_PACKETINPLAYTELEPORTCONFIRM_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketInPlayTeleportConfirm : public PacketInBase {
    private:
        int32_t teleportId;
    public:
        explicit PacketInPlayTeleportConfirm(int32_t teleportId);

        PacketInPlayTeleportConfirm();

        void parse(PacketParser *packetParser) override;

        std::string toString() override;

    };
}


#endif //MCSERVER_PACKETINPLAYTELEPORTCONFIRM_HPP
