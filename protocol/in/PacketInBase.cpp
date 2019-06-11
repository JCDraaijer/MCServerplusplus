//
// Created by jona on 2019-06-09.
//

#include "PacketInBase.hpp"

namespace protocol {
    PacketInBase::PacketInBase(int id, InPacketType type) : PacketBase(id), type(type) {
    }

    InPacketType PacketInBase::getType() {
        return this->type;
    }
}