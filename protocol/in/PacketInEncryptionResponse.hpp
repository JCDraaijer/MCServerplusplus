//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETINENCRYPTIONRESPONSE_HPP
#define MCSERVER_PACKETINENCRYPTIONRESPONSE_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketInEncryptionResponse : public PacketInBase {
    private:
        int32_t sharedSecretLength;
        uint8_t *sharedSecret;
        int32_t verifyTokenLength;
        uint8_t *verifyToken;
    public:
        PacketInEncryptionResponse(int32_t sharedSecretLength, uint8_t *sharedSecret, uint32_t verifyTokenLength, uint8_t *verifyToken);
        ~PacketInEncryptionResponse();

        int32_t getSharedSecretLength() const;

        uint8_t *getSharedSecret() const;

        int32_t getVerifyTokenLength() const;

        uint8_t *getVerifyToken() const;

        std::string toString() override;
    };
}


#endif //MCSERVER_PACKETINENCRYPTIONRESPONSE_HPP
