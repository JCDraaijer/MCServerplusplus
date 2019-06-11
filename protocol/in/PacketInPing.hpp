//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETINPING_HPP
#define MCSERVER_PACKETINPING_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketInPing : public PacketInBase {
    private:
        int64_t mvalue;
    public:
        explicit PacketInPing(int64_t);

        std::string toString() override;

        const int64_t getValue();
    };
}


#endif //MCSERVER_PACKETINPING_HPP
