//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETOUTSETCOMPRESSION_HPP
#define MCSERVER_PACKETOUTSETCOMPRESSION_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutSetCompression : public PacketOutBase {
    private:
        int32_t threshold;
    public:
        explicit PacketOutSetCompression(int32_t threshold);
        int32_t getThreshold();

        void setThreshold(int32_t newThreshold);
    };
}


#endif //MCSERVER_PACKETOUTSETCOMPRESSION_HPP
