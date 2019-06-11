//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_UTIL_HPP
#define MCSERVER_UTIL_HPP


#include <string>

namespace network {
    class Util {
    private:
        static uint32_t stringLengthRaw(std::string aString);

    public:

        static const uint8_t LONG_LENGTH = 8;

        static const uint8_t INT_LENGTH = 4;

        static int8_t readByte(int socket);

        static int32_t readVarInt(int socket, uint8_t *length);


        static int8_t readByte(uint8_t *data, uint32_t *offset, uint32_t dataLength);

        static uint8_t readUnsignedByte(uint8_t *data, uint32_t *offset, uint32_t dataLength);

        static int32_t readVarInt(uint8_t *data, uint32_t *offset, uint32_t dataLength);

        static std::string readString(uint8_t *data, uint32_t *offset, uint32_t dataLength);

        static uint16_t readUnsignedShort(uint8_t *data, uint32_t *offset, uint32_t dataLength);

        static uint8_t *readByteArray(uint8_t *data, uint32_t dataLength, uint32_t *offset, int32_t count);


        static void writeVarInt(int32_t integer, uint8_t *buffer, uint32_t *offset);

        static void writeString(std::string, uint8_t *buffer, uint32_t *offset);

        static void writeLong(int64_t longInteger, uint8_t *buffer, uint32_t *offset);

        static uint8_t varIntLength(int32_t integer);

        static uint8_t varLongLength(int64_t longInteger);

        static uint32_t stringLength(const std::string &someString);


        static int64_t readLong(unsigned char *data, uint32_t *offset, int dataLength);
    };
}


#endif //MCSERVER_UTIL_HPP
