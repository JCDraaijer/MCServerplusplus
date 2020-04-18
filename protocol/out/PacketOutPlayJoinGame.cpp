#include <utility>

//
// Created by jona on 2019-06-14.
//

#include "PacketOutPlayJoinGame.hpp"

namespace protocol {
    PacketOutPlayJoinGame::PacketOutPlayJoinGame(int32_t entityId, uint8_t gameMode, int32_t dimension,
                                                 uint64_t seedHash,
                                                 uint8_t maxPlayers, std::string levelType, uint32_t viewDistance,
                                                 bool reducedDebugInfo, bool respawnScreen) :
            PacketOutBase(JOIN_GAME), entityId(entityId), gameMode(gameMode), dimension(dimension), seedHash(seedHash),
            maxPlayers(maxPlayers), levelType(std::move(levelType)), viewDistance(viewDistance),
            reducedDebugInfo(reducedDebugInfo), respawnScreen(respawnScreen) {}

    void PacketOutPlayJoinGame::serialize(protocol::PacketSerializer *packetSerializer) {
        packetSerializer->writeInt(entityId);
        packetSerializer->writeUnsignedByte(gameMode);
        packetSerializer->writeInt(dimension);
        packetSerializer->writeLong(seedHash);
        packetSerializer->writeUnsignedByte(maxPlayers);
        packetSerializer->writeString(levelType);
        packetSerializer->writeVarInt(viewDistance);
        packetSerializer->writeUnsignedByte(reducedDebugInfo);
        packetSerializer->writeUnsignedByte(respawnScreen);
    }

    PacketOutPlayJoinGame::~PacketOutPlayJoinGame() = default;

}