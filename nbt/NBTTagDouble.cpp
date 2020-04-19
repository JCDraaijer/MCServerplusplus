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

#include "NBTTagDouble.hpp"

namespace nbt {

    NBTTagDouble::NBTTagDouble(std::string name, double value) : NBTTagBase(DOUBLE, std::move(name)), value(value) {

    }

    NBTTagDouble::NBTTagDouble(double value) : NBTTagBase(DOUBLE), value(value) {

    }

    NBTTagDouble::NBTTagDouble() : NBTTagBase(DOUBLE), value(-1) {

    }

    NBTTagDouble::~NBTTagDouble() = default;

    void NBTTagDouble::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        value = readDouble(stream);
    }

    void NBTTagDouble::write(std::FILE *stream, bool named) {

    }

    const double NBTTagDouble::getValue() {
        return value;
    }

    void NBTTagDouble::setValue(double newValue) {
        value = newValue;
    }
}