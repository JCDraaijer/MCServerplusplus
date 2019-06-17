//
// Created by jona on 2019-06-16.
//

#include "PacketOutPlayChunkData.hpp"

namespace protocol {

    void PacketOutPlayChunkData::serialize(PacketSerializer *packetSerializer) {
        uint32_t chunksToSend = 0;
        uint32_t bitMask = 0;
        uint32_t size = 0;

        for (uint32_t i = 0; i < 16; i++) {
            if (!someChunk->getSections()[i].isEmtpy()){
                bitMask &= 1u << i;
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

    PacketOutPlayChunkData::PacketOutPlayChunkData(server::Chunk *someChunk, bool fullChunk)
            : PacketOutBase(CHUNK_DATA), someChunk(someChunk), fullChunk(fullChunk) {

    }

    PacketOutPlayChunkData::~PacketOutPlayChunkData() = default;
}