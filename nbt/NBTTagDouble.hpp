//
// Created by jona on 2019-06-25.
//

#ifndef MCSERVER_NBTTAGDOUBLE_HPP
#define MCSERVER_NBTTAGDOUBLE_HPP


#include "NBTTagBase.hpp"

namespace nbt {
    class NBTTagDouble : public NBTTagBase {
    private:
        double value;
    public:
        explicit NBTTagDouble(std::string name, double value);

        explicit NBTTagDouble(double value);

        explicit NBTTagDouble();

        ~NBTTagDouble() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;

        const double getValue();

        void setValue(double newValue);
    };
}


#endif //MCSERVER_NBTTAGDOUBLE_HPP
