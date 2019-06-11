//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETOUTLOGINSUCCESS_HPP
#define MCSERVER_PACKETOUTLOGINSUCCESS_HPP

#include "PacketOutBase.hpp"
#include "../../server/UUID.hpp"

namespace protocol {
    class PacketOutLoginSuccess : public PacketOutBase {
    private:
        server::UUID uuid;
        std::string username;
    public:
        PacketOutLoginSuccess(server::UUID uuid, std::string &username);

        server::UUID &getUuid();

        void setUuid(const server::UUID &uuid);

        std::string &getUsername();

        void setUsername(const std::string &username);
    };
}


#endif //MCSERVER_PACKETOUTLOGINSUCCESS_HPP
