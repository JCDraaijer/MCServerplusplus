//
// Created by jona on 2019-06-15.
//

#ifndef MCSERVER_PACKETPLAYINPLUGINMESSAGE_HPP
#define MCSERVER_PACKETPLAYINPLUGINMESSAGE_HPP

#include "PacketInBase.hpp"
#include "../Identifier.hpp"

namespace protocol {
    class PacketPlayInPluginMessage : public PacketInBase {
    private:
        Identifier identifier;
        uint8_t *data;
        uint32_t dataLength;
    public:
        PacketPlayInPluginMessage(Identifier ident, uint32_t dataLength, uint8_t *data);
        uint8_t *getData();

        explicit PacketPlayInPluginMessage(PacketParser *parser);

        void parse(PacketParser *packetParser) override;

        std::string toString() override;

        Identifier *getIdentifier();
    };
}


#endif //MCSERVER_PACKETPLAYINPLUGINMESSAGE_HPP
