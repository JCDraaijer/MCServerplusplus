//
// Created by jona on 2019-06-16.
//

#ifndef MCSERVER_PACKETOUTPLAYCHUNKDATA_HPP
#define MCSERVER_PACKETOUTPLAYCHUNKDATA_HPP

#include "PacketOutBase.hpp"

#include "../../server/world/Chunk.hpp"

namespace protocol {
    class PacketOutPlayChunkData : public PacketOutBase {
    private:
        server::Chunk *someChunk;
    public:
        ~PacketOutPlayChunkData() override;

    private:
        bool fullChunk;
    public:
        explicit PacketOutPlayChunkData(server::Chunk *someChunk, bool fullChunk);

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETOUTPLAYCHUNKDATA_HPP
