//
// Created by jona on 2019-06-19.
//

#ifndef MCSERVER_NBTTAGBASE_HPP
#define MCSERVER_NBTTAGBASE_HPP

#include <cstdint>
#include <string>

namespace nbt {

    enum NBTTag {
        END = 0,
        BYTE = 1,
        SHORT = 2,
        INT = 3,
        LONG = 4,
        FLOAT = 5,
        DOUBLE = 6,
        BYTE_ARRAY = 7,
        STRING = 8,
        LIST = 9,
        COMPOUND = 10,
        INT_ARRAY = 11,
        LONG_ARRAY = 12
    };

    class NBTTagBase {
    private:
        NBTTag typeId;
        std::string name;
    public:
        explicit NBTTagBase(NBTTag typeId);

        explicit NBTTagBase(NBTTag typeId, std::string name);

        virtual ~NBTTagBase() = 0;

        bool hasName();

        std::string getName();

        void parseName(std::FILE *stream);

        virtual void parsePayload(std::FILE *stream, bool named) = 0;

        virtual void write(std::FILE *stream, bool named) = 0;
    };
}


#endif //MCSERVER_NBTTAGBASE_HPP
