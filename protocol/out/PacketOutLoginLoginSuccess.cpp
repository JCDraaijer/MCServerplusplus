//
// Created by jona on 2019-06-11.
//

#include "PacketOutLoginLoginSuccess.hpp"

namespace protocol {

    PacketOutLoginLoginSuccess::PacketOutLoginLoginSuccess(const server::UUID& uuid, std::string &username) :
            PacketOutBase(LOGIN_SUCCESS), uuid(uuid), username(username) {

    }

    server::UUID &PacketOutLoginLoginSuccess::getUuid() {
        return uuid;
    }

    void PacketOutLoginLoginSuccess::setUuid(const server::UUID &newUuid) {
        this->uuid = newUuid;
    }

    std::string &PacketOutLoginLoginSuccess::getUsername() {
        return username;
    }

    void PacketOutLoginLoginSuccess::setUsername(const std::string &newUsername) {
        PacketOutLoginLoginSuccess::username = newUsername;
    }

    void PacketOutLoginLoginSuccess::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeString(uuid.toString());
        packetSerializer->writeString(getUsername());
    }
}