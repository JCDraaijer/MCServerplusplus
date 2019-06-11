//
// Created by jona on 2019-06-09.
//

#include "PacketBase.hpp"

namespace protocol {

    int PacketBase::getId() {
        return this->id;
    }

    PacketBase::PacketBase(int id) : id(id) {

    }
}