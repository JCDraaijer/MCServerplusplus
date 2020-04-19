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


#include "PacketOutLoginSetCompression.hpp"

namespace protocol {

    PacketOutLoginSetCompression::PacketOutLoginSetCompression(int32_t threshold) : PacketOutBase(LOGIN_SET_COMPRESSION),
                                                                          threshold(threshold) {

    }

    int32_t PacketOutLoginSetCompression::getThreshold() {
        return threshold;
    }

    void PacketOutLoginSetCompression::setThreshold(int32_t newThreshold) {
        threshold = newThreshold;
    }

    void PacketOutLoginSetCompression::serialize(PacketSerializer *packetSerializer) {

    }

    PacketOutLoginSetCompression::~PacketOutLoginSetCompression() = default;
}