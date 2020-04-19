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


#ifndef MCSERVER_NBTTAGINT_HPP
#define MCSERVER_NBTTAGINT_HPP

#include "NBTTagBase.hpp"

namespace nbt {
    class NBTTagInt : public NBTTagBase {
    private:
        int32_t value;
    public:
        explicit NBTTagInt(std::string name, int32_t value);

        explicit NBTTagInt(int32_t value);

        explicit NBTTagInt();

        ~NBTTagInt() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;

        const int32_t getValue();

        void setValue(int32_t newValue);
    };
}


#endif //MCSERVER_NBTTAGINT_HPP
