//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETOUTLOGINLOGINSUCCESS_HPP
#define MCSERVER_PACKETOUTLOGINLOGINSUCCESS_HPP

#include "PacketOutBase.hpp"
#include "../../server/UUID.hpp"

namespace protocol {
    class PacketLoginOutLoginSuccess : public PacketOutBase {
    private:
        server::UUID uuid;
        std::string username;
    public:
        PacketLoginOutLoginSuccess(server::UUID uuid, std::string &username);

        server::UUID &getUuid();

        void setUuid(const server::UUID &uuid);

        std::string &getUsername();

        void setUsername(const std::string &username);

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETOUTLOGINLOGINSUCCESS_HPP
