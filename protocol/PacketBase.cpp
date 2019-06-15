//
// Created by jona on 2019-06-09.
//

#include "PacketBase.hpp"

namespace protocol {

    uint32_t PacketBase::getId() {
        return this->id;
    }

    PacketBase::PacketBase(uint32_t id) : id(id) {

    }

    std::string enumToString(OutPacketType type) {
        return enumToStrx(type);
    }
}