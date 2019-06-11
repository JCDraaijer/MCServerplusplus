//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETOUTENCRYPTIONREQUEST_HPP
#define MCSERVER_PACKETOUTENCRYPTIONREQUEST_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutEncryptionRequest : public PacketOutBase {
    private:
        std::string serverId;
        int32_t publicKeyLength;
        uint8_t *publicKey;
        int32_t verifyTokenLength;
        uint8_t *verifyToken;
    public:
        PacketOutEncryptionRequest(std::string serverId, int32_t publicKeyLength, uint8_t *publicKey, int32_t verifyTokenLength, uint8_t *verifyToken);
        ~PacketOutEncryptionRequest();

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


#endif //MCSERVER_PACKETOUTENCRYPTIONREQUEST_HPP
