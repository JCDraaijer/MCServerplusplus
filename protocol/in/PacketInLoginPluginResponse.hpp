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


#ifndef MCSERVER_PACKETINLOGINPLUGINRESPONSE_HPP
#define MCSERVER_PACKETINLOGINPLUGINRESPONSE_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketInLoginPluginResponse : public PacketInBase {
    private:
        int32_t messageId;
        bool successful;
        uint8_t *data;
        uint32_t dataLength;
    public:
        PacketInLoginPluginResponse(int32_t messageId, bool succesful, uint32_t dataLength, uint8_t *data);

        int32_t getMessageId() const;

        bool isSuccessful() const;

        uint8_t *getData() const;

        uint32_t getDataLength() const;

        std::string toString() override;

        explicit PacketInLoginPluginResponse(PacketParser *parser);

        void parse(PacketParser *packetParser) override;
    };
}


#endif //MCSERVER_PACKETINLOGINPLUGINRESPONSE_HPP
