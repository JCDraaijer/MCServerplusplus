//
// Created by jona on 2019-06-15.
//

#ifndef MCSERVER_PACKETPLAYINCLIENTSETTINGS_HPP
#define MCSERVER_PACKETPLAYINCLIENTSETTINGS_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketPlayInClientSettings : public PacketInBase {
    private:
        std::string locale;
        int8_t renderDistance;
        int32_t chatMode;
        bool chatColors;
        uint8_t skinParts;
        int32_t mainHand;

    public:
        std::string toString() override;

        explicit PacketPlayInClientSettings(PacketParser *parser);

        void parse(PacketParser *packetParser) override;
    };
}


#endif //MCSERVER_PACKETPLAYINCLIENTSETTINGS_HPP
