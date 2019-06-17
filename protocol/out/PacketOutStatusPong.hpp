//
// Created by jona on 2019-06-10.
//

#ifndef MCSERVER_PACKETOUTSTATUSPONG_HPP
#define MCSERVER_PACKETOUTSTATUSPONG_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketOutStatusPong : public PacketOutBase {
    private:
        int64_t value;
    public:
        explicit PacketOutStatusPong(int64_t value);

        std::string toString() override;

        int64_t getValue();

        ~PacketOutStatusPong() override;

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETOUTSTATUSPONG_HPP
