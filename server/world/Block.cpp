//
// Created by jona on 2019-06-13.
//

#include "Block.hpp"

namespace server {

    Block::Block(Material material, BlockLocation location) : material(material), location(location) {

    }

    BlockLocation Block::getLocation() {
        return location;
    }

    Material Block::getMaterial() {
        return material;
    }

    void Block::setMaterial(Material newMaterial) {
        this->material = newMaterial;
    }

    Block::Block() : material(AIR), location(BlockLocation(0, 0, 0)) {

    }
}