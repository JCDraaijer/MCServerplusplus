//
// Created by jona on 2019-06-15.
//

#ifndef MCSERVER_PACKETINPLAYCLIENTSETTINGS_HPP
#define MCSERVER_PACKETINPLAYCLIENTSETTINGS_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketInPlayClientSettings : public PacketInBase {
    private:
        std::string locale;
        int8_t renderDistance;
        int32_t chatMode;
        bool chatColors;
        uint8_t skinParts;
        int32_t mainHand;

    public:
        std::string toString() override;

        explicit PacketInPlayClientSettings(PacketParser *parser);

        void parse(PacketParser *packetParser) override;
    };
}


#endif //MCSERVER_PACKETINPLAYCLIENTSETTINGS_HPP
