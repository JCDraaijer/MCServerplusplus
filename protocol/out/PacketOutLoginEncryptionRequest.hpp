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

#ifndef MCSERVER_PACKETOUTLOGINENCRYPTIONREQUEST_HPP
#define MCSERVER_PACKETOUTLOGINENCRYPTIONREQUEST_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutLoginEncryptionRequest : public PacketOutBase {
    private:
        std::string serverId;
        int32_t publicKeyLength;
        uint8_t *publicKey;
        int32_t verifyTokenLength;
        uint8_t *verifyToken;
    public:
        PacketOutLoginEncryptionRequest(std::string serverId, int32_t publicKeyLength, uint8_t *publicKey, int32_t verifyTokenLength, uint8_t *verifyToken);

        ~PacketOutLoginEncryptionRequest() override;

        void serialize(PacketSerializer *packetSerializer) override;

        const std::string &getServerId() const;

        void setServerId(const std::string &serverId);

        int32_t getPublicKeyLength() const;

        void setPublicKeyLength(int32_t publicKeyLength);

        uint8_t *getPublicKey() const;

        void setPublicKey(uint8_t *publicKey);

        int32_t getVerifyTokenLength() const;

        void setVerifyTokenLength(int32_t verifyTokenLength);

        uint8_t *getVerifyToken() const;

        void setVerifyToken(uint8_t *verifyToken);
    };
}


#endif //MCSERVER_PACKETOUTLOGINENCRYPTIONREQUEST_HPP
