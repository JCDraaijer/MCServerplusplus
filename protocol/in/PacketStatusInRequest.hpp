//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETSTATUSINREQUEST_HPP
#define MCSERVER_PACKETSTATUSINREQUEST_HPP


#include "PacketInBase.hpp"

namespace protocol {
    class PacketStatusInRequest : public PacketInBase {
    public:
        explicit PacketStatusInRequest();

        std::string toString() override;
    };
}

#endif //MCSERVER_PACKETSTATUSINREQUEST_HPP
