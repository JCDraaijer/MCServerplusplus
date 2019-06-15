//
// Created by jona on 2019-06-11.
//

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
