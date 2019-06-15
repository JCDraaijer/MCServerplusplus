//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "PacketInRequest.hpp"

namespace protocol {
    PacketInRequest::PacketInRequest() : PacketInBase(0, STATUS_REQUEST) {

    }

    std::string PacketInRequest::toString() {
        std::ostringstream stringStream;
        stringStream << "Request packet. ID: " << this->getId();
        return stringStream.str();
    }

}
