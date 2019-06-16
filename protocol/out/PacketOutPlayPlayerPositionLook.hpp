//
// Created by jona on 2019-06-16.
//

#ifndef MCSERVER_PACKETOUTPLAYPLAYERPOSITIONLOOK_HPP
#define MCSERVER_PACKETOUTPLAYPLAYERPOSITIONLOOK_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutPlayPlayerPositionLook : public PacketOutBase {
    private:
        double x;
        double y;
        double z;
        float yaw;
        float pitch;
        uint8_t flags;
        int32_t teleportId;
    public:
        PacketOutPlayPlayerPositionLook(double x, double y, double z, float yaw, float pitch, uint8_t flags, int32_t teleportId);

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETOUTPLAYPLAYERPOSITIONLOOK_HPP
