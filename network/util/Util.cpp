//
// Created by jona on 2019-06-09.
//

#include <unistd.h>
#include "Util.hpp"
#include "OffsetOutOfBoundsException.hpp"
#include "Exception.hpp"

namespace network {
    uint8_t Util::readUnsignedByte(uint8_t *data, uint32_t *offset, uint32_t dataLength) {
        if (dataLength <= *offset) {
            throw OffsetOutOfBoundsException(*offset, dataLength);
        }
        return data[(*offset)++];
    }

    int8_t Util::readByte(uint8_t *data, uint32_t *offset, uint32_t dataLength) {
        return readUnsignedByte(data, offset, dataLength);
    }

    int8_t Util::readByte(int socket) {
        auto *buffer = (uint8_t *) malloc(sizeof(uint8_t));
        int readBytes = read(socket, buffer, 1);
        if (readBytes != 1) {
            throw Exception("Could not read byte from network!");
        }
        uint8_t value = buffer[0];
        free(buffer);
        return value;
    }

    int32_t Util::readVarInt(uint8_t *data, uint32_t *offset, uint32_t dataLength) {
        int32_t finalValue = 0;
        uint8_t read = 0;
        uint8_t current = 0;
        do {
            if (read > 5) {
                throw Exception("Can't read VarInt>5!");
            }
            current = readByte(data, offset, dataLength);
            finalValue |= (current & 0b01111111u) << (7u * read++);
        } while ((current & 0b10000000u) != 0);
        return finalValue;
    }


    int32_t Util::readVarInt(int socket, uint8_t *length) {
        int32_t finalValue = 0;
        uint8_t read = 0;
        uint8_t current = 0;
        do {
            if (read > 5) {
                throw Exception("Can't read VarInt>5!");
            }
            current = readByte(socket);
            finalValue |= (current & 0b01111111u) << (7u * read++);
        } while ((current & 0b10000000u) != 0);
        *length += read;
        return finalValue;
    }

    std::string Util::readString(uint8_t *data, uint32_t *offset, uint32_t dataLength) {
        int32_t length = readVarInt(data, offset, dataLength);
        if (length + *offset > dataLength) {
            throw Exception("Length is greater than available data! (String)");
        }
        char stringToReturn[length + 1];
        stringToReturn[length] = '\0';
        for (int i = 0; i < length; i++) {
            stringToReturn[i] = readByte(data, offset, dataLength);
        }
        return std::string(stringToReturn);
    }

    uint16_t Util::readUnsignedShort(uint8_t *data, uint32_t *offset, uint32_t dataLength) {
        if (*offset + 2 >= dataLength) {
            throw Exception("Length is greater than available data! (Unsigned short)");
        }
        uint16_t shortToReturn =
                readUnsignedByte(data, offset, dataLength) << 8u | readUnsignedByte(data, offset, dataLength);
        return shortToReturn;
    }

    uint8_t Util::varIntLength(int32_t integer) {
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

    uint8_t Util::varLongLength(int64_t longInteger) {
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

    uint32_t Util::stringLength(const std::string &someString) {
        return varIntLength(stringLengthRaw(someString)) + stringLengthRaw(someString);
    }

    void Util::writeVarInt(int32_t integer, uint8_t *buffer, uint32_t *offset) {
        do {
            uint8_t value = integer & 0b1111111;
            integer >>= 7;
            if ((uint32_t) integer > 0) {
                value |= 0b10000000u;
            }
            buffer[(*offset)++] = value;
        } while ((uint32_t) integer > 0);
    }

    void Util::writeString(std::string aString, uint8_t *buffer, uint32_t *offset) {
        writeVarInt(stringLengthRaw(aString), buffer, offset);
        std::string::iterator iterator;
        for (iterator = aString.begin(); iterator != aString.end(); iterator++) {
            buffer[(*offset)++] = *iterator;
        }
    }

    void Util::writeLong(int64_t longInteger, uint8_t *buffer, uint32_t *offset) {
        for (int i = 0; i < 8; i++) {
            buffer[(*offset)++] = longInteger & 0xFF;
            longInteger >>= 8;
        }
    }

    uint8_t *Util::readByteArray(uint8_t *data, uint32_t dataLength, uint32_t *offset, int32_t count) {
        auto *actualData = (uint8_t *) malloc(sizeof(uint8_t) * count);
        for (int i = 0; i < count; i++) {
            actualData[i] = readByte(data, offset, dataLength);
        }
        return actualData;
    }

    int64_t Util::readLong(unsigned char *data, uint32_t *offset, int dataLength) {
        int64_t value = 0;
        for (int i = 0; i < 8; i++) {
            value |= readByte(data, offset, dataLength);
            value <<= 8;
        }
        return value;
    }

    uint32_t Util::stringLengthRaw(std::string aString) {
        return aString.size();
    }
}