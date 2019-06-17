//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETOUTLOGINDISCONNECT_HPP
#define MCSERVER_PACKETOUTLOGINDISCONNECT_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutLoginDisconnect : public PacketOutBase {
    private:
        //TODO Change this to JSON/Chat
        std::string reason;
    public:
        explicit PacketOutLoginDisconnect(std::string reason);

        ~PacketOutLoginDisconnect() override;

        const std::string &getReason() const;

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETOUTLOGINDISCONNECT_HPP
