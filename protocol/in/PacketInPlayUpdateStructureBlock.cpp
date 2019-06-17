//
// Created by jona on 2019-06-17.
//

#include "PacketInPlayUpdateStructureBlock.hpp"

namespace protocol {
    std::string PacketInPlayUpdateStructureBlock::toString() {
        return std::__cxx11::string();
    }

    void PacketInPlayUpdateStructureBlock::parse(protocol::PacketParser *packetParser) {

    }

    PacketInPlayUpdateStructureBlock::PacketInPlayUpdateStructureBlock(PacketParser *packetParser) : PacketInBase(UPDATE_STRUCTURE_BLOCK) {

    }
}

