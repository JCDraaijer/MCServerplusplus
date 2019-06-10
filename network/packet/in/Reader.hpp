//
// Created by jona on 2019-06-10.
//

#ifndef MCSERVER_READER_HPP
#define MCSERVER_READER_HPP

#include "InBase.hpp"

namespace packet {
    class Reader {
    public:
        InBase *readPacket(unsigned char *, int);
    };
}


#endif //MCSERVER_READER_HPP
