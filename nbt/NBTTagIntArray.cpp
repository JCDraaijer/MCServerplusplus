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


#include "NBTTagIntArray.hpp"

namespace nbt {

    NBTTagIntArray::~NBTTagIntArray() = default;

    void NBTTagIntArray::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        int32_t length = readInt(stream);
        elements = std::list<int32_t>(length);
        for (int i = 0; i < length; i++) {
            elements.push_back(readInt(stream));
        }
    }

    void NBTTagIntArray::write(std::FILE *stream, bool named) {

    }

    NBTTagIntArray::NBTTagIntArray() : NBTTagBase(INT_ARRAY) {

    }

    NBTTagIntArray::NBTTagIntArray(std::string name) : NBTTagBase(INT_ARRAY, std::move(name)) {

    }
}