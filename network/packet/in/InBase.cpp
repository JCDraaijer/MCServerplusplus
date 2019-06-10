//
// Created by jona on 2019-06-09.
//

#include "InBase.hpp"

namespace packet {
    InBase::InBase(int id, PacketType type) : Base(id), type(type) {
    }
}