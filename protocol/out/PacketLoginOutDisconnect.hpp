//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETLOGINOUTDISCONNECT_HPP
#define MCSERVER_PACKETLOGINOUTDISCONNECT_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketLoginOutDisconnect : public PacketOutBase {
    private:
        //TODO Change this to JSON/Chat
        std::string reason;
    public:
        explicit PacketLoginOutDisconnect(std::string reason);

        const std::string &getReason() const;

        void serialize(PacketSerializer packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETLOGINOUTDISCONNECT_HPP
