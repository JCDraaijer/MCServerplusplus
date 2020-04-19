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

#include <sstream>
#include "PacketInLoginStart.hpp"

namespace protocol {
    PacketInLoginStart::PacketInLoginStart(std::string name) : PacketInBase(LOGIN_START), name(std::move(name)) {

    }

    std::string PacketInLoginStart::getName() {
        return name;
    }

    std::string PacketInLoginStart::toString() {
        std::ostringstream stringStream;
        stringStream << "Login Start packet. ID: " << this->getId() << ". Name: " << getName();
        return stringStream.str();
    }

    PacketInLoginStart::PacketInLoginStart(PacketParser *parser) : PacketInBase(LOGIN_START) {
        parse(parser);
    }

    void PacketInLoginStart::parse(PacketParser *packetParser) {
        name = packetParser->readString();
    }
}
