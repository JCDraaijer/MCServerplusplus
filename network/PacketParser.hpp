//
// Created by jona on 2019-06-10.
//

#ifndef MCSERVER_PACKETPARSER_HPP
#define MCSERVER_PACKETPARSER_HPP

#include "../protocol/in/PacketInBase.hpp"
#include "State.hpp"

using namespace protocol;

namespace network {
    class PacketParser {
    private:
        static PacketInBase *
        _parseHandshake(int packetId, uint8_t *data, uint32_t dataLength);

        static PacketInBase *
        _parseStatus(int packetId, unsigned char *data,
                     int dataLength);

        static PacketInBase *
        _parsePlay(int packetId, unsigned char *data,
                   int dataLength);

        static PacketInBase *
        _parseLogin(int packetId, unsigned char *data,
                    int dataLength);

    public:
        static PacketInBase *
        parse(network::State currentState, int packetId, unsigned char *data,
              int dataLength);
    };
}


#endif //MCSERVER_PACKETPARSER_HPP
