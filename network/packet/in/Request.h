//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_REQUEST_H
#define MCSERVER_REQUEST_H


#include "InBase.h"

namespace packet {
    namespace in {
        class Request : public InBase {
        public:
            explicit Request();

            void parse(unsigned char *data, int dataLength) override;

            std::string toString() override;
        };
    }
}

#endif //MCSERVER_REQUEST_H
