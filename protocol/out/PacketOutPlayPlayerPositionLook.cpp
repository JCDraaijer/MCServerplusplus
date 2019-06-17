//
// Created by jona on 2019-06-16.
//

#include "PacketOutPlayPlayerPositionLook.hpp"

namespace protocol {
    void PacketOutPlayPlayerPositionLook::serialize(protocol::PacketSerializer *packetSerializer) {
        packetSerializer->writeDouble(x);
        packetSerializer->writeDouble(y);
        packetSerializer->writeDouble(z);
        packetSerializer->writeFloat(yaw);
        packetSerializer->writeFloat(pitch);
        packetSerializer->writeUnsignedByte(flags);
        packetSerializer->writeVarInt(teleportId);
    }

    PacketOutPlayPlayerPositionLook::PacketOutPlayPlayerPositionLook(double x, double y, double z, float yaw,
                                                                     float pitch, uint8_t flags, int32_t teleportId)
            : PacketOutBase(CLIENT_PLAYER_POSITION_LOOK), x(x), y(y), z(z),
              yaw(yaw), pitch(pitch), flags(flags), teleportId(teleportId) {

    }

    PacketOutPlayPlayerPositionLook::~PacketOutPlayPlayerPositionLook() = default;
}
