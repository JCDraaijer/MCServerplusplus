//
// Created by jona on 2019-06-13.
//

#include "Block.hpp"

namespace server {

    Block::Block(Material material) : material(material) {

    }

    Material Block::getMaterial() {
        return material;
    }

    void Block::setMaterial(Material newMaterial) {
        this->material = newMaterial;
    }

    Block::Block() : Block(AIR) {

    }

}