//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETSTATUSOUTRESPONSE_HPP
#define MCSERVER_PACKETSTATUSOUTRESPONSE_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketStatusOutResponse : public PacketOutBase {
    private:
        std::string jsonResponse;
    public:
        explicit PacketStatusOutResponse(std::string);

        std::string toString() override;

        std::string getJsonResponse();

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETSTATUSOUTRESPONSE_HPP
