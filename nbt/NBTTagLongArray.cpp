//
// Created by jona on 2019-06-25.
//

#include "NBTTagLongArray.hpp"

namespace nbt {
    NBTTagLongArray::~NBTTagLongArray() = default;

    void NBTTagLongArray::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        int32_t length = readInt(stream);
        elements = std::list<int32_t>(length);
        for (int i = 0; i < length; i++) {
            elements.push_back(readLong(stream));
        }
    }

    void NBTTagLongArray::write(std::FILE *stream, bool named) {

    }

    NBTTagLongArray::NBTTagLongArray() : NBTTagBase(LONG_ARRAY) {

    }

    NBTTagLongArray::NBTTagLongArray(std::string name) : NBTTagBase(LONG_ARRAY, std::move(name)) {

    }
}