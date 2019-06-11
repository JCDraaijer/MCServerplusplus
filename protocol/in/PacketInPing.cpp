//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "PacketInPing.hpp"
#include "../../network/util/Util.hpp"

namespace protocol {

    std::string PacketInPing::toString() {
        std::ostringstream stringStream;
        stringStream << "Ping packet. ID: " << this->getId();
        return stringStream.str();
    }

    PacketInPing::PacketInPing(int64_t value) : PacketInBase(1, PING), mvalue(value) {
    }

    const int64_t PacketInPing::getValue() {
        return mvalue;
    }
}
