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


#include <vector>
#include <cstring>
#include "NBTTagBase.hpp"

namespace nbt {

    NBTTagBase::NBTTagBase(NBTTag typeId) : typeId(typeId), name("") {
    }

    NBTTagBase::NBTTagBase(NBTTag typeId, std::string name) : typeId(typeId), name(std::move(name)) {
    }

    bool NBTTagBase::hasName() {
        return !name.empty();
    }

    std::string NBTTagBase::getName() {
        return name;
    }

    void NBTTagBase::parseName(FILE *stream) {
        uint16_t nameLength = readShort(stream);
        std::vector<char> nameVector(nameLength);
        std::fread(&nameVector[0], sizeof(nameVector[0]), nameVector.size(), stream);
        name = std::string(nameVector.begin(), nameVector.end());
    }

    int16_t NBTTagBase::readShort(std::FILE *stream) {
        uint8_t array[2];
        std::fread(&array[1], 1, 1, stream);
        std::fread(&array[0], 1, 1, stream);
        return array[1] | array[0];
    }

    int32_t NBTTagBase::readInt(std::FILE *stream) {
        uint8_t array[4];
        for (int i = 0; i < 4; i++) {
            std::fread(&array[3 - i], 1, 1, stream);
        }
        return array[3] << 24 | array[2] << 16 | array[1] << 8 | array[0];
    }

    int64_t NBTTagBase::readLong(std::FILE *stream) {
        uint8_t array[8];
        for (int i = 0; i < 8; i++) {
            std::fread(&array[7 - i], 1, 1, stream);
        }
        int64_t value = (int64_t) array[7] << 56 | (int64_t) array[6] << 48 | (int64_t) array[5] << 40 |
                        (int64_t) array[4] << 32 | array[3] << 24 | array[2] << 16 | array[1] << 8 | array[0];
        return value;
    }

    double NBTTagBase::readDouble(std::FILE *stream) {
        double value;
        int64_t intValue = readLong(stream);
        memcpy(&intValue, &value, 8);
        return value;
    }

    float NBTTagBase::readFloat(std::FILE *stream) {
        float value;
        int32_t intValue = readInt(stream);
        memcpy(&intValue, &value, 4);
        return value;
    }

    NBTTagBase::~NBTTagBase() = default;

}
