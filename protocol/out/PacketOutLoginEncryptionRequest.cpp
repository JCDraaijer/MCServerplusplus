#include <utility>

//
// Created by jona on 2019-06-11.
//

#include "PacketOutLoginEncryptionRequest.hpp"


namespace protocol {

    const std::string &PacketOutLoginEncryptionRequest::getServerId() const {
        return serverId;
    }

    void PacketOutLoginEncryptionRequest::setServerId(const std::string &newServerId) {
        this->serverId = newServerId;
    }

    int32_t PacketOutLoginEncryptionRequest::getPublicKeyLength() const {
        return publicKeyLength;
    }

    void PacketOutLoginEncryptionRequest::setPublicKeyLength(int32_t newLength) {
        this->publicKeyLength = newLength;
    }

    uint8_t *PacketOutLoginEncryptionRequest::getPublicKey() const {
        return publicKey;
    }

    void PacketOutLoginEncryptionRequest::setPublicKey(uint8_t *newKey) {
        this->publicKey = newKey;
    }

    int32_t PacketOutLoginEncryptionRequest::getVerifyTokenLength() const {
        return verifyTokenLength;
    }

    void PacketOutLoginEncryptionRequest::setVerifyTokenLength(int32_t newTokenLength) {
        this->verifyTokenLength = newTokenLength;
    }

    uint8_t *PacketOutLoginEncryptionRequest::getVerifyToken() const {
        return verifyToken;
    }

    void PacketOutLoginEncryptionRequest::setVerifyToken(uint8_t *newToken) {
        this->verifyToken = newToken;
    }

    PacketOutLoginEncryptionRequest::~PacketOutLoginEncryptionRequest() {
        free(publicKey);
        free(verifyToken);
    }

    PacketOutLoginEncryptionRequest::PacketOutLoginEncryptionRequest(std::string serverId, int32_t publicKeyLength,
                                                           uint8_t *publicKey, int32_t verifyTokenLength,
                                                           uint8_t *verifyToken) : PacketOutBase(LOGIN_ENCRYPTION_REQUEST),
                                                                                   serverId(std::move(serverId)),
                                                                                   publicKeyLength(publicKeyLength),
                                                                                   publicKey(publicKey),
                                                                                   verifyTokenLength(verifyTokenLength),
                                                                                   verifyToken(verifyToken) {

    }

    void PacketOutLoginEncryptionRequest::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeString(serverId);
        packetSerializer->writeVarInt(publicKeyLength);
        packetSerializer->writeByteArray(publicKey, publicKeyLength);
        packetSerializer->writeVarInt(verifyTokenLength);
        packetSerializer->writeByteArray(verifyToken, verifyTokenLength);
    }
}