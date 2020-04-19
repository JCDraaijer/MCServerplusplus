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

#ifndef MCSERVER_IDENTIFIER_HPP
#define MCSERVER_IDENTIFIER_HPP

#include <string>

namespace protocol {
    class Identifier {
    private:
        std::string identifierNamespace;
        std::string thing;

    public:
        Identifier();

        Identifier(std::string theNamespace, std::string thing);

        explicit Identifier(std::string fullName);

        std::string getNamespace();

        std::string getThing();
    };
}


#endif //MCSERVER_IDENTIFIER_HPP
