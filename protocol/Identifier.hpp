//
// Created by jona on 2019-06-15.
//

#ifndef MCSERVER_IDENTIFIER_HPP
#define MCSERVER_IDENTIFIER_HPP

#include <string>

namespace protocol {
    class Identifier {
    private:
        std::string identifierNamespace;
        std::string thing;

    public:
        Identifier(std::string theNamespace, std::string thing);

        explicit Identifier(std::string fullName);

        std::string getNamespace();

        std::string getThing();
    };
}


#endif //MCSERVER_IDENTIFIER_HPP
