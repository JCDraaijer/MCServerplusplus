//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "Ping.h"

namespace packet {
    namespace in {
        void packet::in::Ping::parse(unsigned char *data, int dataLength) {

        }

        std::string Ping::toString() {
            std::ostringstream stringStream;
            stringStream << "Ping packet. ID: " << this->getId();
            return stringStream.str();
        }

    }
}
