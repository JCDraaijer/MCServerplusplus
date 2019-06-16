//
// Created by jona on 2019-06-16.
//

#ifndef MCSERVER_PACKETINLEGACYPINGREQUEST_HPP
#define MCSERVER_PACKETINLEGACYPINGREQUEST_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketInLegacyPingRequest : public PacketInBase{
    public:
        explicit PacketInLegacyPingRequest();

        std::string toString() override;

        void parse(PacketParser *packetParser) override;
    };
}


#endif //MCSERVER_PACKETINLEGACYPINGREQUEST_HPP
