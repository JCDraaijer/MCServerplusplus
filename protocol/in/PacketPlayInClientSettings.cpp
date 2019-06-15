//
// Created by jona on 2019-06-15.
//

#include "PacketPlayInClientSettings.hpp"

namespace protocol {
    std::string protocol::PacketPlayInClientSettings::toString() {
        return std::__cxx11::string();
    }

    protocol::PacketPlayInClientSettings::PacketPlayInClientSettings(protocol::PacketParser *parser) : PacketInBase(
            CLIENT_SETTINGS) {
        parse(parser);
    }

    void protocol::PacketPlayInClientSettings::parse(protocol::PacketParser *packetParser) {
        locale = packetParser->readString();
        renderDistance = packetParser->readByte();
        chatMode = packetParser->readVarInt();
        chatColors = packetParser->readBoolean();
        skinParts = packetParser->readUnsignedByte();
        mainHand = packetParser->readVarInt();
    }
}
