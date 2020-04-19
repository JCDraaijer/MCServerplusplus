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

#include <cstdio>
#include <cstdlib>
#include "OffsetOutOfBoundsException.hpp"

namespace protocol {
    OffsetOutOfBoundsException::OffsetOutOfBoundsException(uint32_t expected, uint32_t actual) {
        std::sprintf(this->whatValue, "Index %d is larger than datalength %d", expected, actual);
    }

    const char *OffsetOutOfBoundsException::what() const _GLIBCXX_USE_NOEXCEPT {
        return whatValue;
    }

    OffsetOutOfBoundsException::~OffsetOutOfBoundsException() {
        free(whatValue);
    }
}
