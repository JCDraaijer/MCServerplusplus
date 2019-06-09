//
// Created by jona on 2019-06-09.
//

#include "Util.h"
#include <unistd.h>

namespace networking {
    char Util::readByte(int socket) {
        char buffer[1];
        int bytesRead = read(socket, buffer, 1);
        if (bytesRead != 1) {
            std::printf("Error! Could not read byte. (Code: %d, %d)\n", bytesRead, errno);
            return 0;
        }
        return buffer[0];
    }

    unsigned char Util::readUnsignedByte(unsigned char *data, int *offset, int dataLength) {
        return data[(*offset)++];
    }

    int Util::readVarInt(int socket) {
        int numRead = 0;
        int result = 0;
        char read;
        do {
            read = readByte(socket);
            int value = read & 0b01111111;
            result |= (value << (7 * numRead));
            numRead++;
            if (numRead > 5) {
                std::printf("Error! Tried to read a VarInt>5\n");
            }
        } while ((read & 0b10000000) != 0);

        return result;
    }

    int Util::readVarInt(int socket, int *length) {
        int numRead = 0;
        int result = 0;
        char read;
        do {
            read = readByte(socket);
            int value = read & 0b01111111;
            result |= (value << (7 * numRead));
            numRead++;
            if (numRead > 5) {
                std::printf("Error! Tried to read a VarInt>5\n");
            }
        } while ((read & 0b10000000) != 0);

        *length += numRead;

        return result;
    }

    int Util::readVarInt(unsigned char *data, int *offset, int dataLength) {
        int numRead = 0;
        int result = 0;
        char read;
        do {
            read = readUnsignedByte(data, offset, dataLength);
            int value = read & 0b01111111;
            result |= (value << (7 * numRead));
            numRead++;
            if (numRead > 5) {
                std::printf("Error! Tried to read a VarInt>5\n");
            } else if (*offset > dataLength) {
                std::printf("Error! Reading garbage!\n");
            }
        } while ((read & 0b10000000) != 0);

        return result;
    }

    std::string Util::readString(int socket) {
        int length = readVarInt(socket);
        char toReturn[length + 1];
        toReturn[length] = '\0';
        for (int i = 0; i < length; i++) {
            toReturn[i] = readByte(socket);
        }
        return std::string(toReturn);
    }

    std::string Util::readString(unsigned char *data, int *offset, int dataLength) {
        int length = readVarInt(data, offset, dataLength);
        char toReturn[length + 1];
        toReturn[length] = '\0';
        for (int i = 0; i < length; i++) {
            toReturn[i] = readUnsignedByte(data, offset, dataLength);
        }
        return std::string(toReturn);
    }

    short Util::readShort(int socket) {
        unsigned char first = readByte(socket);
        unsigned char second = readByte(socket);
        short toReturn = (first << 8) | second;
        return toReturn;
    }

    unsigned short Util::readUnsignedShort(int socket) {
        unsigned char first = readByte(socket);
        unsigned char second = readByte(socket);
        unsigned short toReturn = (first << 8) | second;
        return toReturn;
    }

    unsigned short Util::readUnsignedShort(unsigned char *data, int *offset, int length) {
        unsigned char first = readUnsignedByte(data, offset, length);
        unsigned char second = readUnsignedByte(data, offset, length);
        unsigned short toReturn = (first << 8) | second;
        return toReturn;
    }

    bool Util::readBoolean(int socket) {
        char result = readByte(socket);
        return result;
    }

    unsigned char Util::readUnsignedByte(int socket) {
        unsigned char buffer[1];
        int bytesRead = read(socket, buffer, 1);
        if (bytesRead != 1) {
            std::printf("Error! Could not read byte. (Code: %d, %d)\n", bytesRead, errno);
            return 0;
        }
        return buffer[0];
    }

    int Util::readInt(int socket) {
        unsigned char buffer[4];
        int bytesRead = read(socket, buffer, 4);
        if (bytesRead != 4) {
            std::printf("Could not read integer! Code: %d, %d)\n", bytesRead, errno);
            return 0;
        }
        int result = buffer[3] << 24 | buffer[2] << 16 | buffer[1] << 8 | buffer[0];
        return result;
    }

    long Util::readLong(int socket) {
        unsigned char buffer[8];
        int bytesRead = read(socket, buffer, 4);
        if (bytesRead != 4) {
            std::printf("Could not read integer! Code: %d, %d)\n", bytesRead, errno);
            return 0;
        }
        int result = buffer[3] << 24 | buffer[2] << 16 | buffer[1] << 8 | buffer[0];
        return 0;
    }

    unsigned char *Util::writeVarInt(int value, int *length) {
        unsigned char buffer[5];
        int current = 0;
        do {
            buffer[current++] = value & 0b01111111;
            value >>= 7;
        } while (value != 0);
        auto *result = (unsigned char *) malloc(sizeof(unsigned char) * current);
        for (int i = 0; i < current; i++) {
            result[i] = buffer[i];
        }
        *length = current;
        return result;
    }

    const char *Util::writeString(std::string theText, int *dataLength) {
        *dataLength = theText.size();
        return theText.c_str();
    }

}