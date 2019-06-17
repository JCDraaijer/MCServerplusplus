//
// Created by jona on 2019-06-17.
//

#ifndef MCSERVER_PACKETINPLAYUPDATESTRUCTUREBLOCK_HPP
#define MCSERVER_PACKETINPLAYUPDATESTRUCTUREBLOCK_HPP

#include "../../server/world/Location.hpp"
#include "PacketInBase.hpp"

namespace protocol {
    class PacketInPlayUpdateStructureBlock : public PacketInBase {
    private:
        server::Location location;
        int32_t action;
        int32_t mode;
        std::string name;
        int8_t offsetX;
        int8_t offsetY;
        int8_t offsetZ;
        int8_t sizeX;
        int8_t sizeY;
        int8_t sizeZ;
        int32_t mirror;
        int32_t rotation;
        std::string metadata;
        float integrity;
        int64_t seed;
        uint8_t flags;

    public:
        explicit PacketInPlayUpdateStructureBlock(PacketParser *packetParser);

        std::string toString() override;

        void parse(PacketParser *packetParser) override;
    };
}


#endif //MCSERVER_PACKETINPLAYUPDATESTRUCTUREBLOCK_HPP
