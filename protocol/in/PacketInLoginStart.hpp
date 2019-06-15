//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETINLOGINSTART_HPP
#define MCSERVER_PACKETINLOGINSTART_HPP

#include "PacketInBase.hpp"

namespace protocol{
    class PacketInLoginStart : public PacketInBase {
    private:
        std::string name;
    public:
        explicit PacketInLoginStart(std::string name);

        std::string getName();

        explicit PacketInLoginStart(PacketParser *parser);

        void parse(PacketParser *packetParser) override;

        std::string toString() override;
    };
}


#endif //MCSERVER_PACKETINLOGINSTART_HPP
