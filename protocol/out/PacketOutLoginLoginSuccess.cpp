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

#include "PacketOutLoginLoginSuccess.hpp"

namespace protocol {

    PacketOutLoginLoginSuccess::PacketOutLoginLoginSuccess(const server::UUID& uuid, std::string &username) :
            PacketOutBase(LOGIN_SUCCESS), uuid(uuid), username(username) {

    }

    server::UUID &PacketOutLoginLoginSuccess::getUuid() {
        return uuid;
    }

    void PacketOutLoginLoginSuccess::setUuid(const server::UUID &newUuid) {
        this->uuid = newUuid;
    }

    std::string &PacketOutLoginLoginSuccess::getUsername() {
        return username;
    }

    void PacketOutLoginLoginSuccess::setUsername(const std::string &newUsername) {
        PacketOutLoginLoginSuccess::username = newUsername;
    }

    void PacketOutLoginLoginSuccess::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeString(uuid.toString());
        packetSerializer->writeString(getUsername());
    }

    PacketOutLoginLoginSuccess::~PacketOutLoginLoginSuccess() = default;
}