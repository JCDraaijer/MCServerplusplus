//
// Created by jona on 2019-06-16.
//

#include <sstream>
#include "PacketInPlayTeleportConfirm.hpp"

namespace protocol {
    std::string PacketInPlayTeleportConfirm::toString() {
        std::ostringstream stringStream;
        stringStream << "Teleport confirm packet. ID: " << this->getId() << ". TeleportID: " << teleportId;
        return stringStream.str();
    }

    void PacketInPlayTeleportConfirm::parse(protocol::PacketParser *packetParser) {
        teleportId = packetParser->readVarInt();
    }

    PacketInPlayTeleportConfirm::PacketInPlayTeleportConfirm(int32_t id) : PacketInBase(TELEPORT_CONFIRM),
                                                                           teleportId(id) {

    }

    PacketInPlayTeleportConfirm::PacketInPlayTeleportConfirm(PacketParser *parser) : PacketInBase(TELEPORT_CONFIRM) {
        parse(parser);
    }
}
