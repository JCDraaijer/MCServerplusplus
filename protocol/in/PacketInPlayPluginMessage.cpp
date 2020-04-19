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
#include "PacketInPlayPluginMessage.hpp"

namespace protocol {


    PacketInPlayPluginMessage::PacketInPlayPluginMessage(Identifier ident, uint32_t dataLength, uint8_t *data)
            : PacketInBase(SERVER_PLUGIN_MESSAGE), identifier(std::move(ident)), dataLength(dataLength), data(data) {

    }

    Identifier *PacketInPlayPluginMessage::getIdentifier() {
        return &identifier;
    }

    uint8_t *PacketInPlayPluginMessage::getData() {
        return data;
    }

    uint32_t PacketInPlayPluginMessage::getDataLength(){
        return dataLength;
    }

    std::string PacketInPlayPluginMessage::toString() {
        std::ostringstream stringStream;
        char dataString[dataLength + 1];
        sprintf(dataString, "%s", data);
        stringStream << "Server Plugin Message packet. ID: " << this->getId()
                     << ". Identifier: " + identifier.getNamespace() + ":" + identifier.getThing() + ". Data: "
                     << dataString;
        return stringStream.str();
    }

    PacketInPlayPluginMessage::PacketInPlayPluginMessage(PacketParser *parser) : PacketInBase(SERVER_PLUGIN_MESSAGE) {
        parse(parser);
    }

    void PacketInPlayPluginMessage::parse(PacketParser *packetParser) {
        identifier = Identifier(packetParser->readString());
        data = packetParser->readByteArray(&dataLength);
    }

    PacketInPlayPluginMessage::~PacketInPlayPluginMessage() {
        free(data);
    }
}