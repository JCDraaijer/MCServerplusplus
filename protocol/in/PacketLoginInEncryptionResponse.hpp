//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETLOGININENCRYPTIONRESPONSE_HPP
#define MCSERVER_PACKETLOGININENCRYPTIONRESPONSE_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketLoginInEncryptionResponse : public PacketInBase {
    private:
        int32_t sharedSecretLength;
        uint8_t *sharedSecret;
        int32_t verifyTokenLength;
        uint8_t *verifyToken;
    public:
        PacketLoginInEncryptionResponse(int32_t sharedSecretLength, uint8_t *sharedSecret, uint32_t verifyTokenLength, uint8_t *verifyToken);
        ~PacketLoginInEncryptionResponse();

        int32_t getSharedSecretLength() const;

        uint8_t *getSharedSecret() const;

        explicit PacketLoginInEncryptionResponse(PacketParser *parser);

        void parse(PacketParser *packetParser) override;

        int32_t getVerifyTokenLength() const;

        uint8_t *getVerifyToken() const;

        std::string toString() override;
    };
}


#endif //MCSERVER_PACKETLOGININENCRYPTIONRESPONSE_HPP
