//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETPLAYOUTDISCONNECT_HPP
#define MCSERVER_PACKETPLAYOUTDISCONNECT_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketPlayOutDisconnect : public PacketOutBase {
    private:
        //TODO Change this to JSON/Chat
        std::string reason;
    public:
        explicit PacketPlayOutDisconnect(std::string reason);

        const std::string &getReason() const;
    };
}


#endif //MCSERVER_PACKETPLAYOUTDISCONNECT_HPP
