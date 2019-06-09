//
// Created by jona on 2019-06-09.
//

#include "InBase.h"

namespace packet {
    namespace in {
        InBase::InBase(int id, PacketType type) : Base(id), type(type) {
        }
    }
}