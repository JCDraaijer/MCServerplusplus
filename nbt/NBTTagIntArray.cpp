//
// Created by jona on 2019-06-25.
//

#include "NBTTagIntArray.hpp"

namespace nbt {

    NBTTagIntArray::~NBTTagIntArray() = default;

    void NBTTagIntArray::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        int32_t length = readInt(stream);
        elements = std::list<int32_t>(length);
        for (int i = 0; i < length; i++) {
            elements.push_back(readInt(stream));
        }
    }

    void NBTTagIntArray::write(std::FILE *stream, bool named) {

    }

    NBTTagIntArray::NBTTagIntArray() : NBTTagBase(INT_ARRAY) {

    }

    NBTTagIntArray::NBTTagIntArray(std::string name) : NBTTagBase(INT_ARRAY, std::move(name)) {

    }
}