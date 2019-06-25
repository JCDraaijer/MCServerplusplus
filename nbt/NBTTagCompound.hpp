//
// Created by jona on 2019-06-19.
//

#ifndef MCSERVER_NBTTAGCOMPOUND_HPP
#define MCSERVER_NBTTAGCOMPOUND_HPP

#include "NBTTagBase.hpp"
#include <string>
#include <list>

namespace nbt {
    class NBTTagCompound : public NBTTagBase {

    public:
        explicit NBTTagCompound();

        NBTTagBase *get(const std::string& name);

        bool remove(const std::string& name, bool del);

        void add(NBTTagBase *toAdd);

        void parsePayload(std::FILE *stream, bool named) override;

        ~NBTTagCompound() override;

        void write(std::FILE *stream, bool named) override;

        bool contains(const std::string& nameToFind);

        std::list<NBTTagBase *> elements;
    };
}


#endif //MCSERVER_NBTTAGCOMPOUND_HPP
