//
// Created by jona on 2019-06-25.
//

#ifndef MCSERVER_NBTTAGBYTE_HPP
#define MCSERVER_NBTTAGBYTE_HPP

#include "NBTTagBase.hpp"

namespace nbt {
    class NBTTagByte : public NBTTagBase {
    private:
        int8_t value;
    public:
        explicit NBTTagByte(std::string name, uint8_t value);

        explicit NBTTagByte(uint8_t value);

        explicit NBTTagByte();

        ~NBTTagByte() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;

        const int8_t getValue();

        void setValue(int8_t newValue);
    };
}


#endif //MCSERVER_NBTTAGBYTE_HPP
