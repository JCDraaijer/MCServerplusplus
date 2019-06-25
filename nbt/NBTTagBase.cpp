//
// Created by jona on 2019-06-19.
//

#include <vector>
#include "NBTTagBase.hpp"

namespace nbt {

    NBTTagBase::NBTTagBase(NBTTag typeId) : typeId(typeId), name("") {
    }

    NBTTagBase::NBTTagBase(NBTTag typeId, std::string name) : typeId(typeId), name(std::move(name)) {
    }

    bool NBTTagBase::hasName() {
        return !name.empty();
    }

    std::string NBTTagBase::getName() {
        return name;
    }

    void NBTTagBase::parseName(FILE *stream) {
        uint16_t nameLength;
        std::fread(&nameLength, 2, 1, stream);
        std::vector<char> nameVector(nameLength);
        std::fread(&nameVector[0], sizeof(nameVector[0]), nameVector.size(), stream);
        name = std::string(nameVector.begin(), nameVector.end());
    }

}
