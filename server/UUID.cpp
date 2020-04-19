/*
MCpp, a Minecraft Server implementation in C++.
Copyright (C) 2019, 2020 Johannes Draaijer

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


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