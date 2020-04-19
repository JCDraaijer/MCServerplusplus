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


#include "PacketOutHandshakeLegacyPingResponse.hpp"

namespace protocol {
    void PacketOutHandshakeLegacyPingResponse::serialize(protocol::PacketSerializer *packetSerializer) {
        auto *ps = packetSerializer;
        uint8_t data[] = {0xFF, 0x02, 0xFF, 0x00, 0xA7, 0x00, 0x31, 0x00, 0x00, 0x7F, 0x00, 0x31, 0x00, 0x2e, 0x00,
                          0x34, 0x00, 0x2e, 0x00, 0x32, 0x00, 0x00, 0x41, 0x00, 0x20, 0x00, 0x4d, 0x00, 0x69, 0x00,
                          0x6e,
                          0x00, 0x65, 0x00, 0x63, 0x00, 0x72, 0x00, 0x61, 0x00, 0x66, 0x00, 0x74, 0x00, 0x20, 0x00,
                          0x53, 0x00, 0x65, 0x00,
                          0x72, 0x00, 0x76, 0x00, 0x65, 0x00, 0x72, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x32,
                          0x00, 0x30};
        ps->writeByteArray(&data[0], 67);
    }

    PacketOutHandshakeLegacyPingResponse::PacketOutHandshakeLegacyPingResponse() : PacketOutBase(LEGACY_RESPONSE){

    }

    PacketOutHandshakeLegacyPingResponse::~PacketOutHandshakeLegacyPingResponse() {

    }
}
