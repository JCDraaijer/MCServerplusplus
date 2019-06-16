//
// Created by jona on 2019-06-02.
//

#include "UUID.hpp"

namespace server {
    UUID::UUID(uint64_t mostSignificant, uint64_t leastSignificant) {
        for (int i = 0; i < 8; i++) {
            actualUuid[i] = leastSignificant & 0xFF;
            actualUuid[i + 8] = mostSignificant & 0xFF;
            leastSignificant >>= 8;
            mostSignificant >>= 8;
        }
    }


    bool UUID::equals(UUID &anotherUuid) {
        for (int i = 0; i < sizeof(uuid_t); i++) {
            if (anotherUuid.actualUuid[i] != actualUuid[i]) {
                return false;
            }
        }
        return true;
    }

    std::string UUID::toString() {
        char *uuidString = (char *) (malloc(sizeof(uuid_t) * 37));
        uuid_unparse_lower(actualUuid, uuidString);
        std::string properString = std::string(uuidString);
        free(uuidString);
        return properString;
    }

    UUID UUID::randomUuid() {
        uuid_t uuidType;
        uuid_generate_random(uuidType);
        return UUID(uuidType);
    }

    UUID::UUID() : UUID(0, 0) {
    }

    UUID::UUID(const uuid_t theUuid) {
        for (int i = 0; i < sizeof(uuid_t); i++) {
            actualUuid[i] = theUuid[i];
        }
    }
}