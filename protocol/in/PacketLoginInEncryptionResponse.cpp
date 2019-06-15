//
// Created by jona on 2019-06-11.
//

#include "PacketLoginInEncryptionResponse.hpp"

namespace protocol {
    protocol::PacketLoginInEncryptionResponse::PacketLoginInEncryptionResponse(int32_t sharedSecretLength,
                                                                               uint8_t *sharedSecret,
                                                                               uint32_t verifyTokenLength,
                                                                               uint8_t *verifyToken)
            : PacketInBase(ENCRYPTION_RESPONSE), sharedSecretLength(sharedSecretLength),
              sharedSecret(sharedSecret), verifyTokenLength(verifyTokenLength), verifyToken(verifyToken) {

    }

    PacketLoginInEncryptionResponse::~PacketLoginInEncryptionResponse() {
        free(sharedSecret);
        free(verifyToken);
    }

    int32_t PacketLoginInEncryptionResponse::getSharedSecretLength() const {
        return sharedSecretLength;
    }

    uint8_t *PacketLoginInEncryptionResponse::getSharedSecret() const {
        return sharedSecret;
    }

    int32_t PacketLoginInEncryptionResponse::getVerifyTokenLength() const {
        return verifyTokenLength;
    }

    uint8_t *PacketLoginInEncryptionResponse::getVerifyToken() const {
        return verifyToken;
    }

    std::string PacketLoginInEncryptionResponse::toString() {
        return std::__cxx11::string();
    }

    PacketLoginInEncryptionResponse::PacketLoginInEncryptionResponse(PacketParser *parser) : PacketInBase(
            ENCRYPTION_RESPONSE) {
        parse(parser);
    }

    void PacketLoginInEncryptionResponse::parse(PacketParser *packetParser) {
        sharedSecretLength = packetParser->readVarInt();
        sharedSecret = packetParser->readByteArray(sharedSecretLength);
        verifyTokenLength = packetParser->readVarInt();
        verifyToken = packetParser->readByteArray(verifyTokenLength);
    }

}
