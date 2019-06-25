//
// Created by jona on 2019-06-25.
//

#ifndef MCSERVER_NBTTAGINTARRAY_HPP
#define MCSERVER_NBTTAGINTARRAY_HPP

#include "NBTTagBase.hpp"
#include <list>

namespace nbt {
    class NBTTagIntArray : public NBTTagBase {
    private:
        std::list<int32_t> elements;
    public:
        explicit NBTTagIntArray();

        explicit NBTTagIntArray(std::string name);

        ~NBTTagIntArray() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;
    };
}


#endif //MCSERVER_NBTTAGINTARRAY_HPP
