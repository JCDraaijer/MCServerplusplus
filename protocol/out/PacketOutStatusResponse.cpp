#include <utility>
#include <sstream>

//
// Created by jona on 2019-06-09.
//

#include "PacketOutStatusResponse.hpp"

namespace protocol {
    std::string PacketOutStatusResponse::toString() {
        std::ostringstream stringStream;
        stringStream << "Response packet. ID: " << this->getId() << ". Text: " << this->getJsonResponse();
        return stringStream.str();
    }

    PacketOutStatusResponse::PacketOutStatusResponse(std::string jsonResponse) : PacketOutBase(STATUS_RESPONSE) {
        this->jsonResponse = std::move(jsonResponse);
    }

    std::string PacketOutStatusResponse::getJsonResponse() {
        return this->jsonResponse;
    }

    void PacketOutStatusResponse::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeString(getJsonResponse());
    }

    PacketOutStatusResponse::~PacketOutStatusResponse() = default;
}
