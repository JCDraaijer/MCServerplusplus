//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "PacketStatusInRequest.hpp"

namespace protocol {
    PacketStatusInRequest::PacketStatusInRequest() : PacketInBase(STATUS_REQUEST) {

    }

    std::string PacketStatusInRequest::toString() {
        std::ostringstream stringStream;
        stringStream << "Request packet. ID: " << this->getId();
        return stringStream.str();
    }

}
