//
// Created by jona on 2019-06-11.
//

#include "PacketLoginOutLoginSuccess.hpp"

namespace protocol {

    PacketLoginOutLoginSuccess::PacketLoginOutLoginSuccess(server::UUID uuid, std::string &username) :
            PacketOutBase(LOGIN_SUCCESS), uuid(uuid), username(std::move(username)) {

    }

    server::UUID &PacketLoginOutLoginSuccess::getUuid() {
        return uuid;
    }

    void PacketLoginOutLoginSuccess::setUuid(const server::UUID &newUuid) {
        this->uuid = newUuid;
    }

    std::string &PacketLoginOutLoginSuccess::getUsername() {
        return username;
    }

    void PacketLoginOutLoginSuccess::setUsername(const std::string &newUsername) {
        PacketLoginOutLoginSuccess::username = newUsername;
    }

    void PacketLoginOutLoginSuccess::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeString(uuid.toString());
        packetSerializer->writeString(getUsername());
    }
}