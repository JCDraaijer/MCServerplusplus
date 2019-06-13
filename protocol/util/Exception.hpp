//
// Created by jona on 2019-06-10.
//

#ifndef MCSERVER_EXCEPTION_HPP
#define MCSERVER_EXCEPTION_HPP

#include <exception>

namespace protocol {
    class Exception : public std::exception {
    private:
        const char *whatValue;
    public:
        explicit Exception(const char *what);

        const char *
        what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;
    };
}


#endif //MCSERVER_EXCEPTION_HPP
