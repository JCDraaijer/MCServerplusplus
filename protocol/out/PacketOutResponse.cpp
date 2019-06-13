#include <utility>
#include <sstream>

//
// Created by jona on 2019-06-09.
//

#include "PacketOutResponse.hpp"
#include "../util/Util.hpp"

namespace protocol {
    std::string PacketOutResponse::toString() {
        std::ostringstream stringStream;
        stringStream << "Response packet. ID: " << this->getId() << ". Text: " << this->getJsonResponse();
        return stringStream.str();
    }

    PacketOutResponse::PacketOutResponse(std::string jsonResponse) : PacketOutBase(0, RESPONSE) {
        this->jsonResponse = std::move(jsonResponse);
    }

    std::string PacketOutResponse::getJsonResponse() {
        return this->jsonResponse;
    }

    void PacketOutResponse::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeString(getJsonResponse());
    }
}
