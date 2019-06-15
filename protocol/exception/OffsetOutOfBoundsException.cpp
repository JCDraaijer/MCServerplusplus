//
// Created by jona on 2019-06-10.
//

#include <cstdio>
#include <cstdlib>
#include "OffsetOutOfBoundsException.hpp"

namespace protocol {
    OffsetOutOfBoundsException::OffsetOutOfBoundsException(int expected, int actual) {
        whatValue = (char *) (malloc(sizeof(char) * 64));
        std::sprintf(this->whatValue, "Index %d is larger than datalength %d", expected, actual);
    }

    const char *OffsetOutOfBoundsException::what() const _GLIBCXX_USE_NOEXCEPT {
        return whatValue;
    }

    OffsetOutOfBoundsException::~OffsetOutOfBoundsException() {
        free(whatValue);
    }
}
