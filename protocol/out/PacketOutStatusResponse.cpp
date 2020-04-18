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

    PacketOutStatusResponse::PacketOutStatusResponse(std::string versionName, int versionProtocol,
                                                     int currentOnline, int maxOnline, std::string descriptionText,
                                                     std::string favicon) : PacketOutBase(STATUS_RESPONSE),
                                                                            versionName(std::move(versionName)),
                                                                            versionProtocol(versionProtocol),
                                                                            currentOnline(currentOnline),
                                                                            maxOnline(maxOnline),
                                                                            descriptionText(std::move(descriptionText)),
                                                                            favicon(std::move(favicon)) {

    }

    std::string PacketOutStatusResponse::getJsonResponse() {
        std::string jsonResponse =
                R"({"version":{"name":")" + versionName + R"(", "protocol":)" + std::to_string(versionProtocol) +
                R"(}, "players": {"max":)" + std::to_string(maxOnline) + R"(, "online":)" +
                std::to_string(currentOnline) + R"(}, "description": {"text":")" + descriptionText + R"("}})";
        return jsonResponse;
    }

    void PacketOutStatusResponse::serialize(PacketSerializer *packetSerializer) {
        packetSerializer->writeString(getJsonResponse());
    }

    PacketOutStatusResponse::~PacketOutStatusResponse() = default;
}
