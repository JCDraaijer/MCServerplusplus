//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETOUTDISCONNECT_HPP
#define MCSERVER_PACKETOUTDISCONNECT_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutDisconnect : public PacketOutBase {
    private:
        //TODO Change this to JSON/Chat
        std::string reason;
    public:
        explicit PacketOutDisconnect(std::string reason);

        const std::string &getReason() const;
    };
}


#endif //MCSERVER_PACKETOUTDISCONNECT_HPP
