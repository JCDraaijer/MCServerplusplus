//
// Created by jona on 2019-06-25.
//

#ifndef MCSERVER_NBTTAGSTRING_HPP
#define MCSERVER_NBTTAGSTRING_HPP

#include "NBTTagBase.hpp"

namespace nbt {
    class NBTTagString : public NBTTagBase {
    private:
        std::string value;
    public:
        explicit NBTTagString();

        explicit NBTTagString(std::string value);

        explicit NBTTagString(std::string name, std::string value);

        const std::string getString();

        void setString(std::string newValue);

        ~NBTTagString() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;
    };
}


#endif //MCSERVER_NBTTAGSTRING_HPP
