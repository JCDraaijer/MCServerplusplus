//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_STATE_HPP
#define MCSERVER_STATE_HPP

#include <string>

namespace network {
    enum State {
        HANDSHAKING,
        PLAY,
        STATUS,
        LOGIN,
        UNDEFINED
    };

    std::string stateToString(State);
}


#endif //MCSERVER_STATE_HPP
