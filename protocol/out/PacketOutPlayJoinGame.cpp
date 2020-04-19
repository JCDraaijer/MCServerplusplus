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
        packetSerializer->writeBoolean(reducedDebugInfo);
        packetSerializer->writeBoolean(respawnScreen);
    }

    PacketOutPlayJoinGame::~PacketOutPlayJoinGame() = default;

}