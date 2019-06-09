//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_UTIL_H
#define MCSERVER_UTIL_H


#include <string>

namespace networking {
    class Util {
    public:
        static bool readBoolean(int);

        static bool readBoolean(unsigned char *, int *, int);

        static char readByte(int);

        static char readByte(unsigned char *, int *, int);

        static unsigned char readUnsignedByte(int);

        static unsigned char readUnsignedByte(unsigned char *, int *, int);

        static short readShort(int);

        static short readShort(unsigned char *, int *, int);

        static unsigned short readUnsignedShort(int);

        static unsigned short readUnsignedShort(unsigned char *, int *, int);

        static int readInt(int);

        static int readInt(unsigned char *, int *, int);

        static int readVarInt(int);

        static int readVarInt(int, int *);

        static int readVarInt(unsigned char *, int *, int);

        static long readLong(int);

        static long readLong(unsigned char *, int *, int);

        static long readVarLong(int);

        static long readVarLong(unsigned char *, int *, int);

        static float readFloat(int);

        static float readFloat(unsigned char *, int *, int);

        static double readDouble(int);

        static double readDouble(unsigned char *, int *, int);

        static std::string readString(int);

        static std::string readString(unsigned char *, int *, int);

        static std::string readChat(int);

        static std::string readChat(unsigned char *, int *, int);

        static std::string readIdentifier(int);

        static std::string readIdentifier(unsigned char *, int *, int);

        static const char *serializeString(const std::string&, int*);

    };
}


#endif //MCSERVER_UTIL_H
