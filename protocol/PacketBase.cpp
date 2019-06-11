//
// Created by jona on 2019-06-09.
//

#include "PacketBase.hpp"

namespace protocol {

    int PacketBase::getId() {
        return this->id;
    }

    PacketBase::PacketBase(int id) : id(id) {

    }

    std::string outPacketTypeToString(OutPacketType type){
        switch (type){
            case RESPONSE:
                return "RESPONSE";
            case PONG:
                return "PONG";
            case DISCONNECT:
                return "DISCONNECT";
            case ENCRYPTION_REQUEST:
                return "ENCRYPTION REQUEST";
            case SET_COMPRESSION:
                return "SET_COMPRESSION";
            case LOGIN_SUCCESS:
                return "LOGIN_SUCCESS";
        }
        return "";
    }
}