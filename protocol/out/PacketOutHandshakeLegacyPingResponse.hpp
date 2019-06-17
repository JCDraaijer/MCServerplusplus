//
// Created by jona on 2019-06-16.
//

#ifndef MCSERVER_PACKETOUTHANDSHAKELEGACYPINGRESPONSE_HPP
#define MCSERVER_PACKETOUTHANDSHAKELEGACYPINGRESPONSE_HPP


#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutHandshakeLegacyPingResponse : public PacketOutBase {
    public:
        explicit PacketOutHandshakeLegacyPingResponse();

        ~PacketOutHandshakeLegacyPingResponse() override;

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETOUTHANDSHAKELEGACYPINGRESPONSE_HPP
