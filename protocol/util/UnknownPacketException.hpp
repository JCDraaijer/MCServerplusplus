//
// Created by jona on 2019-06-14.
//

#ifndef MCSERVER_UNKNOWNPACKETEXCEPTION_HPP
#define MCSERVER_UNKNOWNPACKETEXCEPTION_HPP

#include <bits/exception.h>
#include "../../network/State.hpp"

namespace protocol {
    class UnknownPacketException : public std::exception {
    private:
        char *whatValue[256];
    public:
        explicit UnknownPacketException(uint32_t packetNumber, network::State state, uint32_t length);

        const char *
        what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;
    };
}


#endif //MCSERVER_UNKNOWNPACKETEXCEPTION_HPP
