//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "PacketInStatusPing.hpp"

namespace protocol {

    std::string PacketInStatusPing::toString() {
        std::ostringstream stringStream;
        stringStream << "Ping packet. ID: " << this->getId();
        return stringStream.str();
    }

    PacketInStatusPing::PacketInStatusPing(int64_t value) : PacketInBase(PING), mvalue(value) {
    }

    const int64_t PacketInStatusPing::getValue() {
        return mvalue;
    }

    PacketInStatusPing::PacketInStatusPing(PacketParser *parser) : PacketInBase(PING) {
        parse(parser);
    }

    void PacketInStatusPing::parse(PacketParser *packetParser) {
        mvalue = packetParser->readLong();
    }
}
