//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "Handshake.h"
#include "../../Util.h"

using namespace networking;

namespace packet { namespace in {

    Handshake::Handshake(int protocolVersion, std::string address, unsigned short port,
                         State nextState) : InBase(0, HANDSHAKE) {
        this->protocolVersion = protocolVersion;
        this->address = address;
        this->port = port;
        this->nextState = nextState;
    }

    Handshake::Handshake() : Handshake(-1, "", 0, UNDEFINED) {
    }

    void Handshake::parse(unsigned char *data, int dataLength) {
        int offset = 0;
        this->protocolVersion = Util::readVarInt(data, &offset, dataLength);
        this->address = Util::readString(data, &offset, dataLength);
        this->port = Util::readUnsignedShort(data, &offset, dataLength);
        int nextStateInt = Util::readVarInt(data, &offset, dataLength);
        if (nextStateInt == 1) {
            nextState = STATUS;
        } else if (nextStateInt == 2) {
            nextState = LOGIN;
        } else {
            nextState = UNDEFINED;
        }
    }

    std::string Handshake::toString() {
        std::ostringstream stringStream;
        stringStream << "Handshake packet. ID: " << this->id << ", Protocol Version: " << this->protocolVersion << ", Server Address: "
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
} }
