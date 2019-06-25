//
// Created by jona on 2019-06-25.
//

#include "NBTTagFloat.hpp"

namespace nbt {

    NBTTagFloat::NBTTagFloat(std::string name, float value) : NBTTagBase(FLOAT, std::move(name)), value(value) {

    }

    NBTTagFloat::NBTTagFloat(float value) : NBTTagBase(FLOAT), value(value) {

    }

    NBTTagFloat::NBTTagFloat() : NBTTagBase(FLOAT), value(-1) {

    }

    NBTTagFloat::~NBTTagFloat() = default;

    void NBTTagFloat::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        std::fread(&value, 4, 1, stream);
    }

    void NBTTagFloat::write(std::FILE *stream, bool named) {

    }

    const float NBTTagFloat::getValue() {
        return value;
    }

    void NBTTagFloat::setValue(float newValue) {
        value = newValue;
    }
}