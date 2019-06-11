//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETOUTRESPONSE_HPP
#define MCSERVER_PACKETOUTRESPONSE_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutResponse : public PacketOutBase {
    private:
        std::string jsonResponse;
    public:
        explicit PacketOutResponse(std::string);

        std::string toString() override;

        std::string getJsonResponse();
    };
}


#endif //MCSERVER_PACKETOUTRESPONSE_HPP
