//
// Created by jona on 2019-06-10.
//

#include "PacketSerializer.hpp"
#include "util/Util.hpp"
#include "../protocol/out/PacketOutResponse.hpp"
#include "Connection.hpp"
#include "../protocol/out/PacketOutPong.hpp"
#include "../protocol/out/PacketOutDisconnect.hpp"

using namespace protocol;

namespace network {
    uint8_t *PacketSerializer::serialize(protocol::PacketOutBase *packet, uint32_t *size) {
        uint32_t offset = 0;
        uint8_t idLength = Util::varIntLength(packet->getId());
        if (packet->getType() == RESPONSE) {
            auto *response = (PacketOutResponse *) packet;
            uint32_t stringLength = Util::stringLength(response->getJsonResponse());

            uint32_t contentsLength = stringLength + idLength;
            uint32_t totalLength = Util::varIntLength(contentsLength) + contentsLength;

            *size = setTotalLength(totalLength);

            Util::writeVarInt(totalLength, buffer, &offset);
            Util::writeVarInt(response->getId(), buffer, &offset);
            Util::writeString(response->getJsonResponse(), buffer, &offset);
        } else if (packet->getType() == PONG) {

            auto *pong = (PacketOutPong *) packet;
            const uint8_t longLength = Util::LONG_LENGTH;

            uint32_t contentsLength = longLength + idLength;

            uint32_t totalLength = Util::varIntLength(contentsLength) + contentsLength;

            *size = setTotalLength(totalLength);

            Util::writeVarInt(totalLength, buffer, &offset);
            Util::writeVarInt(pong->getId(), buffer, &offset);
            Util::writeLong(pong->getValue(), buffer, &offset);
        } else if (packet->getType() == DISCONNECT) {
            auto *disconnect = (PacketOutDisconnect *) packet;

            uint32_t stringLength = Util::stringLength(disconnect->getReason());

            uint32_t contentsLength = stringLength + idLength;
            uint32_t totalLength = Util::varIntLength(contentsLength) + contentsLength;

            *size = setTotalLength(totalLength);

            Util::writeVarInt(totalLength, buffer, &offset);
            Util::writeString(disconnect->getReason(), buffer, &offset);
        }
        return buffer;
    }

    uint32_t PacketSerializer::setTotalLength(uint32_t value) {
        if (value > bufferSize) {
            setBufferSize(value);
        }
        return value;
    }

    PacketSerializer::PacketSerializer(uint32_t bufferSize) {
        this->bufferSize = bufferSize;
        this->buffer = nullptr;
        setBufferSize(bufferSize);
    }

    void PacketSerializer::setBufferSize(uint32_t newSize) {
        bufferSize = newSize;
        buffer = (uint8_t *) realloc(buffer, sizeof(uint8_t) * newSize);
    }

    PacketSerializer::~PacketSerializer() {
        free(buffer);
    }


}
