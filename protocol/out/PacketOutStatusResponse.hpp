//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETOUTSTATUSRESPONSE_HPP
#define MCSERVER_PACKETOUTSTATUSRESPONSE_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutStatusResponse : public PacketOutBase {
    private:
        std::string jsonResponse;
    public:
        explicit PacketOutStatusResponse(std::string);

        std::string toString() override;

        std::string getJsonResponse();

        ~PacketOutStatusResponse() override;

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETOUTSTATUSRESPONSE_HPP
