//
// Created by jona on 2019-06-14.
//

#include <sstream>
#include "UnknownPacketException.hpp"

namespace protocol {

    UnknownPacketException::UnknownPacketException(uint32_t packetNumber, ConnectionState state, uint32_t length) {
        sprintf((char *) whatValue, "Unknown packet 0x%02X for state %s with length %d", packetNumber,
                stateToString(state).c_str(), length);
    }

    const char *UnknownPacketException::what() const _GLIBCXX_USE_NOEXCEPT {
        return (const char *) whatValue;
    }
}