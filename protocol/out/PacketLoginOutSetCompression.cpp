//
// Created by jona on 2019-06-11.
//

#include "PacketLoginOutSetCompression.hpp"

namespace protocol {

    PacketLoginOutSetCompression::PacketLoginOutSetCompression(int32_t threshold) : PacketOutBase(LOGIN_SET_COMPRESSION),
                                                                          threshold(threshold) {

    }

    int32_t PacketLoginOutSetCompression::getThreshold() {
        return threshold;
    }

    void PacketLoginOutSetCompression::setThreshold(int32_t newThreshold) {
        threshold = newThreshold;
    }

    void PacketLoginOutSetCompression::serialize(PacketSerializer *packetSerializer) {

    }
}