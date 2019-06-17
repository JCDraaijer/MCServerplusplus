//
// Created by jona on 2019-06-11.
//

#ifndef MCSERVER_PACKETOUTLOGINSETCOMPRESSION_HPP
#define MCSERVER_PACKETOUTLOGINSETCOMPRESSION_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutLoginSetCompression : public PacketOutBase {
    private:
        int32_t threshold;
    public:
        explicit PacketOutLoginSetCompression(int32_t threshold);
        int32_t getThreshold();

        void setThreshold(int32_t newThreshold);

        ~PacketOutLoginSetCompression() override;

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETOUTLOGINSETCOMPRESSION_HPP
