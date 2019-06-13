//
// Created by jona on 2019-06-10.
//

#include "PacketParser.hpp"
#include "../protocol/in/PacketInHandshake.hpp"
#include "../protocol/in/PacketInRequest.hpp"
#include "../protocol/in/PacketInLoginStart.hpp"
#include "../protocol/in/PacketInEncryptionResponse.hpp"
#include "../protocol/in/PacketInPing.hpp"
#include "../protocol/util/Util.hpp"

using namespace protocol;

namespace network {
    PacketInBase *
    PacketParser::parse(network::State currentState, int packetId, unsigned char *data,
                        int dataLength) {
        if (currentState == network::State::HANDSHAKING) {
            return _parseHandshake(packetId, data, dataLength);
        } else if (currentState == network::State::STATUS) {
            return _parseStatus(packetId, data, dataLength);
        } else if (currentState == network::State::LOGIN) {
            return _parseLogin(packetId, data, dataLength);
        } else if (currentState == network::State::PLAY) {
            return _parsePlay(packetId, data, dataLength);
        }
        return nullptr;
    }

    PacketInBase *
    PacketParser::_parseHandshake(int packetId, uint8_t *data, uint32_t dataLength) {
        uint32_t offset = 0;
        if (packetId == 0x00) {
            int32_t protocolVersion = Util::readVarInt(data, &offset, dataLength);
            std::string serverAddress = Util::readString(data, &offset, dataLength);
            uint16_t port = Util::readUnsignedShort(data, &offset, dataLength);
            int32_t nextStateInt = Util::readVarInt(data, &offset, dataLength);

            network::State actualNextState;

            switch (nextStateInt) {
                case 1:
                    actualNextState = STATUS;
                    break;
                case 2:
                    actualNextState = LOGIN;
                    break;
                default:
                    actualNextState = UNDEFINED;
            }
            PacketInHandshake *packetInHandshake = new PacketInHandshake(protocolVersion, serverAddress, port,
                                                                         actualNextState);
            return packetInHandshake;
        }
        return nullptr;
    }

    PacketInBase *
    PacketParser::_parseStatus(int packetId, unsigned char *data, int dataLength) {
        uint32_t offset = 0;
        if (packetId == 0x00) {
            return new PacketInRequest();
        } else if (packetId == 0x01){
            int64_t value = protocol::Util::readLong(data, &offset, dataLength);
            return new PacketInPing(value);
        }
        return nullptr;
    }

    PacketInBase *
    PacketParser::_parsePlay(int packetId, unsigned char *data, int dataLength) {
        return nullptr;
    }

    PacketInBase *
    PacketParser::_parseLogin(int packetId, unsigned char *data, int dataLength) {
        uint32_t offset = 0;
        if (packetId == 0x00) {
            std::string name = protocol::Util::readString(data, &offset, dataLength);
            return new PacketInLoginStart(name);
        } else if (packetId == 0x01) {
            int32_t keyLength = protocol::Util::readVarInt(data, &offset, dataLength);
            uint8_t *keyData = protocol::Util::readByteArray(data, dataLength, &offset, keyLength);
            uint32_t tokenLength = protocol::Util::readVarInt(data, &offset, dataLength);
            uint8_t *tokenData = protocol::Util::readByteArray(data, dataLength, &offset, tokenLength);
            return new PacketInEncryptionResponse(keyLength, keyData, tokenLength, tokenData);
        } else if (packetId == 0x02) {

        }
        return nullptr;
    }
}
