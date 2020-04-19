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


#include "NBTTagLong.hpp"

namespace nbt {

    NBTTagLong::NBTTagLong(std::string name, int64_t value) : NBTTagBase(LONG, std::move(name)), value(value) {

    }

    NBTTagLong::NBTTagLong(int64_t value) : NBTTagBase(LONG), value(value) {

    }

    NBTTagLong::NBTTagLong() : NBTTagBase(LONG), value(-1) {

    }

    NBTTagLong::~NBTTagLong() = default;

    void NBTTagLong::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        value = readLong(stream);
    }

    void NBTTagLong::write(std::FILE *stream, bool named) {

    }

    const int64_t NBTTagLong::getValue() {
        return value;
    }

    void NBTTagLong::setValue(int64_t newValue) {
        value = newValue;
    }
}