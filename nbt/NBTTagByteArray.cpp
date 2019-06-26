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
        bytes = std::list<int8_t>(length);
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

    NBTTagByteArray::NBTTagByteArray(std::list<int8_t> bytes) : NBTTagBase(BYTE_ARRAY), bytes(std::move(bytes)) {

    }

    NBTTagByteArray::NBTTagByteArray(std::string name, std::list<int8_t> bytes) : NBTTagBase(BYTE_ARRAY,
                                                                                             std::move(name)),
                                                                                  bytes(std::move(bytes)) {

    }

    void NBTTagByteArray::insert(int8_t value, uint32_t position) {
        auto iterator = bytes.begin();
        for (int i = 0; i < position - 1; i++) {
            iterator++;
        }
        bytes.insert(iterator, value);
    }

    void NBTTagByteArray::add(int8_t value) {
        bytes.push_back(value);
    }

    bool NBTTagByteArray::remove(uint32_t index) {
        auto iterator = bytes.begin();
        for (int i = 0; i < index; i++) {
            iterator++;
        }
        bytes.erase(iterator);
        return false;
    }
}