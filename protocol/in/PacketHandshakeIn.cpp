#include <utility>

//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "PacketHandshakeIn.hpp"

namespace protocol {

    PacketHandshakeIn::PacketHandshakeIn(int protocolVersion, std::string address, unsigned short port,
                                         ConnectionState nextState) : PacketInBase(HANDSHAKE) {
        this->protocolVersion = protocolVersion;
        this->address = std::move(address);
        this->port = port;
        this->nextState = nextState;
    }


    PacketHandshakeIn::PacketHandshakeIn(PacketParser *parser) : PacketInBase(HANDSHAKE) {
        parse(parser);
    }

    std::string PacketHandshakeIn::toString() {
        std::ostringstream stringStream;
        stringStream << "Handshake packet. ID: " << this->getId() << ", Protocol Version: " << this->protocolVersion
                     << ", Server Address: "
                     << this->address << ", Server Port: " << this->port << ", Next state: "
                     << stateToString(this->getNextState());
        return stringStream.str();
    }

    ConnectionState PacketHandshakeIn::getNextState() {
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

    void PacketHandshakeIn::parse(PacketParser *packetParser) {
        protocolVersion = packetParser->readVarInt();
        address = packetParser->readString();
        port = packetParser->readUnsignedShort();
        int32_t nextStateInt = packetParser->readVarInt();

        ConnectionState actualNextState;

        switch (nextStateInt) {
            case 1:
                actualNextState = STATUS;
                break;
            case 2:
                actualNextState = LOGIN;
                break;
            default:
                actualNextState = UNDEFINED;
        }
        nextState = actualNextState;
    }
}
