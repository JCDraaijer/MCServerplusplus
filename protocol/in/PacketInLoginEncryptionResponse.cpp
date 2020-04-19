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


#include "PacketInLoginEncryptionResponse.hpp"

namespace protocol {
    PacketInLoginEncryptionResponse::PacketInLoginEncryptionResponse(int32_t sharedSecretLength,
                                                                     uint8_t *sharedSecret,
                                                                     uint32_t verifyTokenLength,
                                                                     uint8_t *verifyToken)
            : PacketInBase(ENCRYPTION_RESPONSE) {
        this->sharedSecretLength = sharedSecretLength;
        this->sharedSecret = sharedSecret;
        this->verifyTokenLength = verifyTokenLength;
        this->verifyToken = verifyToken;

    }

    PacketInLoginEncryptionResponse::PacketInLoginEncryptionResponse() :
            PacketInLoginEncryptionResponse(0, nullptr, 0, nullptr) {
    }

    PacketInLoginEncryptionResponse::~PacketInLoginEncryptionResponse() {
        free(sharedSecret);
        free(verifyToken);
    }

    void PacketInLoginEncryptionResponse::parse(PacketParser *packetParser) {
        sharedSecretLength = packetParser->readVarInt();
        sharedSecret = packetParser->readByteArray(sharedSecretLength);
        verifyTokenLength = packetParser->readVarInt();
        verifyToken = packetParser->readByteArray(verifyTokenLength);
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
        return std::string();
    }

}
