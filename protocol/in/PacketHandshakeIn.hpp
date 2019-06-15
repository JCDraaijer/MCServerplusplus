//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETHANDSHAKEIN_HPP
#define MCSERVER_PACKETHANDSHAKEIN_HPP

#include "PacketInBase.hpp"
#include "../../network/State.hpp"

namespace protocol {

    class PacketHandshakeIn : public PacketInBase {
    private:
        int protocolVersion;
        std::string address;
        unsigned short port;
        network::State nextState;

    public:
        explicit PacketHandshakeIn(int32_t protocolVersion, std::string address, uint16_t port, network::State nextState);

        network::State getNextState();

        int getProtocolVersion();

        std::string getAddress();

        unsigned short getPort();

        std::string toString() override;
    };
}


#endif //MCSERVER_PACKETHANDSHAKEIN_HPP
