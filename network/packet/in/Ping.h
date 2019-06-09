//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PING_H
#define MCSERVER_PING_H

#include "InBase.h"

namespace packet {
    namespace in {
        class Ping : InBase {

            void parse(unsigned char *data, int dataLength) override;

            std::string toString() override;
        };
    }
}


#endif //MCSERVER_PING_H
