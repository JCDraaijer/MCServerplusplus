#include <utility>

//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "PacketInHandshake.hpp"

namespace protocol {

    PacketInHandshake::PacketInHandshake(int protocolVersion, std::string address, unsigned short port,
                                         network::State nextState) : PacketInBase(0, HANDSHAKE) {
        this->protocolVersion = protocolVersion;
        this->address = std::move(address);
        this->port = port;
        this->nextState = nextState;
    }

    std::string PacketInHandshake::toString() {
        std::ostringstream stringStream;
        stringStream << "Handshake packet. ID: " << this->getId() << ", Protocol Version: " << this->protocolVersion
                     << ", Server Address: "
                     << this->address << ", Server Port: " << this->port << ", Next state: "
                     << stateToString(this->getNextState());
        return stringStream.str();
    }

    network::State PacketInHandshake::getNextState() {
        return this->nextState;
    }

    int PacketInHandshake::getProtocolVersion() {
        return this->protocolVersion;
    }

    std::string PacketInHandshake::getAddress() {
        return this->address;
    }

    unsigned short PacketInHandshake::getPort() {
        return this->port;
    }
}
