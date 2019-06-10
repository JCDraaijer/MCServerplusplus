//
// Created by jona on 2019-06-09.
//

#include "OutBase.hpp"

namespace packet {
    OutBase::OutBase(int id, packet::PacketType type) : Base(id), type(type) {

    }

    PacketType OutBase::getType() {
        return this->type;
    }
}
