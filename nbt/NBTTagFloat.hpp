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


#ifndef MCSERVER_NBTTAGFLOAT_HPP
#define MCSERVER_NBTTAGFLOAT_HPP

#include "NBTTagBase.hpp"

namespace nbt {
    class NBTTagFloat : public NBTTagBase {
    private:
        float value;
    public:
        explicit NBTTagFloat(std::string name, float value);

        explicit NBTTagFloat(float value);

        explicit NBTTagFloat();

        ~NBTTagFloat() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;

        const float getValue();

        void setValue(float newValue);
    };
}

#endif //MCSERVER_NBTTAGFLOAT_HPP
