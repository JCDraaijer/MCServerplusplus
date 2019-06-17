//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETOUTBASE_HPP
#define MCSERVER_PACKETOUTBASE_HPP

#include "../PacketBase.hpp"
#include "../PacketSerializer.hpp"

namespace protocol {

    class PacketSerializer;

    class PacketOutBase : public PacketBase {
    private:
        const OutPacketType type;
    public:
        explicit PacketOutBase(OutPacketType type);

        const OutPacketType getType();

        std::string toString() override;

        virtual void serialize(PacketSerializer *packetSerializer) = 0;

        virtual ~PacketOutBase();
    };
}


#endif //MCSERVER_PACKETOUTBASE_HPP
