#include <utility>
#include <sstream>

//
// Created by jona on 2019-06-15.
//

#include "PacketPlayInPluginMessage.hpp"

namespace protocol {


    PacketPlayInPluginMessage::PacketPlayInPluginMessage(Identifier ident, uint32_t dataLength, uint8_t *data)
            : PacketInBase(SERVER_PLUGIN_MESSAGE), identifier(std::move(ident)), dataLength(dataLength), data(data) {

    }

    Identifier *PacketPlayInPluginMessage::getIdentifier() {
        return &identifier;
    }

    uint8_t *PacketPlayInPluginMessage::getData() {
        return data;
    }

    std::string PacketPlayInPluginMessage::toString() {
        std::ostringstream stringStream;
        char dataString[1024];
        sprintf(dataString, "%s", data);
        stringStream << "Server Plugin Message packet. ID: " << this->getId()
                     << ". Identifier: " + identifier.getNamespace() + ":" + identifier.getThing() + ". Data: "
                     << dataString;
        return stringStream.str();
    }
}