//
// Created by jona on 2019-06-16.
//

#include "PacketInLegacyPingRequest.hpp"

namespace protocol {
    std::string protocol::PacketInLegacyPingRequest::toString() {
        return std::string();
    }

    void protocol::PacketInLegacyPingRequest::parse(protocol::PacketParser *packetParser) {

    }

    PacketInLegacyPingRequest::PacketInLegacyPingRequest() : PacketInBase(LEGACY_PING){

    }
}
