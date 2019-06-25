//
// Created by jona on 2019-06-25.
//

#include "NBTTagInt.hpp"

namespace nbt {

    NBTTagInt::NBTTagInt(std::string name, int32_t value) : NBTTagBase(INT, std::move(name)), value(value) {

    }

    NBTTagInt::NBTTagInt(int32_t value) : NBTTagBase(INT), value(value) {

    }

    NBTTagInt::NBTTagInt() : NBTTagBase(INT), value(-1) {

    }

    NBTTagInt::~NBTTagInt() = default;

    void NBTTagInt::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        std::fread(&value, 4, 1, stream);
    }

    void NBTTagInt::write(std::FILE *stream, bool named) {

    }

    const int32_t NBTTagInt::getValue() {
        return value;
    }

    void NBTTagInt::setValue(int32_t newValue) {
        value = newValue;
    }
}
