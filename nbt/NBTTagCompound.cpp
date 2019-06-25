//
// Created by jona on 2019-06-19.
//

#include "NBTTagCompound.hpp"

namespace nbt {
    NBTTagCompound::NBTTagCompound() : NBTTagBase(COMPOUND) {

    }

    NBTTagCompound::~NBTTagCompound() = default;

    NBTTagBase *NBTTagCompound::get(const std::string &nameToGet) {
        for (auto &nbtTag : nbtTags) {
            if (nbtTag->hasName() && nbtTag->getName() == nameToGet) {
                return nbtTag;
            }
        }
        return nullptr;
    }

    bool NBTTagCompound::remove(const std::string &nameToRemove, bool del) {
        for (auto &nbtTag : nbtTags) {
            if (nbtTag->hasName() && nbtTag->getName() == nameToRemove) {
                nbtTags.remove(nbtTag);
                if (del) {
                    delete nbtTag;
                }
                return true;
            }
        }
        return false;
    }

    void NBTTagCompound::add(NBTTagBase *toAdd) {
        nbtTags.push_back(toAdd);
    }

    bool NBTTagCompound::contains(const std::string &nameToFind) {
        return get(nameToFind) != nullptr;
    }

    void NBTTagCompound::parsePayload(std::FILE *stream, bool named) {

    }

    void NBTTagCompound::write(std::FILE *stream, bool named) {

    }
}
