//
// Created by jona on 2019-06-09.
//

#include <unistd.h>
#include "Util.hpp"
#include "OffsetOutOfBoundsException.hpp"
#include "Exception.hpp"

namespace protocol {

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
        uint8_t theByte = 0;
        int readBytes = read(socket, &theByte, 1);
        if (readBytes != 1) {
            throw Exception("Could not read byte from network!");
        }
        return theByte;
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