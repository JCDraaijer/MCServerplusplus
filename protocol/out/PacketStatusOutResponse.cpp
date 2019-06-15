#include <utility>
#include <sstream>

//
// Created by jona on 2019-06-09.
//

#include "PacketStatusOutResponse.hpp"
#include "../util/Util.hpp"

namespace protocol {
    std::string PacketStatusOutResponse::toString() {
        std::ostringstream stringStream;
        stringStream << "Response packet. ID: " << this->getId() << ". Text: " << this->getJsonResponse();
        return stringStream.str();
    }

    PacketStatusOutResponse::PacketStatusOutResponse(std::string jsonResponse) : PacketOutBase(STATUS_RESPONSE) {
        this->jsonResponse = std::move(jsonResponse);
    }

    std::string PacketStatusOutResponse::getJsonResponse() {
        return this->jsonResponse;
    }

    void PacketStatusOutResponse::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeString(getJsonResponse());
    }
}
