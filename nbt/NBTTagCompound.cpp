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

#include "NBTTagCompound.hpp"
#include "NBTTagByte.hpp"
#include "NBTTagShort.hpp"
#include "NBTTagInt.hpp"
#include "NBTTagLong.hpp"
#include "NBTTagFloat.hpp"
#include "NBTTagDouble.hpp"
#include "NBTTagByteArray.hpp"
#include "NBTTagString.hpp"
#include "NBTTagList.hpp"

namespace nbt {
    NBTTagCompound::NBTTagCompound() : NBTTagBase(COMPOUND) {

    }

    NBTTagCompound::~NBTTagCompound() {
        for (auto &nbtTag : elements) {
            delete nbtTag;
        }
    }

    NBTTagBase *NBTTagCompound::get(const std::string &nameToGet) {
        for (auto &nbtTag : elements) {
            if (nbtTag->hasName() && nbtTag->getName() == nameToGet) {
                return nbtTag;
            }
        }
        return nullptr;
    }

    bool NBTTagCompound::remove(const std::string &nameToRemove, bool del) {
        for (auto &nbtTag : elements) {
            if (nbtTag->hasName() && nbtTag->getName() == nameToRemove) {
                elements.remove(nbtTag);
                if (del) {
                    delete nbtTag;
                }
                return true;
            }
        }
        return false;
    }

    void NBTTagCompound::add(NBTTagBase *toAdd) {
        elements.push_back(toAdd);
    }

    bool NBTTagCompound::contains(const std::string &nameToFind) {
        return get(nameToFind) != nullptr;
    }

    void NBTTagCompound::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        elements = std::list<NBTTagBase *>();
        uint8_t typeId;
        do {
            std::fread(&typeId, 1, 1, stream);
            NBTTagBase *value;
            switch (typeId) {
                case END:
                    return;
                case BYTE:
                    value = new NBTTagByte();
                    break;
                case SHORT:
                    value = new NBTTagShort();
                    break;
                case INT:
                    value = new NBTTagInt();
                    break;
                case LONG:
                    value = new NBTTagLong();
                    break;
                case FLOAT:
                    value = new NBTTagFloat();
                    break;
                case DOUBLE:
                    value = new NBTTagDouble();
                    break;
                case BYTE_ARRAY:
                    value = new NBTTagByteArray();
                    break;
                case STRING:
                    value = new NBTTagString();
                    break;
                case LIST:
                    value = new NBTTagList();
                    break;
                case COMPOUND:
                    value = new NBTTagCompound();
                    break;
                case INT_ARRAY:
                    value = new NBTTagByte();
                    break;
                case LONG_ARRAY:
                    value = new NBTTagByte();
                    break;
                default:
                    return;
            }
            value->parsePayload(stream, true);
            elements.push_back(value);
        } while (typeId != END);
    }

    void NBTTagCompound::write(std::FILE *stream, bool named) {

    }
}
