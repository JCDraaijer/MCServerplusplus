//
// Created by jona on 2019-06-11.
//

#include "PacketInLoginEncryptionResponse.hpp"

namespace protocol {
    protocol::PacketInLoginEncryptionResponse::PacketInLoginEncryptionResponse(int32_t sharedSecretLength,
                                                                               uint8_t *sharedSecret,
                                                                               uint32_t verifyTokenLength,
                                                                               uint8_t *verifyToken)
            : PacketInBase(ENCRYPTION_RESPONSE), sharedSecretLength(sharedSecretLength),
              sharedSecret(sharedSecret), verifyTokenLength(verifyTokenLength), verifyToken(verifyToken) {

    }

    PacketInLoginEncryptionResponse::~PacketInLoginEncryptionResponse() {
        free(sharedSecret);
        free(verifyToken);
    }

    int32_t PacketInLoginEncryptionResponse::getSharedSecretLength() const {
        return sharedSecretLength;
    }

    uint8_t *PacketInLoginEncryptionResponse::getSharedSecret() const {
        return sharedSecret;
    }

    int32_t PacketInLoginEncryptionResponse::getVerifyTokenLength() const {
        return verifyTokenLength;
    }

    uint8_t *PacketInLoginEncryptionResponse::getVerifyToken() const {
        return verifyToken;
    }

    std::string PacketInLoginEncryptionResponse::toString() {
        return std::__cxx11::string();
    }

    PacketInLoginEncryptionResponse::PacketInLoginEncryptionResponse(PacketParser *parser) : PacketInBase(
            ENCRYPTION_RESPONSE) {
        parse(parser);
    }

    void PacketInLoginEncryptionResponse::parse(PacketParser *packetParser) {
        sharedSecretLength = packetParser->readVarInt();
        sharedSecret = packetParser->readByteArray(sharedSecretLength);
        verifyTokenLength = packetParser->readVarInt();
        verifyToken = packetParser->readByteArray(verifyTokenLength);
    }

}
