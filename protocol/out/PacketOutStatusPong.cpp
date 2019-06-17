//
// Created by jona on 2019-06-10.
//

#include "PacketOutStatusPong.hpp"

namespace protocol {
    PacketOutStatusPong::PacketOutStatusPong(int64_t value) : PacketOutBase(STATUS_PONG), value(value) {
    }

    std::string PacketOutStatusPong::toString() {
        return PacketOutBase::toString();
    }

    int64_t PacketOutStatusPong::getValue() {
        return value;
    }

    void PacketOutStatusPong::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeLong(getValue());
    }

    PacketOutStatusPong::~PacketOutStatusPong() = default;
}
