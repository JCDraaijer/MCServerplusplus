//
// Created by jona on 2019-06-10.
//

#ifndef MCSERVER_PACKETSERIALIZER_HPP
#define MCSERVER_PACKETSERIALIZER_HPP

#define LENGTH_BUFFER_SIZE 5

#include "out/PacketOutBase.hpp"

namespace protocol {

    class PacketOutBase;

    class PacketSerializer {
    private:
        uint8_t *dataBuffer;
        uint32_t dataBufferSize;
        uint8_t *packetBuffer;

        uint32_t currentDataSize;

        void writeLengthHeader(int32_t integer);

    public:
        explicit PacketSerializer(uint32_t bufferSize);

        ~PacketSerializer();

        void setBufferSize(uint32_t newSize);

        uint8_t *serializePacket(PacketOutBase *packet, uint32_t *packetLength);

        void writeVarInt(int32_t integer);

        void writeString(std::string);

        void writeLong(int64_t longInteger);

        void writeByteArray(const uint8_t *data, uint32_t count);

        void verifyBufferCapacity(uint32_t capacity);

        static uint8_t varIntLength(int32_t integer);

        static uint8_t varLongLength(int64_t longInteger);

        static uint32_t stringLength(const std::string &someString);
    };

}

#endif //MCSERVER_PACKETSERIALIZER_HPP
