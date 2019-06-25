//
// Created by jona on 2019-06-25.
//

#ifndef MCSERVER_NBTTAGLIST_HPP
#define MCSERVER_NBTTAGLIST_HPP

#include "NBTTagCompound.hpp"
#include <list>

namespace nbt {
    class NBTTagList : public NBTTagBase {
    private:
        std::list<NBTTagBase *> elements;
        NBTTag containedType;
    public:
        explicit NBTTagList();

        explicit NBTTagList(std::string name);

        bool remove(uint32_t index);

        void add(NBTTagBase *element);

        ~NBTTagList() override;

        void parsePayload(std::FILE *stream, bool named) override;

        void write(std::FILE *stream, bool named) override;


    };
}


#endif //MCSERVER_NBTTAGLIST_HPP
