//
// Created by jona on 2019-06-11.
//

#include "PacketOutLoginSuccess.hpp"
#include "../util/Util.hpp"

namespace protocol {

    PacketOutLoginSuccess::PacketOutLoginSuccess(server::UUID uuid, std::string &username) : PacketOutBase(0x02,
                                                                                                           LOGIN_SUCCESS),
                                                                                             uuid(uuid), username(
                    std::move(username)) {

    }

    server::UUID &PacketOutLoginSuccess::getUuid() {
        return uuid;
    }

    void PacketOutLoginSuccess::setUuid(const server::UUID &newUuid) {
        this->uuid = newUuid;
    }

    std::string &PacketOutLoginSuccess::getUsername() {
        return username;
    }

    void PacketOutLoginSuccess::setUsername(const std::string &newUsername) {
        PacketOutLoginSuccess::username = newUsername;
    }

    void PacketOutLoginSuccess::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeString(uuid.toString());
        packetSerializer->writeString(getUsername());
    }
}