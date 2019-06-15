//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETINSTATUSREQUEST_HPP
#define MCSERVER_PACKETINSTATUSREQUEST_HPP


#include "PacketInBase.hpp"

namespace protocol {
    class PacketInStatusRequest : public PacketInBase {
    public:
        explicit PacketInStatusRequest();

        std::string toString() override;

        explicit PacketInStatusRequest(PacketParser *parser);

        void parse(PacketParser *packetParser) override;
    };
}

#endif //MCSERVER_PACKETINSTATUSREQUEST_HPP
