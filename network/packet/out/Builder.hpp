//
// Created by jona on 2019-06-10.
//

#include "OutBase.hpp"

#ifndef MCSERVER_BUILDER_H
#define MCSERVER_BUILDER_H


namespace packet {
    class Builder {
    public:
        OutBase *build();
    };
}


#endif //MCSERVER_BUILDER_H
