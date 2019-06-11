#include <utility>
#include <sstream>

//
// Created by jona on 2019-06-11.
//

#include "PacketInLoginStart.hpp"

namespace protocol {
    PacketInLoginStart::PacketInLoginStart(std::string name) : PacketInBase(0x00, LOGIN_START), name(std::move(name)) {

    }

    std::string PacketInLoginStart::getName() {
        return name;
    }

    std::string PacketInLoginStart::toString() {
        std::ostringstream stringStream;
        stringStream << "Login Start packet. ID: " << this->getId() << ". Name: " << getName() << std::endl;
        return stringStream.str();
    }
}
