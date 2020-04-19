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

#include "PacketOutPlayChunkData.hpp"

namespace protocol {

    PacketOutPlayChunkData::PacketOutPlayChunkData(server::Chunk *someChunk, bool fullChunk)
            : PacketOutBase(CHUNK_DATA) {
        this->someChunk = someChunk;
        this->fullChunk = fullChunk;
    }

    void PacketOutPlayChunkData::serialize(PacketSerializer *packetSerializer) {
        uint32_t chunksToSend = 0;
        uint32_t bitMask = 0;
        uint32_t size = 0;

        for (uint32_t i = 0; i < 16; i++) {
            if (!someChunk->getSections()[i].isEmtpy()) {
                bitMask |= 1u << i;
                chunksToSend++;
            }
        }
        packetSerializer->writeInt(someChunk->getChunkLocation().getX());
        packetSerializer->writeInt(someChunk->getChunkLocation().getZ());
        packetSerializer->writeBoolean(fullChunk);
        packetSerializer->writeVarInt(bitMask);
        packetSerializer->writeString("");
        packetSerializer->writeVarInt(chunksToSend);
        packetSerializer->writeVarInt(size);
    }

}