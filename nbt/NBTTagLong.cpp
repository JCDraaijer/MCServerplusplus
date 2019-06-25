//
// Created by jona on 2019-06-25.
//

#include "NBTTagLong.hpp"

namespace nbt {

    NBTTagLong::NBTTagLong(std::string name, int64_t value) : NBTTagBase(LONG, std::move(name)), value(value) {

    }

    NBTTagLong::NBTTagLong(int64_t value) : NBTTagBase(LONG), value(value) {

    }

    NBTTagLong::NBTTagLong() : NBTTagBase(LONG), value(-1) {

    }

    NBTTagLong::~NBTTagLong() = default;

    void NBTTagLong::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        value = readLong(stream);
    }

    void NBTTagLong::write(std::FILE *stream, bool named) {

    }

    const int64_t NBTTagLong::getValue() {
        return value;
    }

    void NBTTagLong::setValue(int64_t newValue) {
        value = newValue;
    }
}