//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_STATE_H
#define MCSERVER_STATE_H

#include <string>

namespace networking {
    enum State {
        HANDSHAKING,
        PLAY,
        STATUS,
        LOGIN,
        UNDEFINED
    };

    std::string stateToString(State);
}


#endif //MCSERVER_STATE_H
