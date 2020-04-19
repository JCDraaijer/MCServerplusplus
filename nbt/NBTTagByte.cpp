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
#include "NBTTagByte.hpp"

namespace nbt {

    NBTTagByte::~NBTTagByte() = default;

    void NBTTagByte::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        std::fread(&value, 1, 1, stream);
    }

    void NBTTagByte::write(std::FILE *stream, bool named) {

    }

    NBTTagByte::NBTTagByte(std::string name, uint8_t value) : NBTTagBase(BYTE, std::move(name)), value(value) {

    }

    NBTTagByte::NBTTagByte(uint8_t value) : NBTTagBase(BYTE), value(value) {

    }

    NBTTagByte::NBTTagByte() : NBTTagBase(BYTE), value(-1) {

    }

    const int8_t NBTTagByte::getValue() {
        return value;
    }

    void NBTTagByte::setValue(int8_t newValue) {
        value = newValue;
    }
}