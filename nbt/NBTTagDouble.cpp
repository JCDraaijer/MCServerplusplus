//
// Created by jona on 2019-06-25.
//

#include "NBTTagDouble.hpp"

namespace nbt {

    NBTTagDouble::NBTTagDouble(std::string name, double value) : NBTTagBase(DOUBLE, std::move(name)), value(value) {

    }

    NBTTagDouble::NBTTagDouble(double value) : NBTTagBase(DOUBLE), value(value) {

    }

    NBTTagDouble::NBTTagDouble() : NBTTagBase(DOUBLE), value(-1) {

    }

    NBTTagDouble::~NBTTagDouble() = default;

    void NBTTagDouble::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        std::fread(&value, 8, 1, stream);
    }

    void NBTTagDouble::write(std::FILE *stream, bool named) {

    }

    const double NBTTagDouble::getValue() {
        return value;
    }

    void NBTTagDouble::setValue(double newValue) {
        value = newValue;
    }
}