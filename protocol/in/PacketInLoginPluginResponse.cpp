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

#include "PacketInLoginPluginResponse.hpp"

namespace protocol {
    PacketInLoginPluginResponse::PacketInLoginPluginResponse(
            int32_t messageId, bool succesful, uint32_t dataLength, uint8_t *data) : PacketInBase(
            LOGIN_PLUGIN_RESPONSE) {
        this->messageId = messageId;
        this->successful = succesful;
        this->dataLength = dataLength;
        this->data = data;

    }

    PacketInLoginPluginResponse::PacketInLoginPluginResponse() : PacketInLoginPluginResponse(0, false,
                                                                                                                 0,
                                                                                                                 nullptr) {
    }

    void PacketInLoginPluginResponse::parse(PacketParser *packetParser) {

    }


    int32_t PacketInLoginPluginResponse::getMessageId() const {
        return messageId;
    }

    bool PacketInLoginPluginResponse::isSuccessful() const {
        return successful;
    }

    uint8_t *PacketInLoginPluginResponse::getData() const {
        return data;
    }

    uint32_t PacketInLoginPluginResponse::getDataLength() const {
        return dataLength;
    }

    std::string PacketInLoginPluginResponse::toString() {
        return std::string();
    }

}