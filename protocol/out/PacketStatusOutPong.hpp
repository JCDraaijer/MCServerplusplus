//
// Created by jona on 2019-06-10.
//

#ifndef MCSERVER_PACKETSTATUSOUTPONG_HPP
#define MCSERVER_PACKETSTATUSOUTPONG_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketStatusOutPong : public PacketOutBase {
    private:
        int64_t value;
    public:
        explicit PacketStatusOutPong(int64_t value);

        std::string toString() override;

        int64_t getValue();

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETSTATUSOUTPONG_HPP
