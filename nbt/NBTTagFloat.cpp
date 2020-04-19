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

#include "NBTTagFloat.hpp"

namespace nbt {

    NBTTagFloat::NBTTagFloat(std::string name, float value) : NBTTagBase(FLOAT, std::move(name)), value(value) {

    }

    NBTTagFloat::NBTTagFloat(float value) : NBTTagBase(FLOAT), value(value) {

    }

    NBTTagFloat::NBTTagFloat() : NBTTagBase(FLOAT), value(-1) {

    }

    NBTTagFloat::~NBTTagFloat() = default;

    void NBTTagFloat::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        value = readFloat(stream);
    }

    void NBTTagFloat::write(std::FILE *stream, bool named) {

    }

    const float NBTTagFloat::getValue() {
        return value;
    }

    void NBTTagFloat::setValue(float newValue) {
        value = newValue;
    }
}