//
// Created by jona on 2019-06-11.
//

#include "PacketOutLoginSetCompression.hpp"

namespace protocol {

    PacketOutLoginSetCompression::PacketOutLoginSetCompression(int32_t threshold) : PacketOutBase(LOGIN_SET_COMPRESSION),
                                                                          threshold(threshold) {

    }

    int32_t PacketOutLoginSetCompression::getThreshold() {
        return threshold;
    }

    void PacketOutLoginSetCompression::setThreshold(int32_t newThreshold) {
        threshold = newThreshold;
    }

    void PacketOutLoginSetCompression::serialize(PacketSerializer *packetSerializer) {

    }

    PacketOutLoginSetCompression::~PacketOutLoginSetCompression() = default;
}