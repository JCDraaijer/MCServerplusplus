//
// Created by jona on 2019-06-10.
//

#ifndef MCSERVER_PACKETOUTPONG_HPP
#define MCSERVER_PACKETOUTPONG_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutPong : public PacketOutBase {
    private:
        int64_t value;
    public:
        explicit PacketOutPong(int64_t value);
        std::string toString() override;
        int64_t getValue();
    };
}


#endif //MCSERVER_PACKETOUTPONG_HPP
