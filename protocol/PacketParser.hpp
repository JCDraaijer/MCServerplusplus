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

#ifndef MCSERVER_PACKETPARSER_HPP
#define MCSERVER_PACKETPARSER_HPP

#include "ConnectionState.hpp"
#include "in/PacketInBase.hpp"

namespace protocol {

    class PacketInBase;

    class PacketParser {
    private:

        uint32_t currentOffset;
        uint32_t dataLength;
        uint8_t *dataBuffer;

        PacketInBase *
        _parseHandshake(int packetId);

        PacketInBase *
        _parseStatus(int packetId);

        PacketInBase *
        _parsePlay(int packetId);

        PacketInBase *
        _parseLogin(int packetId);

        bool verifyDataLeft(uint32_t left);

    public:

        explicit PacketParser();

        PacketInBase *
        parse(ConnectionState currentState, int packetId, unsigned char *data,
              int dataLength);


        int64_t readLong();

        uint8_t *readByteArray(uint32_t count);

        uint8_t *readByteArray(uint32_t *length);

        uint16_t readUnsignedShort();

        std::string readString();

        std::string readString(uint32_t *length);

        int32_t readVarInt(int socket, uint8_t *length);

        int32_t readVarInt();

        int8_t readByte();

        int8_t readByte(int socket);

        uint8_t readUnsignedByte();

        bool readBoolean();
    };
}


#endif //MCSERVER_PACKETPARSER_HPP
