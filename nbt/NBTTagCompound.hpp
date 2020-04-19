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

#ifndef MCSERVER_NBTTAGCOMPOUND_HPP
#define MCSERVER_NBTTAGCOMPOUND_HPP

#include "NBTTagBase.hpp"
#include <string>
#include <list>

namespace nbt {
    class NBTTagCompound : public NBTTagBase {

    public:
        explicit NBTTagCompound();

        NBTTagBase *get(const std::string& name);

        bool remove(const std::string& name, bool del);

        void add(NBTTagBase *toAdd);

        void parsePayload(std::FILE *stream, bool named) override;

        ~NBTTagCompound() override;

        void write(std::FILE *stream, bool named) override;

        bool contains(const std::string& nameToFind);

        std::list<NBTTagBase *> elements;
    };
}


#endif //MCSERVER_NBTTAGCOMPOUND_HPP
