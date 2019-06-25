//
// Created by jona on 2019-06-25.
//

#ifndef MCSERVER_NBTTAGFLOAT_HPP
#define MCSERVER_NBTTAGFLOAT_HPP

#include "NBTTagBase.hpp"

namespace nbt {
    class NBTTagFloat : public NBTTagBase {
    private:
        float value;
    public:
        explicit NBTTagFloat(std::string name, float value);

        explicit NBTTagFloat(float value);

        explicit NBTTagFloat();

        ~NBTTagFloat() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;

        const float getValue();

        void setValue(float newValue);
    };
}

#endif //MCSERVER_NBTTAGFLOAT_HPP
