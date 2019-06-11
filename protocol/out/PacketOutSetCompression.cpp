//
// Created by jona on 2019-06-11.
//

#include "PacketOutSetCompression.hpp"

namespace protocol {

    PacketOutSetCompression::PacketOutSetCompression(int32_t threshold) : PacketOutBase(0x03, SET_COMPRESSION),
                                                                          threshold(threshold) {

    }

    int32_t PacketOutSetCompression::getThreshold() {
        return threshold;
    }

    void PacketOutSetCompression::setThreshold(int32_t newThreshold) {
        threshold = newThreshold;
    }
}