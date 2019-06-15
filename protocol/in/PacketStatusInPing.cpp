//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "PacketStatusInPing.hpp"

namespace protocol {

    std::string PacketStatusInPing::toString() {
        std::ostringstream stringStream;
        stringStream << "Ping packet. ID: " << this->getId();
        return stringStream.str();
    }

    PacketStatusInPing::PacketStatusInPing(int64_t value) : PacketInBase(PING), mvalue(value) {
    }

    const int64_t PacketStatusInPing::getValue() {
        return mvalue;
    }

    PacketStatusInPing::PacketStatusInPing(PacketParser *parser) : PacketInBase(PING) {
        parse(parser);
    }

    void PacketStatusInPing::parse(PacketParser *packetParser) {
        mvalue = packetParser->readLong();
    }
}
