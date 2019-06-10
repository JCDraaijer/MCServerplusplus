#include <utility>
#include <sstream>

//
// Created by jona on 2019-06-09.
//

#include "Response.hpp"
#include "../../Util.hpp"

namespace packet {
    std::string Response::toString() {
        std::ostringstream stringStream;
        stringStream << "Request packet. ID: " << this->getId();
        return stringStream.str();
    }

    Response::Response(std::string jsonResponse) : OutBase(0, RESPONSE) {
        this->jsonResponse = std::move(jsonResponse);
    }

    std::string Response::getJsonResponse() {
        return this->jsonResponse;
    }
}
