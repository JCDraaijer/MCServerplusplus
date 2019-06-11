//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_UUID_HPP
#define MCSERVER_UUID_HPP


#include <cstdint>
#include <string>

namespace server {
    class UUID {
    private:
        uint64_t mostSignificant;
        uint64_t leastSignificant;
    public:
        UUID(uint64_t mostSignificant, uint64_t leastSignificant);

        std::string toString();

        bool equals(UUID &anotherUuid);
    };
}


#endif //MCSERVER_UUID_HPP
