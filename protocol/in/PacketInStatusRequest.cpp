//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "PacketInStatusRequest.hpp"

namespace protocol {
    PacketInStatusRequest::PacketInStatusRequest() : PacketInBase(STATUS_REQUEST) {

    }

    std::string PacketInStatusRequest::toString() {
        std::ostringstream stringStream;
        stringStream << "Request packet. ID: " << this->getId();
        return stringStream.str();
    }

    PacketInStatusRequest::PacketInStatusRequest(PacketParser *parser) : PacketInBase(STATUS_REQUEST) {

    }

    void PacketInStatusRequest::parse(PacketParser *packetParser) {

    }

}
