//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_RESPONSE_H
#define MCSERVER_RESPONSE_H

#include "OutBase.h"

namespace packet {
    namespace out {
        class Response : public OutBase {
        private:
            std::string jsonResponse;
        public:
            Response(std::string);
            std::string toString() override;
            unsigned char *serialize(int *) override;
        };
    }
}


#endif //MCSERVER_RESPONSE_H
