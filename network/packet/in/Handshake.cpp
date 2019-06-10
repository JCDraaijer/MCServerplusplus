#include <utility>

//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "Handshake.hpp"
#include "../../Util.hpp"

namespace packet {

    Handshake::Handshake(int protocolVersion, std::string address, unsigned short port,
                         networking::State nextState) : InBase(0, HANDSHAKE) {
        this->protocolVersion = protocolVersion;
        this->address = std::move(address);
        this->port = port;
        this->nextState = nextState;
    }

    Handshake::Handshake() : Handshake(-1, "", 0, networking::UNDEFINED) {
    }

    void Handshake::parse(unsigned char *data, int dataLength) {
        int offset = 0;
        this->protocolVersion = networking::Util::readVarInt(data, &offset, dataLength);
        this->address = networking::Util::readString(data, &offset, dataLength);
        this->port = networking::Util::readUnsignedShort(data, &offset, dataLength);
        int nextStateInt = networking::Util::readVarInt(data, &offset, dataLength);
        if (nextStateInt == 1) {
            nextState = networking::STATUS;
        } else if (nextStateInt == 2) {
            nextState = networking::LOGIN;
        } else {
            nextState = networking::UNDEFINED;
        }
    }

    std::string Handshake::toString() {
        std::ostringstream stringStream;
        stringStream << "Handshake packet. ID: " << this->id << ", Protocol Version: " << this->protocolVersion
                     << ", Server Address: "
                     << this->address << ", Server Port: " << this->port << ", Next state: "
                     << stateToString(this->getNextState());
        return stringStream.str();
    }

    networking::State Handshake::getNextState() {
        return this->nextState;
    }

    int Handshake::getProtocolVersion() {
        return this->protocolVersion;
    }

    std::string Handshake::getAddress() {
        return this->address;
    }

    unsigned short Handshake::getPort() {
        return this->port;
    }
}
