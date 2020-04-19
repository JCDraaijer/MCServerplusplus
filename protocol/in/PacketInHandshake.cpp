/*
MCpp, a Minecraft Server implementation in C++.
Copyright (C) 2019, 2020 Johannes Draaijer

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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


    PacketInHandshake::PacketInHandshake() : PacketInHandshake(0, "", 0, UNDEFINED) {}

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

}
