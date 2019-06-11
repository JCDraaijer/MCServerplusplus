//
// Created by jona on 2019-06-09.
//

#include "PacketOutBase.hpp"

namespace protocol {
    PacketOutBase::PacketOutBase(int id, OutPacketType type) : PacketBase(id), type(type) {

    }

    const OutPacketType PacketOutBase::getType() {
        return this->type;
    }

    std::string PacketOutBase::toString() {
        return std::__cxx11::string();
    }
}
