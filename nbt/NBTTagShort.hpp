//
// Created by jona on 2019-06-25.
//

#ifndef MCSERVER_NBTTAGSHORT_HPP
#define MCSERVER_NBTTAGSHORT_HPP


#include "NBTTagBase.hpp"

namespace nbt {
    class NBTTagShort : public NBTTagBase {
    private:
        int16_t value;
    public:
        explicit NBTTagShort(std::string name, int16_t value);

        explicit NBTTagShort(int16_t value);

        explicit NBTTagShort();

        ~NBTTagShort() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;

        const int16_t getValue();

        void setValue(int16_t newValue);
    };
}


#endif //MCSERVER_NBTTAGSHORT_HPP
