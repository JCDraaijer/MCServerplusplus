//
// Created by jona on 2019-06-25.
//

#include "NBTTagString.hpp"
#include <zlib.h>

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
        char theString[length + 1];
        theString[length] = '\0';
        std::fread(&theString, length, 1, stream);
        value = std::string(theString);
    }

    void NBTTagString::write(std::FILE *stream, bool named) {

    }
}