//
// Created by jona on 2019-06-16.
//

#ifndef MCSERVER_PACKETINPLAYTELEPORTCONFIRM_HPP
#define MCSERVER_PACKETINPLAYTELEPORTCONFIRM_HPP

#include "PacketInBase.hpp"

namespace protocol {
    class PacketInPlayTeleportConfirm : public PacketInBase {
    private:
        int32_t teleportId;
    public:
        explicit PacketInPlayTeleportConfirm(int32_t teleportId);

        explicit PacketInPlayTeleportConfirm(PacketParser *parser);

        std::string toString() override;

        void parse(PacketParser *packetParser) override;
    };
}


#endif //MCSERVER_PACKETINPLAYTELEPORTCONFIRM_HPP
