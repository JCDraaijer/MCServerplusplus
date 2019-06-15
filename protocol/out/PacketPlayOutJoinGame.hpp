//
// Created by jona on 2019-06-14.
//

#ifndef MCSERVER_PACKETPLAYOUTJOINGAME_HPP
#define MCSERVER_PACKETPLAYOUTJOINGAME_HPP

#include "PacketOutBase.hpp"

namespace protocol {
    class PacketPlayOutJoinGame : public PacketOutBase {
    private:
        int32_t entityId;
        uint8_t gameMode;
        int32_t dimension;
        uint8_t difficulty;
        uint8_t maxPlayers;
        std::string levelType;
        bool reducedDebugInfo;
    public:
        PacketPlayOutJoinGame(int32_t entityId, uint8_t gameMode, int32_t dimension,
                              uint8_t difficulty, uint8_t maxPlayers, std::string levelType,
                              bool reducedDebugInfo);

        void serialize(PacketSerializer *packetSerializer) override;
    };
}


#endif //MCSERVER_PACKETPLAYOUTJOINGAME_HPP
