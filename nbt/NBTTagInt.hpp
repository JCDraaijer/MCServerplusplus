//
// Created by jona on 2019-06-25.
//

#ifndef MCSERVER_NBTTAGINT_HPP
#define MCSERVER_NBTTAGINT_HPP

#include "NBTTagBase.hpp"

namespace nbt {
    class NBTTagInt : public NBTTagBase {
    private:
        int32_t value;
    public:
        explicit NBTTagInt(std::string name, int32_t value);

        explicit NBTTagInt(int32_t value);

        explicit NBTTagInt();

        ~NBTTagInt() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;

        const int32_t getValue();

        void setValue(int32_t newValue);
    };
}


#endif //MCSERVER_NBTTAGINT_HPP
