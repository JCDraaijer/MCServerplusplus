//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_CONNECTIONSTATE_HPP
#define MCSERVER_CONNECTIONSTATE_HPP

#include <string>

namespace protocol {
    enum ConnectionState {
        HANDSHAKING,
        PLAY,
        STATUS,
        LOGIN,
        UNDEFINED
    };

    std::string stateToString(ConnectionState);
}


#endif //MCSERVER_CONNECTIONSTATE_HPP
