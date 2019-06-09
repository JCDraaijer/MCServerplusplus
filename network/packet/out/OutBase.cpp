//
// Created by jona on 2019-06-09.
//

#include "OutBase.h"

namespace packet {
    namespace out {
        OutBase::OutBase(int id, packet::out::PacketType type) : Base(id), type(type) {

        }

        PacketType OutBase::getType() {
            return this->type;
        }
    }
}
