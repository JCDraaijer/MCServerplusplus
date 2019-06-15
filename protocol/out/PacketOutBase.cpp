//
// Created by jona on 2019-06-09.
//

#include "PacketOutBase.hpp"

namespace protocol {
    PacketOutBase::PacketOutBase(OutPacketType type) : PacketBase(type), type(type) {

    }

    const OutPacketType PacketOutBase::getType() {
        return this->type;
    }

    std::string PacketOutBase::toString() {
        return std::__cxx11::string();
    }

}
