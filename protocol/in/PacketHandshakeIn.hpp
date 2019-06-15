//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETHANDSHAKEIN_HPP
#define MCSERVER_PACKETHANDSHAKEIN_HPP

#include "PacketInBase.hpp"
#include "../ConnectionState.hpp"

namespace protocol {

    class PacketHandshakeIn : public PacketInBase {
    private:
        int protocolVersion;
        std::string address;
        unsigned short port;
        ConnectionState nextState;

    public:
        explicit PacketHandshakeIn(int32_t protocolVersion, std::string address, uint16_t port, ConnectionState nextState);

        explicit PacketHandshakeIn(PacketParser *parser);

        ConnectionState getNextState();

        int getProtocolVersion();


        std::string getAddress();

        void parse(PacketParser *packetParser) override;

        unsigned short getPort();

        std::string toString() override;
    };
}


#endif //MCSERVER_PACKETHANDSHAKEIN_HPP
