//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETLOGINOUTSETCOMPRESSION_HPP
#define MCSERVER_PACKETLOGINOUTSETCOMPRESSION_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketLoginOutSetCompression : public PacketOutBase {
    private:
        int32_t threshold;
    public:
        explicit PacketLoginOutSetCompression(int32_t threshold);
        int32_t getThreshold();

        void setThreshold(int32_t newThreshold);

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETLOGINOUTSETCOMPRESSION_HPP
