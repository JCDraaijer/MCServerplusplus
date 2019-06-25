//
// Created by jona on 2019-06-25.
//

#ifndef MCSERVER_NBTTAGLONGARRAY_HPP
#define MCSERVER_NBTTAGLONGARRAY_HPP


#include "NBTTagBase.hpp"
#include <list>

namespace nbt {
    class NBTTagLongArray : public NBTTagBase {
    private:
        std::list<int32_t> elements;
    public:
        explicit NBTTagLongArray();

        explicit NBTTagLongArray(std::string name);

        ~NBTTagLongArray() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;
    };
}


#endif //MCSERVER_NBTTAGLONGARRAY_HPP
