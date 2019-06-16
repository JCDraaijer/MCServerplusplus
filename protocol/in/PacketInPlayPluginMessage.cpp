#include <utility>
#include <sstream>

//
// Created by jona on 2019-06-15.
//

#include "PacketInPlayPluginMessage.hpp"

namespace protocol {


    PacketInPlayPluginMessage::PacketInPlayPluginMessage(Identifier ident, uint32_t dataLength, uint8_t *data)
            : PacketInBase(SERVER_PLUGIN_MESSAGE), identifier(std::move(ident)), dataLength(dataLength), data(data) {

    }

    Identifier *PacketInPlayPluginMessage::getIdentifier() {
        return &identifier;
    }

    uint8_t *PacketInPlayPluginMessage::getData() {
        return data;
    }

    uint32_t PacketInPlayPluginMessage::getDataLength(){
        return dataLength;
    }

    std::string PacketInPlayPluginMessage::toString() {
        std::ostringstream stringStream;
        char dataString[dataLength + 1];
        sprintf(dataString, "%s", data);
        stringStream << "Server Plugin Message packet. ID: " << this->getId()
                     << ". Identifier: " + identifier.getNamespace() + ":" + identifier.getThing() + ". Data: "
                     << dataString;
        return stringStream.str();
    }

    PacketInPlayPluginMessage::PacketInPlayPluginMessage(PacketParser *parser) : PacketInBase(SERVER_PLUGIN_MESSAGE) {
        parse(parser);
    }

    void PacketInPlayPluginMessage::parse(PacketParser *packetParser) {
        identifier = Identifier(packetParser->readString());
        data = packetParser->readByteArray();
    }

    PacketInPlayPluginMessage::~PacketInPlayPluginMessage() {
        free(data);
    }
}