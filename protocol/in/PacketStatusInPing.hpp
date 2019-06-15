//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETSTATUSINPING_HPP
#define MCSERVER_PACKETSTATUSINPING_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketStatusInPing : public PacketInBase {
    private:
        int64_t mvalue;
    public:
        explicit PacketStatusInPing(int64_t);

        std::string toString() override;

        const int64_t getValue();
    };
}


#endif //MCSERVER_PACKETSTATUSINPING_HPP
