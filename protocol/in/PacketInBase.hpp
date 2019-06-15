//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_PACKETINBASE_HPP
#define MCSERVER_PACKETINBASE_HPP

#include <string>
#include "../PacketBase.hpp"
#include "../PacketParser.hpp"

namespace protocol {

    class PacketParser;

    class PacketInBase : public PacketBase {
    private:
        const InPacketType type;
    public:
        explicit PacketInBase(InPacketType type);

        //virtual explicit PacketInBase(PacketParser *parser) = 0;

        InPacketType getType();

        virtual void parse(PacketParser *packetParser) = 0;

    };
}

#endif //MCSERVER_PACKETINBASE_HPP
