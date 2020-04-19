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
#include "PacketInPlayClientSettings.hpp"

namespace protocol {

    PacketInPlayClientSettings::PacketInPlayClientSettings(std::string locale, int8_t renderDistance, int32_t chatMode,
                                                           bool chatColors, uint8_t skinParts, int32_t mainhand)
            : PacketInBase(
            CLIENT_SETTINGS) {
        this->locale = std::move(locale);
        this->renderDistance = renderDistance;
        this->chatMode = chatMode;
        this->chatColors = chatColors;
        this->skinParts = skinParts;
        this->mainHand = mainhand;

    }

    PacketInPlayClientSettings::PacketInPlayClientSettings() : PacketInPlayClientSettings("", 0, 0, false, 0,
                                                                                                    0) {
    }

    void PacketInPlayClientSettings::parse(PacketParser *packetParser) {
        locale = packetParser->readString();
        renderDistance = packetParser->readByte();
        chatMode = packetParser->readVarInt();
        chatColors = packetParser->readBoolean();
        skinParts = packetParser->readUnsignedByte();
        mainHand = packetParser->readVarInt();
    }

    std::string PacketInPlayClientSettings::toString() {
        std::ostringstream stringStream;
        stringStream << "Client Settings packet. ID: " << this->getId() << ". Render distance: "
                     << std::to_string(renderDistance) << ". Chat Mode: " << chatMode;
        return stringStream.str();
    }

}
