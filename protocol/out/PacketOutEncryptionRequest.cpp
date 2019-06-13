#include <utility>

//
// Created by jona on 2019-06-11.
//

#include "PacketOutEncryptionRequest.hpp"


namespace protocol {

    const std::string &PacketOutEncryptionRequest::getServerId() const {
        return serverId;
    }

    void PacketOutEncryptionRequest::setServerId(const std::string &newServerId) {
        this->serverId = newServerId;
    }

    int32_t PacketOutEncryptionRequest::getPublicKeyLength() const {
        return publicKeyLength;
    }

    void PacketOutEncryptionRequest::setPublicKeyLength(int32_t newLength) {
        this->publicKeyLength = newLength;
    }

    uint8_t *PacketOutEncryptionRequest::getPublicKey() const {
        return publicKey;
    }

    void PacketOutEncryptionRequest::setPublicKey(uint8_t *newKey) {
        this->publicKey = newKey;
    }

    int32_t PacketOutEncryptionRequest::getVerifyTokenLength() const {
        return verifyTokenLength;
    }

    void PacketOutEncryptionRequest::setVerifyTokenLength(int32_t newTokenLength) {
        this->verifyTokenLength = newTokenLength;
    }

    uint8_t *PacketOutEncryptionRequest::getVerifyToken() const {
        return verifyToken;
    }

    void PacketOutEncryptionRequest::setVerifyToken(uint8_t *newToken) {
        this->verifyToken = newToken;
    }

    PacketOutEncryptionRequest::~PacketOutEncryptionRequest() {
        free(publicKey);
        free(verifyToken);
    }

    PacketOutEncryptionRequest::PacketOutEncryptionRequest(std::string serverId, int32_t publicKeyLength,
                                                           uint8_t *publicKey, int32_t verifyTokenLength,
                                                           uint8_t *verifyToken) : PacketOutBase(1, ENCRYPTION_REQUEST),
                                                                                   serverId(std::move(serverId)),
                                                                                   publicKeyLength(publicKeyLength),
                                                                                   publicKey(publicKey),
                                                                                   verifyTokenLength(verifyTokenLength),
                                                                                   verifyToken(verifyToken) {

    }

    void PacketOutEncryptionRequest::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeString(serverId);
        packetSerializer->writeVarInt(publicKeyLength);
        packetSerializer->writeByteArray(publicKey, publicKeyLength);
        packetSerializer->writeVarInt(verifyTokenLength);
        packetSerializer->writeByteArray(verifyToken, verifyTokenLength);
    }
}