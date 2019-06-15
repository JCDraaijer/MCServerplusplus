//
// Created by jona on 2019-06-09.
//

#include "PacketInBase.hpp"

namespace protocol {
    PacketInBase::PacketInBase(InPacketType type) : PacketBase(type), type(type) {
    }

    InPacketType PacketInBase::getType() {
        return this->type;
    }
}