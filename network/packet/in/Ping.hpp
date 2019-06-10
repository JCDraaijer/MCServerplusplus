//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PING_HPP
#define MCSERVER_PING_HPP

#include "InBase.hpp"

namespace packet {
    class Ping : InBase {

        void parse(unsigned char *data, int dataLength) override;

        std::string toString() override;
    };
}


#endif //MCSERVER_PING_HPP
