//
// Created by jona on 2019-06-25.
//

#ifndef MCSERVER_NBTTAGBYTEARRAY_HPP
#define MCSERVER_NBTTAGBYTEARRAY_HPP

#include "NBTTagBase.hpp"
#include <list>

namespace nbt {
    class NBTTagByteArray : public NBTTagBase {
    private:
        std::list<int8_t> bytes;
    public:
        explicit NBTTagByteArray();

        explicit NBTTagByteArray(std::list<int8_t> bytes);

        explicit NBTTagByteArray(std::string name, std::list<int8_t> bytes);

        ~NBTTagByteArray() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;

        void insert(int8_t value, uint32_t position);

        void add(int8_t value);

        bool remove(uint32_t index);

    };
}


#endif //MCSERVER_NBTTAGBYTEARRAY_HPP
