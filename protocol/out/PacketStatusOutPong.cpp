//
// Created by jona on 2019-06-10.
//

#include "PacketStatusOutPong.hpp"
#include "../util/Util.hpp"

namespace protocol {
    PacketStatusOutPong::PacketStatusOutPong(int64_t value) : PacketOutBase(STATUS_PONG), value(value) {
    }

    std::string PacketStatusOutPong::toString() {
        return PacketOutBase::toString();
    }

    int64_t PacketStatusOutPong::getValue() {
        return value;
    }

    void PacketStatusOutPong::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeLong(getValue());
    }
}
