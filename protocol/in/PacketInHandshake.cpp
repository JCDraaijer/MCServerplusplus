#include <utility>

//
// Created by jona on 2019-06-09.
//

#include <sstream>
#include "PacketInHandshake.hpp"

namespace protocol {

    PacketInHandshake::PacketInHandshake(int protocolVersion, std::string address, unsigned short port,
                                         ConnectionState nextState) : PacketInBase(HANDSHAKE) {
        this->protocolVersion = protocolVersion;
        this->address = std::move(address);
        this->port = port;
        this->nextState = nextState;
    }


    PacketInHandshake::PacketInHandshake(PacketParser *parser) : PacketInBase(HANDSHAKE) {
        parse(parser);
    }

    std::string PacketInHandshake::toString() {
        std::ostringstream stringStream;
        stringStream << "Handshake packet. ID: " << this->getId() << ", Protocol Version: " << this->protocolVersion
                     << ", Server Address: "
                     << this->address << ", Server Port: " << this->port << ", Next state: "
                     << stateToString(this->getNextState());
        return stringStream.str();
    }

    ConnectionState PacketInHandshake::getNextState() {
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

    void PacketInHandshake::parse(PacketParser *packetParser) {
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
