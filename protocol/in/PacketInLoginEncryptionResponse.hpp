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


#ifndef MCSERVER_PACKETINLOGINENCRYPTIONRESPONSE_HPP
#define MCSERVER_PACKETINLOGINENCRYPTIONRESPONSE_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketInLoginEncryptionResponse : public PacketInBase {
    private:
        int32_t sharedSecretLength;
        uint8_t *sharedSecret;
        int32_t verifyTokenLength;
        uint8_t *verifyToken;
    public:
        PacketInLoginEncryptionResponse(int32_t sharedSecretLength, uint8_t *sharedSecret, uint32_t verifyTokenLength, uint8_t *verifyToken);
        ~PacketInLoginEncryptionResponse();

        int32_t getSharedSecretLength() const;

        uint8_t *getSharedSecret() const;

        explicit PacketInLoginEncryptionResponse(PacketParser *parser);

        void parse(PacketParser *packetParser) override;

        int32_t getVerifyTokenLength() const;

        uint8_t *getVerifyToken() const;

        std::string toString() override;
    };
}


#endif //MCSERVER_PACKETINLOGINENCRYPTIONRESPONSE_HPP
