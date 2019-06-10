//
// Created by jona on 2019-06-09.
//

#include "Base.hpp"

namespace packet {
    int Base::getId() {
        return this->id;
    }

    Base::Base(int id) : id(id) {

    }
}