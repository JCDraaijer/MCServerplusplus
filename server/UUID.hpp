//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_UUID_HPP
#define MCSERVER_UUID_HPP


#include <cstdint>
#include <string>
#include <uuid/uuid.h>

namespace server {
    class UUID {
    private:
        uuid_t actualUuid{};
    public:
        UUID();

        explicit UUID(const uuid_t uuid);

        UUID(uint64_t mostSignificant, uint64_t leastSignificant);


        std::string toString();

        bool equals(UUID &anotherUuid);

        static UUID randomUuid();
    };
}


#endif //MCSERVER_UUID_HPP
