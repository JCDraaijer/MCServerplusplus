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


#include <utility>
#include "NBTTagByteArray.hpp"

namespace nbt {

    NBTTagByteArray::~NBTTagByteArray() = default;

    void NBTTagByteArray::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        int32_t length = readInt(stream);
        bytes = std::list<int8_t>(length);
        int8_t value;
        for (int i = 0; i < length; i++) {
            std::fread(&value, 1, 1, stream);
            bytes.push_back(value);
        }
    }

    void NBTTagByteArray::write(std::FILE *stream, bool named) {
    }

    NBTTagByteArray::NBTTagByteArray() : NBTTagBase(BYTE_ARRAY) {

    }

    NBTTagByteArray::NBTTagByteArray(std::list<int8_t> bytes) : NBTTagBase(BYTE_ARRAY), bytes(std::move(bytes)) {

    }

    NBTTagByteArray::NBTTagByteArray(std::string name, std::list<int8_t> bytes) : NBTTagBase(BYTE_ARRAY,
                                                                                             std::move(name)),
                                                                                  bytes(std::move(bytes)) {

    }

    void NBTTagByteArray::insert(int8_t value, uint32_t position) {
        auto iterator = bytes.begin();
        for (int i = 0; i < position - 1; i++) {
            iterator++;
        }
        bytes.insert(iterator, value);
    }

    void NBTTagByteArray::add(int8_t value) {
        bytes.push_back(value);
    }

    bool NBTTagByteArray::remove(uint32_t index) {
        auto iterator = bytes.begin();
        for (int i = 0; i < index; i++) {
            iterator++;
        }
        bytes.erase(iterator);
        return false;
    }
}