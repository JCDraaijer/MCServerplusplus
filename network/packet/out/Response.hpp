//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_RESPONSE_HPP
#define MCSERVER_RESPONSE_HPP

#include "OutBase.hpp"

namespace packet {
    class Response : public OutBase {
    private:
        std::string jsonResponse;
    public:
        explicit Response(std::string);

        std::string toString() override;

        std::string getJsonResponse();
    };
}


#endif //MCSERVER_RESPONSE_HPP
