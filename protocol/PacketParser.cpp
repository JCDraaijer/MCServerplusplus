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


#include <unistd.h>
#include <strings.h>
#include "PacketParser.hpp"
#include "in/PacketInHandshake.hpp"
#include "in/PacketInStatusRequest.hpp"
#include "in/PacketInLoginStart.hpp"
#include "in/PacketInStatusPing.hpp"
#include "in/PacketInPlayPluginMessage.hpp"
#include "Identifier.hpp"
#include "exception/UnknownPacketException.hpp"
#include "exception/Exception.hpp"
#include "exception/OffsetOutOfBoundsException.hpp"
#include "in/PacketInPlayClientSettings.hpp"
#include "in/PacketInPlayTeleportConfirm.hpp"
#include "in/PacketInLegacyPingRequest.hpp"
#include "in/PacketInPlayUpdateStructureBlock.hpp"
#include "in/PacketInPlayerPositionLook.hpp"
#include "exception/DataShortageException.hpp"

namespace protocol {

    typedef union {
        float f;
        uint8_t bytes[sizeof(float)];
    } float_byte_union;

    typedef union {
        double d;
        uint8_t bytes[sizeof(double)];
    } double_byte_union;

    PacketParser::PacketParser() {
        dataBuffer = nullptr;
        dataLength = 0;
        currentOffset = 0;
    }

    PacketInBase *
    PacketParser::parse(ConnectionState currentState, int packetId, unsigned char *data,
                        int theDataLength) {
        currentOffset = 0;
        this->dataBuffer = data;
        this->dataLength = theDataLength;
        PacketInBase *packet;
        if (currentState == HANDSHAKING) {
            packet = _parseHandshake(packetId);
        } else if (currentState == STATUS) {
            packet = _parseStatus(packetId);
        } else if (currentState == LOGIN) {
            packet = _parseLogin(packetId);
        } else if (currentState == PLAY) {
            packet = _parsePlay(packetId);
        } else {
            throw UnknownPacketException(packetId, UNDEFINED, dataLength);
        }
        packet->parse(this);
        return packet;
    }

    PacketInBase *
    PacketParser::_parseHandshake(int packetId) {
        PacketInBase *packet;
        switch (packetId) {
            case HANDSHAKE:
                packet = new PacketInHandshake();
                break;
            case LEGACY_PING:
                packet = new PacketInLegacyPingRequest();
                break;
            default:
                throw UnknownPacketException(packetId, HANDSHAKING, dataLength);
        }
        return packet;
    }

    PacketInBase *
    PacketParser::_parseStatus(int packetId) {
        PacketInBase *packet;
        switch (packetId) {
            case STATUS_REQUEST:
                packet = new PacketInStatusRequest();
                break;
            case PING:
                packet = new PacketInStatusPing();
                break;
            default:
                throw UnknownPacketException(packetId, STATUS, dataLength);
        }
        return packet;
    }

    PacketInBase *
    PacketParser::_parsePlay(int packetId) {
        PacketInBase *packet;
        switch (packetId) {
            case SERVER_PLUGIN_MESSAGE:
                packet = new PacketInPlayPluginMessage();
                break;
            case CLIENT_SETTINGS:
                packet = new PacketInPlayClientSettings();
                break;
            case TELEPORT_CONFIRM:
                packet = new PacketInPlayTeleportConfirm();
                break;
            case UPDATE_STRUCTURE_BLOCK:
                packet = new PacketInPlayUpdateStructureBlock();
                break;
            case SERVER_PLAYER_POSITION_LOOK:
                packet = new PacketInPlayerPositionLook();
                break;
            default:
                throw UnknownPacketException(packetId, PLAY, dataLength);
        }
        return packet;
    }

    PacketInBase *
    PacketParser::_parseLogin(int packetId) {
        PacketInBase *packet;
        switch (packetId) {
            case LOGIN_START:
                packet = new PacketInLoginStart();
                break;
            case ENCRYPTION_RESPONSE:
            case LOGIN_PLUGIN_RESPONSE:
            default:
                throw UnknownPacketException(packetId, LOGIN, dataLength);
        }
        return packet;
    }

    uint8_t PacketParser::readUnsignedByte() {
        verifyDataLeft(1);
        return dataBuffer[currentOffset++];
    }

    int8_t PacketParser::readByte() {
        return readUnsignedByte();
    }

    int8_t PacketParser::readByte(int socket) {
        uint8_t theByte = 0;
        int readBytes = read(socket, &theByte, 1);
        if (readBytes != 1) {
            throw Exception("Could not read byte from socket!");
        }
        return theByte;
    }

    int32_t PacketParser::readVarInt() {
        int32_t finalValue = 0;
        uint8_t read = 0;
        uint8_t current = 0;
        do {
            if (read > 5) {
                throw Exception("Can't read VarInt>5!");
            }
            current = readByte();
            finalValue |= (current & 0b01111111u) << (7u * read++);
        } while ((current & 0b10000000u) != 0);
        return finalValue;
    }


    int32_t PacketParser::readVarInt(int socket, uint8_t *length) {
        int32_t finalValue = 0;
        uint8_t read = 0;
        uint8_t current = 0;
        do {
            if (read > 5) {
                throw Exception("Can't read VarInt>5!");
            }
            current = readByte(socket);
            finalValue |= (current & 0b01111111u) << (7u * read++);
        } while ((current & 0b10000000u) != 0);
        *length += read;
        return finalValue;
    }

    std::string PacketParser::readString() {
        uint32_t length = 0;
        return readString(&length);
    }

    std::string PacketParser::readString(uint32_t *length) {
        *length = readVarInt();
        verifyDataLeft(*length);
        char *array = (char *) readByteArray(*length);
        std::string toReturn = std::string(array);
        free(array);
        return toReturn;
    }

    uint16_t PacketParser::readUnsignedShort() {
        uint16_t shortToReturn =
                readUnsignedByte() << 8u | readUnsignedByte();
        return shortToReturn;
    }


    uint8_t *PacketParser::readByteArray(uint32_t count) {
        verifyDataLeft(count);
        auto *actualData = (uint8_t *) malloc(sizeof(uint8_t) * (count + 1));
        bzero(actualData, count);
        for (int i = 0; i < count; i++) {
            actualData[i] = readByte();
        }
        actualData[count] = '\0';
        return actualData;
    }

    int32_t PacketParser::readInt() {
        verifyDataLeft(4);
        int32_t value = 0;
        for (int i = 0; i < 4; i++) {
            value |= readByte();
            value <<= 8;
        }
        return value;
    }

    int64_t PacketParser::readLong() {
        verifyDataLeft(8);
        int64_t value = 0;
        for (int i = 0; i < 8; i++) {
            value |= readByte();
            value <<= 8;
        }
        return value;
    }

    bool PacketParser::verifyDataLeft(uint32_t left) {
        if (currentOffset + left <= dataLength){
            return true;
        } else {
            throw OffsetOutOfBoundsException(currentOffset - dataLength, left);
        }
    }

    bool PacketParser::readBoolean() {
        return readByte();
    }

    uint8_t *PacketParser::readByteArray(uint32_t *length) {
        *length = dataLength - currentOffset;
        return readByteArray(dataLength - currentOffset);
    }

    double PacketParser::readDouble() {
        verifyDataLeft(8);
        double_byte_union theUnion;
        for (unsigned char &byte : theUnion.bytes) {
            byte = readUnsignedByte();
        }
        return theUnion.d;
    }

    float PacketParser::readFloat() {
        verifyDataLeft(4);
        float_byte_union theUnion;
        for (unsigned char &byte : theUnion.bytes) {
            byte = readUnsignedByte();
        }
        return theUnion.f;
    }
}
