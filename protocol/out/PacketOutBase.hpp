//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETOUTBASE_HPP
#define MCSERVER_PACKETOUTBASE_HPP

#include "../PacketBase.hpp"

namespace protocol {

    class PacketOutBase : public PacketBase {
    private:
        const protocol::OutPacketType type;
    public:
        explicit PacketOutBase(int id, OutPacketType type);

        const OutPacketType getType();

        std::string toString() override;

    };
}


#endif //MCSERVER_PACKETOUTBASE_HPP
