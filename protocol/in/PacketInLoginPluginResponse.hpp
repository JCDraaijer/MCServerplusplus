//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETINLOGINPLUGINRESPONSE_HPP
#define MCSERVER_PACKETINLOGINPLUGINRESPONSE_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketInLoginPluginResponse : public PacketInBase {
    private:
        int32_t messageId;
        bool successful;
        uint8_t *data;
        uint32_t dataLength;
    public:
        PacketInLoginPluginResponse(int32_t messageId, bool succesful, uint32_t dataLength, uint8_t *data);

        int32_t getMessageId() const;

        bool isSuccessful() const;

        uint8_t *getData() const;

        uint32_t getDataLength() const;

        std::string toString() override;

        explicit PacketInLoginPluginResponse(PacketParser *parser);

        void parse(PacketParser *packetParser) override;
    };
}


#endif //MCSERVER_PACKETINLOGINPLUGINRESPONSE_HPP
