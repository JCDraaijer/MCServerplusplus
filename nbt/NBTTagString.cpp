//
// Created by jona on 2019-06-25.
//

#include "NBTTagString.hpp"

namespace nbt {

    NBTTagString::NBTTagString() : NBTTagBase(STRING), value("") {

    }

    NBTTagString::NBTTagString(std::string value) : NBTTagBase(STRING), value(std::move(value)) {

    }

    NBTTagString::NBTTagString(std::string name, std::string value) : NBTTagBase(STRING, std::move(name)),
                                                                      value(std::move(value)) {

    }

    NBTTagString::~NBTTagString() = default;

    const std::string NBTTagString::getString() {
        return value;
    }

    void NBTTagString::setString(std::string newValue) {
        value = std::move(newValue);
    }


    void NBTTagString::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        uint16_t length = readShort(stream);
        value = std::string();
        value.reserve(length);
        std::fread(&value, 1, length, stream);
    }

    void NBTTagString::write(std::FILE *stream, bool named) {

    }
}