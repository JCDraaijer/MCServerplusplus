//
// Created by jona on 2019-06-25.
//

#include "NBTTagShort.hpp"

namespace nbt {

    NBTTagShort::NBTTagShort(std::string name, int16_t value) : NBTTagBase(SHORT, std::move(name)), value(value) {

    }

    NBTTagShort::NBTTagShort(int16_t value) : NBTTagBase(SHORT), value(value) {

    }

    NBTTagShort::NBTTagShort() : NBTTagBase(BYTE), value(-1) {

    }

    NBTTagShort::~NBTTagShort() = default;

    void NBTTagShort::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        value = readShort(stream);
    }

    void NBTTagShort::write(std::FILE *stream, bool named) {

    }

    const int16_t NBTTagShort::getValue() {
        return value;
    }

    void NBTTagShort::setValue(int16_t newValue) {
        value = newValue;
    }


}