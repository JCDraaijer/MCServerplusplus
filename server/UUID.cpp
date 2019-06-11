//
// Created by jona on 2019-06-02.
//

#include "UUID.hpp"

namespace server {
    UUID::UUID(uint64_t mostSignificant, uint64_t leastSignificant) : mostSignificant(mostSignificant),
                                                                      leastSignificant(leastSignificant) {

    }

    bool UUID::equals(UUID &anotherUuid) {
        return anotherUuid.mostSignificant == this->mostSignificant &&
               anotherUuid.leastSignificant == this->leastSignificant;
    }

    std::string UUID::toString() {
        return "e67a1fd6-b40c-486c-b94e-eb0c4661fb4f";
    }
}