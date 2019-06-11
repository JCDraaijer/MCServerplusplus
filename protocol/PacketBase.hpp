//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETBASE_HPP
#define MCSERVER_PACKETBASE_HPP

#include <string>

namespace protocol {
    enum InPacketType {
        HANDSHAKE,
        REQUEST,
        PING,
        LOGIN_START,
        ENCRYPTION_RESPONSE,
        LOGIN_PLUGIN_RESPONSE,
    };

    enum OutPacketType {
        RESPONSE,
        PONG,
        DISCONNECT,
        ENCRYPTION_REQUEST,
        SET_COMPRESSION,
        LOGIN_SUCCESS
    };

    class PacketBase {
    private:
        const int id;
    public:
        explicit PacketBase(int);

        virtual std::string toString() = 0;

        int getId();
    };

    std::string outPacketTypeToString(OutPacketType type);

}
#endif //MCSERVER_PACKETBASE_HPP
