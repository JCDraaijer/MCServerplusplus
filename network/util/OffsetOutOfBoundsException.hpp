//
// Created by jona on 2019-06-10.
//

#ifndef MCSERVER_OFFSETOUTOFBOUNDSEXCEPTION_HPP
#define MCSERVER_OFFSETOUTOFBOUNDSEXCEPTION_HPP


#include <exception>

namespace network {
    class OffsetOutOfBoundsException : public std::exception {
    private:
        char *whatValue;
    public:
        OffsetOutOfBoundsException(int expected, int actual);

        ~OffsetOutOfBoundsException() override;

        const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;
    };
}

#endif //MCSERVER_OFFSETOUTOFBOUNDSEXCEPTION_HPP
