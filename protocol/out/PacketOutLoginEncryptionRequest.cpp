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