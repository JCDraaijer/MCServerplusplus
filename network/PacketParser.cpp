//
// Created by jona on 2019-06-10.
//

#include "PacketParser.hpp"
#include "../protocol/in/PacketHandshakeIn.hpp"
#include "../protocol/in/PacketStatusInRequest.hpp"
#include "../protocol/in/PacketInLoginStart.hpp"
#include "../protocol/in/PacketLoginInEncryptionResponse.hpp"
#include "../protocol/in/PacketStatusInPing.hpp"
#include "../protocol/util/Util.hpp"
#include "../protocol/util/Exception.hpp"
#include "../protocol/util/UnknownPacketException.hpp"
#include "../protocol/Identifier.hpp"
#include "../protocol/in/PacketPlayInPluginMessage.hpp"

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
        throw UnknownPacketException(packetId, UNDEFINED, dataLength);
    }

    PacketInBase *
    PacketParser::_parseHandshake(int packetId, uint8_t *data, uint32_t dataLength) {
        uint32_t offset = 0;
        if (packetId == HANDSHAKE) {
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
            PacketHandshakeIn *packetInHandshake = new PacketHandshakeIn(protocolVersion, serverAddress, port,
                                                                         actualNextState);
            return packetInHandshake;
        }
        throw UnknownPacketException(packetId, HANDSHAKING, dataLength);
    }

    PacketInBase *
    PacketParser::_parseStatus(int packetId, unsigned char *data, int dataLength) {
        uint32_t offset = 0;
        if (packetId == STATUS_REQUEST) {
            return new PacketStatusInRequest();
        } else if (packetId == PING){
            int64_t value = protocol::Util::readLong(data, &offset, dataLength);
            return new PacketStatusInPing(value);
        }
        throw UnknownPacketException(packetId, STATUS, dataLength);
    }

    PacketInBase *
    PacketParser::_parsePlay(int packetId, unsigned char *data, int dataLength) {
        uint32_t offset = 0;
        if (packetId == SERVER_PLUGIN_MESSAGE){
            Identifier ident = Identifier(Util::readString(data, &offset, dataLength));
            uint32_t inferredDataLength = dataLength - offset;
            uint8_t *data = Util::readByteArray(data, dataLength, &offset, inferredDataLength);
            return new PacketPlayInPluginMessage(ident, inferredDataLength, data);
        }
        throw UnknownPacketException(packetId, PLAY, dataLength);
    }

    PacketInBase *
    PacketParser::_parseLogin(int packetId, unsigned char *data, int dataLength) {
        uint32_t offset = 0;
        if (packetId == LOGIN_START) {
            std::string name = protocol::Util::readString(data, &offset, dataLength);
            return new PacketInLoginStart(name);
        } else if (packetId == ENCRYPTION_RESPONSE) {
            int32_t keyLength = protocol::Util::readVarInt(data, &offset, dataLength);
            uint8_t *keyData = protocol::Util::readByteArray(data, dataLength, &offset, keyLength);
            uint32_t tokenLength = protocol::Util::readVarInt(data, &offset, dataLength);
            uint8_t *tokenData = protocol::Util::readByteArray(data, dataLength, &offset, tokenLength);
            return new PacketLoginInEncryptionResponse(keyLength, keyData, tokenLength, tokenData);
        } else if (packetId == LOGIN_PLUGIN_RESPONSE) {

        }
        throw UnknownPacketException(packetId, LOGIN, dataLength);
    }
}
