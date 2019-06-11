#include <utility>

//
// Created by jona on 2019-06-11.
//

#include "PacketPlayOutDisconnect.hpp"

namespace protocol {
    PacketPlayOutDisconnect::PacketPlayOutDisconnect(std::string reason) : PacketOutBase(0x1B, DISCONNECT),
                                                                   reason(std::move(reason)) {

    }

    const std::string &PacketPlayOutDisconnect::getReason() const {
        return reason;
    }

}