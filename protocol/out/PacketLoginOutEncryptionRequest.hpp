//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETLOGINOUTENCRYPTIONREQUEST_HPP
#define MCSERVER_PACKETLOGINOUTENCRYPTIONREQUEST_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketLoginOutEncryptionRequest : public PacketOutBase {
    private:
        std::string serverId;
        int32_t publicKeyLength;
        uint8_t *publicKey;
        int32_t verifyTokenLength;
        uint8_t *verifyToken;
    public:
        PacketLoginOutEncryptionRequest(std::string serverId, int32_t publicKeyLength, uint8_t *publicKey, int32_t verifyTokenLength, uint8_t *verifyToken);
        ~PacketLoginOutEncryptionRequest();

        const std::string &getServerId() const;

        void setServerId(const std::string &serverId);

        int32_t getPublicKeyLength() const;

        void setPublicKeyLength(int32_t publicKeyLength);

        uint8_t *getPublicKey() const;

        void setPublicKey(uint8_t *publicKey);

        int32_t getVerifyTokenLength() const;

        void setVerifyTokenLength(int32_t verifyTokenLength);

        void serialize(PacketSerializer *packetSerializer) override;

        uint8_t *getVerifyToken() const;

        void setVerifyToken(uint8_t *verifyToken);
    };
}


#endif //MCSERVER_PACKETLOGINOUTENCRYPTIONREQUEST_HPP
