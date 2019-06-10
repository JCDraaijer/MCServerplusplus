//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_BASE_HPP
#define MCSERVER_BASE_HPP

#include <string>

namespace packet {
    class Base {
    private:
        const int id;
    public:
        explicit Base(int);

        virtual std::string toString() = 0;

        int getId();
    };

}
#endif //MCSERVER_BASE_HPP
