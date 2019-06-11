//
// Created by jona on 2019-06-11.
//

#include "PacketInEncryptionResponse.hpp"

namespace protocol {
    protocol::PacketInEncryptionResponse::PacketInEncryptionResponse(int32_t sharedSecretLength, uint8_t *sharedSecret,
                                                                     uint32_t verifyTokenLength, uint8_t *verifyToken)
            : PacketInBase(0x01, ENCRYPTION_RESPONSE), sharedSecretLength(sharedSecretLength),
              sharedSecret(sharedSecret), verifyTokenLength(verifyTokenLength), verifyToken(verifyToken) {

    }

    PacketInEncryptionResponse::~PacketInEncryptionResponse() {
        free(sharedSecret);
        free(verifyToken);
    }

    int32_t PacketInEncryptionResponse::getSharedSecretLength() const {
        return sharedSecretLength;
    }

    uint8_t *PacketInEncryptionResponse::getSharedSecret() const {
        return sharedSecret;
    }

    int32_t PacketInEncryptionResponse::getVerifyTokenLength() const {
        return verifyTokenLength;
    }

    uint8_t *PacketInEncryptionResponse::getVerifyToken() const {
        return verifyToken;
    }

    std::string PacketInEncryptionResponse::toString() {
        return std::__cxx11::string();
    }

}
