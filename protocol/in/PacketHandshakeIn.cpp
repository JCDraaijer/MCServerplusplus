#include <utility>

//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "PacketHandshakeIn.hpp"

namespace protocol {

    PacketHandshakeIn::PacketHandshakeIn(int protocolVersion, std::string address, unsigned short port,
                                         network::State nextState) : PacketInBase(HANDSHAKE) {
        this->protocolVersion = protocolVersion;
        this->address = std::move(address);
        this->port = port;
        this->nextState = nextState;
    }

    std::string PacketHandshakeIn::toString() {
        std::ostringstream stringStream;
        stringStream << "Handshake packet. ID: " << this->getId() << ", Protocol Version: " << this->protocolVersion
                     << ", Server Address: "
                     << this->address << ", Server Port: " << this->port << ", Next state: "
                     << stateToString(this->getNextState());
        return stringStream.str();
    }

    network::State PacketHandshakeIn::getNextState() {
        return this->nextState;
    }

    int PacketHandshakeIn::getProtocolVersion() {
        return this->protocolVersion;
    }

    std::string PacketHandshakeIn::getAddress() {
        return this->address;
    }

    unsigned short PacketHandshakeIn::getPort() {
        return this->port;
    }
}
