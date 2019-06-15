//
// Created by jona on 2019-06-15.
//

#include "PacketInPlayClientSettings.hpp"

namespace protocol {
    std::string protocol::PacketInPlayClientSettings::toString() {
        return "Client Settings packet, ID: 0x05.";
    }

    protocol::PacketInPlayClientSettings::PacketInPlayClientSettings(protocol::PacketParser *parser) : PacketInBase(
            CLIENT_SETTINGS) {
        parse(parser);
    }

    void protocol::PacketInPlayClientSettings::parse(protocol::PacketParser *packetParser) {
        locale = packetParser->readString();
        renderDistance = packetParser->readByte();
        chatMode = packetParser->readVarInt();
        chatColors = packetParser->readBoolean();
        skinParts = packetParser->readUnsignedByte();
        mainHand = packetParser->readVarInt();
    }
}
