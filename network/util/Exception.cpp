//
// Created by jona on 2019-06-10.
//

#include "Exception.hpp"
namespace network {

    Exception::Exception(const char *what) {
        whatValue = what;
    }

    const char *Exception::what() const _GLIBCXX_USE_NOEXCEPT {
        return whatValue;
    }
}