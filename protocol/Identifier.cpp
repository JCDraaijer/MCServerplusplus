#include <utility>

#include <utility>

//
// Created by jona on 2019-06-15.
//

#include "Identifier.hpp"

namespace protocol {
    Identifier::Identifier(std::string theNamespace, std::string thing) : identifierNamespace(std::move(theNamespace)),
                                                                          thing(std::move(thing)) {

    }

    Identifier::Identifier(std::string fullName) {
        std::string theNameSpace;
        std::string theThing;
        std::string::iterator it;
        bool encounteredSemicolon = false;
        for (it = fullName.begin(); it != fullName.end(); it++) {
            if (*it != ':' && !encounteredSemicolon) {
                theNameSpace += *it;
            } else if (encounteredSemicolon) {
                theThing += *it;
            } else {
                encounteredSemicolon = true;
            }
        }
        identifierNamespace = theNameSpace;
        thing = std::move(theThing);
    }

    std::string Identifier::getNamespace() {
        return identifierNamespace;
    }

    std::string Identifier::getThing() {
        return thing;
    }
}
