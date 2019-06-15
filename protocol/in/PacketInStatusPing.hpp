//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETINSTATUSPING_HPP
#define MCSERVER_PACKETINSTATUSPING_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketInStatusPing : public PacketInBase {
    private:
        int64_t mvalue;
    public:
        explicit PacketInStatusPing(int64_t);

        explicit PacketInStatusPing(PacketParser *parser);

        void parse(PacketParser *packetParser) override;

        std::string toString() override;

        const int64_t getValue();
    };
}


#endif //MCSERVER_PACKETINSTATUSPING_HPP
