#include <utility>

//
// Created by jona on 2019-06-11.
//

#include "PacketLoginOutEncryptionRequest.hpp"


namespace protocol {

    const std::string &PacketLoginOutEncryptionRequest::getServerId() const {
        return serverId;
    }

    void PacketLoginOutEncryptionRequest::setServerId(const std::string &newServerId) {
        this->serverId = newServerId;
    }

    int32_t PacketLoginOutEncryptionRequest::getPublicKeyLength() const {
        return publicKeyLength;
    }

    void PacketLoginOutEncryptionRequest::setPublicKeyLength(int32_t newLength) {
        this->publicKeyLength = newLength;
    }

    uint8_t *PacketLoginOutEncryptionRequest::getPublicKey() const {
        return publicKey;
    }

    void PacketLoginOutEncryptionRequest::setPublicKey(uint8_t *newKey) {
        this->publicKey = newKey;
    }

    int32_t PacketLoginOutEncryptionRequest::getVerifyTokenLength() const {
        return verifyTokenLength;
    }

    void PacketLoginOutEncryptionRequest::setVerifyTokenLength(int32_t newTokenLength) {
        this->verifyTokenLength = newTokenLength;
    }

    uint8_t *PacketLoginOutEncryptionRequest::getVerifyToken() const {
        return verifyToken;
    }

    void PacketLoginOutEncryptionRequest::setVerifyToken(uint8_t *newToken) {
        this->verifyToken = newToken;
    }

    PacketLoginOutEncryptionRequest::~PacketLoginOutEncryptionRequest() {
        free(publicKey);
        free(verifyToken);
    }

    PacketLoginOutEncryptionRequest::PacketLoginOutEncryptionRequest(std::string serverId, int32_t publicKeyLength,
                                                           uint8_t *publicKey, int32_t verifyTokenLength,
                                                           uint8_t *verifyToken) : PacketOutBase(LOGIN_ENCRYPTION_REQUEST),
                                                                                   serverId(std::move(serverId)),
                                                                                   publicKeyLength(publicKeyLength),
                                                                                   publicKey(publicKey),
                                                                                   verifyTokenLength(verifyTokenLength),
                                                                                   verifyToken(verifyToken) {

    }

    void PacketLoginOutEncryptionRequest::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeString(serverId);
        packetSerializer->writeVarInt(publicKeyLength);
        packetSerializer->writeByteArray(publicKey, publicKeyLength);
        packetSerializer->writeVarInt(verifyTokenLength);
        packetSerializer->writeByteArray(verifyToken, verifyTokenLength);
    }
}