//
// Created by jona on 2019-06-10.
//

#ifndef MCSERVER_PACKETPARSER_HPP
#define MCSERVER_PACKETPARSER_HPP

#include "ConnectionState.hpp"
#include "in/PacketInBase.hpp"

namespace protocol {

    class PacketInBase;

    class PacketParser {
    private:

        uint32_t currentOffset;
        uint32_t dataLength;
        uint8_t *dataBuffer;

        PacketInBase *
        _parseHandshake(int packetId);

        PacketInBase *
        _parseStatus(int packetId);

        PacketInBase *
        _parsePlay(int packetId);

        PacketInBase *
        _parseLogin(int packetId);

        bool verifyDataLeft(uint32_t left);

    public:

        explicit PacketParser();

        PacketInBase *
        parse(ConnectionState currentState, int packetId, unsigned char *data,
              int dataLength);


        int64_t readLong();

        uint8_t *readByteArray(uint32_t count);

        uint8_t *readByteArray(uint32_t *length);

        uint16_t readUnsignedShort();

        std::string readString();

        std::string readString(uint32_t *length);

        int32_t readVarInt(int socket, uint8_t *length);

        int32_t readVarInt();

        int8_t readByte();

        int8_t readByte(int socket);

        uint8_t readUnsignedByte();

        bool readBoolean();
    };
}


#endif //MCSERVER_PACKETPARSER_HPP
