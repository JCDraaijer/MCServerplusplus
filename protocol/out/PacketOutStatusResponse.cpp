/*
MCpp, a Minecraft Server implementation in C++.
Copyright (C) 2019, 2020 Johannes Draaijer

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <sstream>
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
