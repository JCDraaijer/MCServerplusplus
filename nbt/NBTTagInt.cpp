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

#include "NBTTagInt.hpp"

namespace nbt {

    NBTTagInt::NBTTagInt(std::string name, int32_t value) : NBTTagBase(INT, std::move(name)), value(value) {

    }

    NBTTagInt::NBTTagInt(int32_t value) : NBTTagBase(INT), value(value) {

    }

    NBTTagInt::NBTTagInt() : NBTTagBase(INT), value(-1) {

    }

    NBTTagInt::~NBTTagInt() = default;

    void NBTTagInt::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        value = readInt(stream);
    }

    void NBTTagInt::write(std::FILE *stream, bool named) {

    }

    const int32_t NBTTagInt::getValue() {
        return value;
    }

    void NBTTagInt::setValue(int32_t newValue) {
        value = newValue;
    }
}
