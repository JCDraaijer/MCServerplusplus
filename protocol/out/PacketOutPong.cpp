//
// Created by jona on 2019-06-10.
//

#include "PacketOutPong.hpp"
#include "../util/Util.hpp"

namespace protocol {
    PacketOutPong::PacketOutPong(int64_t value) : PacketOutBase(1, PONG), value(value) {
    }

    std::string PacketOutPong::toString() {
        return PacketOutBase::toString();
    }

    int64_t PacketOutPong::getValue() {
        return value;
    }

    void PacketOutPong::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeLong(getValue());
    }
}
