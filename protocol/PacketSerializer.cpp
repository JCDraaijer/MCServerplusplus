//
// Created by jona on 2019-06-10.
//


#include <cstring>
#include "PacketSerializer.hpp"

#define LONG_LENGTH 8
#define INT_LENGTH 4
#define DOUBLE_LENGTH 8
#define FLOAT_LENGTH 4
#define SHORT_LENGHT 2

namespace protocol {

    PacketSerializer::PacketSerializer(uint32_t bufferSize) {
        this->currentDataSize = 0;
        this->dataBufferSize = bufferSize;
        this->dataBuffer = (uint8_t *) malloc(sizeof(uint8_t) * bufferSize);
        this->packetBuffer = (uint8_t *) malloc((sizeof(uint8_t) * bufferSize) + LENGTH_BUFFER_SIZE);
    }

    uint8_t *PacketSerializer::serializePacket(PacketOutBase *packet, uint32_t *packetLength, bool includeLength) {

        currentDataSize = 0;
        writeVarInt(packet->getId());
        packet->serialize(this);

        uint8_t sizeLength = varIntLength(currentDataSize);

        verifyBufferCapacity(sizeLength);

        if (includeLength) {

            memcpy(&packetBuffer[sizeLength], dataBuffer, sizeof(uint8_t) * currentDataSize);

            writeLengthHeader(currentDataSize);

            *packetLength += sizeLength + currentDataSize;
        } else {
            memcpy(&packetBuffer, dataBuffer, sizeof(uint8_t) * currentDataSize);
            *packetLength += currentDataSize;
        }
        return packetBuffer;
    }

    uint8_t *PacketSerializer::serializePacket(PacketOutBase *packet, uint32_t *packetLength) {
        return serializePacket(packet, packetLength, true);
    }

    void PacketSerializer::setBufferSize(uint32_t newSize) {
        dataBufferSize = newSize;
        dataBuffer = (uint8_t *) realloc(dataBuffer, sizeof(uint8_t) * newSize);
        packetBuffer = (uint8_t *) realloc(packetBuffer, (sizeof(uint8_t) * newSize) + LENGTH_BUFFER_SIZE);
    }

    PacketSerializer::~PacketSerializer() {
        free(dataBuffer);
        free(packetBuffer);
    }

    uint8_t PacketSerializer::varIntLength(int32_t integer) {
        uint32_t toTest = integer;
        if (toTest == 0) {
            return 1;
        }
        uint8_t counter = 0;
        do {
            counter++;
            toTest >>= 7u;
        } while (toTest != 0);
        return counter;
    }

    uint8_t PacketSerializer::varLongLength(int64_t longInteger) {
        uint64_t toTest = longInteger;
        if (toTest == 0) {
            return 1;
        }
        uint8_t counter = 0;
        do {
            counter++;
            toTest >>= 7u;
        } while (toTest != 0);
        return counter;
    }


    uint32_t PacketSerializer::stringLength(const std::string &someString) {
        return varIntLength(someString.size()) + someString.size();
    }

    void PacketSerializer::writeVarInt(int32_t integer) {
        verifyBufferCapacity(varIntLength(integer));
        do {
            uint8_t value = integer & 0b1111111;
            integer >>= 7;
            if ((uint32_t) integer > 0) {
                value |= 0b10000000u;
            }
            dataBuffer[currentDataSize++] = value;
        } while ((uint32_t) integer > 0);
    }

    void PacketSerializer::writeByteArray(const uint8_t *data, uint32_t count) {
        for (int i = 0; i < count; i++) {
            dataBuffer[(currentDataSize++)] = data[i];
        }
    }


    void PacketSerializer::writeLengthHeader(int32_t integer) {
        uint8_t offset = 0;
        do {
            uint8_t value = integer & 0b1111111;
            integer >>= 7;
            if ((uint32_t) integer > 0) {
                value |= 0b10000000u;
            }
            packetBuffer[offset++] = value;
        } while ((uint32_t) integer > 0);
    }

    void PacketSerializer::writeString(std::string aString) {
        verifyBufferCapacity(stringLength(aString));
        writeVarInt(aString.size());
        std::string::iterator iterator;
        for (iterator = aString.begin(); iterator != aString.end(); iterator++) {
            dataBuffer[currentDataSize++] = *iterator;
        }
    }

    void PacketSerializer::writeLong(int64_t longInteger) {
        verifyBufferCapacity(8);
        for (int i = 0; i < LONG_LENGTH; i++) {
            dataBuffer[currentDataSize++] = longInteger & 0xFF;
            longInteger >>= 8;
        }
    }

    void PacketSerializer::verifyBufferCapacity(uint32_t capacity) {
        uint32_t bufferSizeToTest = dataBufferSize;
        if (bufferSizeToTest - currentDataSize < capacity) {
            while (bufferSizeToTest - currentDataSize < capacity) {
                bufferSizeToTest *= 2;
            }
            setBufferSize(bufferSizeToTest);
        }
    }

    void PacketSerializer::writeInt(int32_t integer) {
        verifyBufferCapacity(INT_LENGTH);
        for (int i = 0; i < INT_LENGTH; i++) {
            dataBuffer[currentDataSize++] = integer & 0xFF;
            integer >>= 8;
        }
    }

    void PacketSerializer::writeUnsignedByte(uint8_t aByte) {
        verifyBufferCapacity(1);
        dataBuffer[currentDataSize++] = aByte;
    }

    void PacketSerializer::writeBoolean(bool someBoolean) {
        writeUnsignedByte(someBoolean);
    }

    void PacketSerializer::writeDouble(double doubleToWrite) {
        verifyBufferCapacity(DOUBLE_LENGTH);
        uint64_t doubleToLong;
        memcpy(&doubleToLong, &doubleToWrite, DOUBLE_LENGTH);
        writeLong(doubleToLong);
    }

    void PacketSerializer::writeFloat(float floatToWrite) {
        verifyBufferCapacity(DOUBLE_LENGTH);
        uint32_t floatToInt;
        memcpy(&floatToInt, &floatToWrite, FLOAT_LENGTH);
        writeInt(floatToInt);
    }

    void PacketSerializer::writeUnsignedShort(uint16_t someShort) {
        verifyBufferCapacity(SHORT_LENGHT);
        writeUnsignedByte(someShort & 0xFF);
        writeUnsignedByte((someShort >> 8u) & 0xFF);
    }

}
