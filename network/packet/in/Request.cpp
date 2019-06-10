//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "Request.hpp"

namespace packet {
    Request::Request() : InBase(0, REQUEST) {

    }

    std::string Request::toString() {
        std::ostringstream stringStream;
        stringStream << "Request packet. ID: " << this->getId();
        return stringStream.str();
    }

    void Request::parse(unsigned char *data, int dataLength) {
    }
}
