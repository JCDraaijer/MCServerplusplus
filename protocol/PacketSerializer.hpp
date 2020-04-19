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


#ifndef MCSERVER_PACKETSERIALIZER_HPP
#define MCSERVER_PACKETSERIALIZER_HPP

#define LENGTH_BUFFER_SIZE 5

#include "out/PacketOutBase.hpp"

namespace protocol {

    class PacketOutBase;

    class PacketSerializer {
    private:
        uint8_t *dataBuffer;
        uint32_t dataBufferSize;
        uint8_t *packetBuffer;

        uint32_t currentDataSize;

        void writeLengthHeader(int32_t integer);

    public:
        explicit PacketSerializer(uint32_t bufferSize);

        ~PacketSerializer();

        void setBufferSize(uint32_t newSize);

        uint8_t *serializePacket(PacketOutBase *packet, uint32_t *packetLength);

        void writeVarInt(int32_t integer);

        void writeString(std::string);

        void writeLong(int64_t longInteger);

        void writeByteArray(const uint8_t *data, uint32_t count);

        void verifyBufferCapacity(uint32_t capacity);

        static uint8_t varIntLength(int32_t integer);

        static uint8_t varLongLength(int64_t longInteger);

        static uint32_t stringLength(const std::string &someString);

        void writeInt(int32_t integer);

        void writeUnsignedByte(uint8_t aByte);

        void writeBoolean(bool someBoolean);

        void writeDouble(double doubleToWrite);

        void writeFloat(float floatToWrite);

        uint8_t *serializePacket(PacketOutBase *packet, uint32_t *packetLength, bool includeLength);

        void writeUnsignedShort(uint16_t someShort);
    };

}

#endif //MCSERVER_PACKETSERIALIZER_HPP
