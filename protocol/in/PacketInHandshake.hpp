//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETINHANDSHAKE_HPP
#define MCSERVER_PACKETINHANDSHAKE_HPP

#include "PacketInBase.hpp"
#include "../../network/State.hpp"

namespace protocol {

    class PacketInHandshake : public PacketInBase {
    private:
        const int id = 0;
        int protocolVersion;
        std::string address;
        unsigned short port;
        network::State nextState;

    public:
        explicit PacketInHandshake(int32_t protocolVersion, std::string address, uint16_t port, network::State nextState);

        network::State getNextState();

        int getProtocolVersion();

        std::string getAddress();

        unsigned short getPort();

        std::string toString() override;
    };
}


#endif //MCSERVER_PACKETINHANDSHAKE_HPP
