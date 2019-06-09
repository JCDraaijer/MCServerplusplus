//
// Created by jona on 2019-06-09.
//

#include "State.h"

namespace networking {
    std::string stateToString(State state) {
        switch (state) {
            case HANDSHAKING:
                return "HANDSHAKING";
            case PLAY:
                return "PLAY";
            case STATUS:
                return "STATUS";
            case LOGIN:
                return "LOGIN";
            case UNDEFINED:
            default:
                return "UNDEFINED";
        }
    }
}