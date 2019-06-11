#include <utility>

//
// Created by jona on 2019-06-11.
//

#include "PacketOutDisconnect.hpp"

namespace protocol {
    PacketOutDisconnect::PacketOutDisconnect(std::string reason) : PacketOutBase(0x00, DISCONNECT),
                                                                   reason(std::move(reason)) {

    }

    const std::string &PacketOutDisconnect::getReason() const {
        return reason;
    }

}