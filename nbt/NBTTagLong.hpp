//
// Created by jona on 2019-06-25.
//

#ifndef MCSERVER_NBTTAGLONG_HPP
#define MCSERVER_NBTTAGLONG_HPP

#include "NBTTagBase.hpp"

namespace nbt {
    class NBTTagLong : public NBTTagBase {
    private:
        int64_t value;
    public:
        explicit NBTTagLong(std::string name, int64_t value);

        explicit NBTTagLong(int64_t value);

        explicit NBTTagLong();

        ~NBTTagLong() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;

        const int64_t getValue();

        void setValue(int64_t newValue);

    };
}


#endif //MCSERVER_NBTTAGLONG_HPP
