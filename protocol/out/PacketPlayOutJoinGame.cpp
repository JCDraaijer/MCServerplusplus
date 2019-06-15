#include <utility>

//
// Created by jona on 2019-06-14.
//

#include "PacketPlayOutJoinGame.hpp"

namespace protocol {
    PacketPlayOutJoinGame::PacketPlayOutJoinGame(int32_t entityId,
                                                 uint8_t gameMode, int32_t dimension, uint8_t difficulty,
                                                 uint8_t maxPlayers, std::string levelType,
                                                 bool reducedDebugInfo) : PacketOutBase(JOIN_GAME),
                                                                          entityId(entityId), gameMode(gameMode),
                                                                          dimension(dimension),
                                                                          difficulty(difficulty),
                                                                          maxPlayers(maxPlayers),
                                                                          levelType(std::move(levelType)),
                                                                          reducedDebugInfo(reducedDebugInfo) {}

    void PacketPlayOutJoinGame::serialize(protocol::PacketSerializer *packetSerializer) {
        packetSerializer->writeInt(entityId);
        packetSerializer->writeUnsignedByte(gameMode);
        packetSerializer->writeInt(dimension);
        packetSerializer->writeUnsignedByte(difficulty);
        packetSerializer->writeString(levelType);
        packetSerializer->writeVarInt(maxPlayers);
        packetSerializer->writeUnsignedByte(reducedDebugInfo);
    }

}