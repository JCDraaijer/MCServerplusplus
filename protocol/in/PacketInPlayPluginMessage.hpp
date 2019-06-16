//
// Created by jona on 2019-06-15.
//

#ifndef MCSERVER_PACKETINPLAYPLUGINMESSAGE_HPP
#define MCSERVER_PACKETINPLAYPLUGINMESSAGE_HPP

#include "PacketInBase.hpp"
#include "../Identifier.hpp"

namespace protocol {
    class PacketInPlayPluginMessage : public PacketInBase {
    private:
        Identifier identifier;
        uint8_t *data;
        uint32_t dataLength;
    public:
        PacketInPlayPluginMessage(Identifier ident, uint32_t dataLength, uint8_t *data);
        uint8_t *getData();

        explicit PacketInPlayPluginMessage(PacketParser *parser);

        ~PacketInPlayPluginMessage();

        void parse(PacketParser *packetParser) override;

        std::string toString() override;

        Identifier *getIdentifier();

        uint32_t getDataLength();
    };
}


#endif //MCSERVER_PACKETINPLAYPLUGINMESSAGE_HPP
