#include <utility>

//
// Created by jona on 2019-06-25.
//

#include "NBTTagByte.hpp"

namespace nbt {

    NBTTagByte::~NBTTagByte() = default;

    void NBTTagByte::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        std::fread(&value, 1, 1, stream);
    }

    void NBTTagByte::write(std::FILE *stream, bool named) {

    }

    NBTTagByte::NBTTagByte(std::string name, uint8_t value) : NBTTagBase(BYTE, std::move(name)), value(value) {

    }

    NBTTagByte::NBTTagByte(uint8_t value) : NBTTagBase(BYTE), value(value) {

    }

    NBTTagByte::NBTTagByte() : NBTTagBase(BYTE), value(-1) {

    }

    const int8_t NBTTagByte::getValue() {
        return value;
    }

    void NBTTagByte::setValue(int8_t newValue) {
        value = newValue;
    }
}