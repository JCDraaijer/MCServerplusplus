#include <utility>

//
// Created by jona on 2019-06-14.
//

#include "PacketOutPlayJoinGame.hpp"

namespace protocol {
    PacketOutPlayJoinGame::PacketOutPlayJoinGame(int32_t entityId,
                                                 uint8_t gameMode, int32_t dimension, uint8_t difficulty,
                                                 uint8_t maxPlayers, std::string levelType,
                                                 bool reducedDebugInfo) : PacketOutBase(JOIN_GAME),
                                                                          entityId(entityId), gameMode(gameMode),
                                                                          dimension(dimension),
                                                                          difficulty(difficulty),
                                                                          maxPlayers(maxPlayers),
                                                                          levelType(std::move(levelType)),
                                                                          reducedDebugInfo(reducedDebugInfo) {}

    void PacketOutPlayJoinGame::serialize(protocol::PacketSerializer *packetSerializer) {
        packetSerializer->writeInt(entityId);
        packetSerializer->writeUnsignedByte(gameMode);
        packetSerializer->writeInt(dimension);
        packetSerializer->writeUnsignedByte(difficulty);
        packetSerializer->writeString(levelType);
        packetSerializer->writeVarInt(maxPlayers);
        packetSerializer->writeUnsignedByte(reducedDebugInfo);
    }

    PacketOutPlayJoinGame::~PacketOutPlayJoinGame() = default;

}