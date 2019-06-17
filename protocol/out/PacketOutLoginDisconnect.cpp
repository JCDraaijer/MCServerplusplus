#include <utility>

//
// Created by jona on 2019-06-11.
//

#include "PacketOutLoginDisconnect.hpp"

namespace protocol {
    PacketOutLoginDisconnect::PacketOutLoginDisconnect(std::string reason) : PacketOutBase(LOGIN_DISCONNECT),
                                                                             reason(std::move(reason)) {

    }

    const std::string &PacketOutLoginDisconnect::getReason() const {
        return reason;
    }

    void PacketOutLoginDisconnect::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeString(getReason());
    }

    PacketOutLoginDisconnect::~PacketOutLoginDisconnect() {

    }

}