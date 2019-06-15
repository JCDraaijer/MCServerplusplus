#include <utility>
#include <sstream>

//
// Created by jona on 2019-06-11.
//

#include "PacketInLoginStart.hpp"

namespace protocol {
    PacketInLoginStart::PacketInLoginStart(std::string name) : PacketInBase(LOGIN_START), name(std::move(name)) {

    }

    std::string PacketInLoginStart::getName() {
        return name;
    }

    std::string PacketInLoginStart::toString() {
        std::ostringstream stringStream;
        stringStream << "Login Start packet. ID: " << this->getId() << ". Name: " << getName();
        return stringStream.str();
    }

    PacketInLoginStart::PacketInLoginStart(PacketParser *parser) : PacketInBase(LOGIN_START) {
        parse(parser);
    }

    void PacketInLoginStart::parse(PacketParser *packetParser) {
        name = packetParser->readString();
    }
}
