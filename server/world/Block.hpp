//
// Created by jona on 2019-06-13.
//

#ifndef MCSERVER_BLOCK_HPP
#define MCSERVER_BLOCK_HPP

#include "../Material.hpp"
#include "BlockLocation.hpp"

namespace server {
    class Block {
    private:
        Material material;
        BlockLocation location;
    public:
        explicit Block();

        explicit Block(Material material, BlockLocation location);

        Material getMaterial();

        void setMaterial(Material newMaterial);

        BlockLocation getLocation();
    };
}


#endif //MCSERVER_BLOCK_HPP
