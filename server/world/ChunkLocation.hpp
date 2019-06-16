//
// Created by jona on 2019-06-16.
//

#ifndef MCSERVER_CHUNKLOCATION_HPP
#define MCSERVER_CHUNKLOCATION_HPP

#include <cstdint>

namespace server {
    class ChunkLocation {
    private:
        uint32_t x;
        uint32_t z;
    public:
        ChunkLocation(uint32_t x, uint32_t z);

        const uint32_t &getX() const;
        const uint32_t &getZ() const;
    };
}


#endif //MCSERVER_CHUNKLOCATION_HPP
