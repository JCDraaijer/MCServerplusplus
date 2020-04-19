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
    protected:
        void parseName(std::FILE *stream);

    public:
        explicit NBTTagBase(NBTTag typeId);

        explicit NBTTagBase(NBTTag typeId, std::string name);

        virtual ~NBTTagBase();

        bool hasName();

        std::string getName();


        virtual void parsePayload(std::FILE *stream, bool named) = 0;

        virtual void write(std::FILE *stream, bool named) = 0;

        static int16_t readShort(std::FILE *stream);

        static int32_t readInt(std::FILE *stream);

        static int64_t readLong(std::FILE *stream);

        static float readFloat(std::FILE *stream);

        static double readDouble(std::FILE *stream);
    };
}


#endif //MCSERVER_NBTTAGBASE_HPP
