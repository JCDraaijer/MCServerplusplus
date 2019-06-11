//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETINREQUEST_HPP
#define MCSERVER_PACKETINREQUEST_HPP


#include "PacketInBase.hpp"

namespace protocol {
    class PacketInRequest : public PacketInBase {
    public:
        explicit PacketInRequest();

        std::string toString() override;
    };
}

#endif //MCSERVER_PACKETINREQUEST_HPP
