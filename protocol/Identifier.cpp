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

    Identifier::Identifier() : identifierNamespace(""), thing(""){

    }
}
