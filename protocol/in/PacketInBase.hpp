//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_PACKETINBASE_HPP
#define MCSERVER_PACKETINBASE_HPP

#include <string>
#include "../PacketBase.hpp"

namespace protocol {

    class PacketInBase : public PacketBase {
    private:
        const InPacketType type;
    public:
        explicit PacketInBase(InPacketType type);

        InPacketType getType();

    };
}

#endif //MCSERVER_PACKETINBASE_HPP
