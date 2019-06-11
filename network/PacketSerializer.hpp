//
// Created by jona on 2019-06-10.
//

#ifndef MCSERVER_PACKETSERIALIZER_HPP
#define MCSERVER_PACKETSERIALIZER_HPP


#include "../protocol/out/PacketOutBase.hpp"

using namespace protocol;

namespace network {
    class PacketSerializer {
    private:
        uint8_t *buffer;
        uint32_t bufferSize;

        uint32_t setTotalLength(uint32_t value);

    public:
        explicit PacketSerializer(uint32_t bufferSize);
        ~PacketSerializer();

        void setBufferSize(uint32_t newSize);

        uint8_t *serialize(PacketOutBase *packet, uint32_t *size);

    };

}

#endif //MCSERVER_PACKETSERIALIZER_HPP
