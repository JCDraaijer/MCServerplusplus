//
// Created by jona on 2019-06-25.
//

#ifndef MCSERVER_NBTTAGBYTEARRAY_HPP
#define MCSERVER_NBTTAGBYTEARRAY_HPP

#include "NBTTagBase.hpp"
#include <vector>

namespace nbt {
    class NBTTagByteArray : public NBTTagBase {
    private:
        std::vector<int8_t> bytes;
    public:
        explicit NBTTagByteArray();

        explicit NBTTagByteArray(std::vector<int8_t> bytes);

        explicit NBTTagByteArray(std::string name, std::vector<int8_t> bytes);

        ~NBTTagByteArray() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;
    };
}


#endif //MCSERVER_NBTTAGBYTEARRAY_HPP
