#include <utility>

//
// Created by jona on 2019-06-25.
//

#include "NBTTagByteArray.hpp"

namespace nbt {

    NBTTagByteArray::~NBTTagByteArray() = default;

    void NBTTagByteArray::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        int32_t length = readInt(stream);
        bytes = std::vector<int8_t>(length);
        int8_t value;
        for (int i = 0; i < length; i++) {
            std::fread(&value, 1, 1, stream);
            bytes.push_back(value);
        }
    }

    void NBTTagByteArray::write(std::FILE *stream, bool named) {
    }

    NBTTagByteArray::NBTTagByteArray() : NBTTagBase(BYTE_ARRAY) {

    }

    NBTTagByteArray::NBTTagByteArray(std::vector<int8_t> bytes) : NBTTagBase(BYTE_ARRAY), bytes(std::move(bytes)) {

    }

    NBTTagByteArray::NBTTagByteArray(std::string name, std::vector<int8_t> bytes) : NBTTagBase(BYTE_ARRAY,
                                                                                               std::move(name)),
                                                                                    bytes(std::move(bytes)) {

    }
}