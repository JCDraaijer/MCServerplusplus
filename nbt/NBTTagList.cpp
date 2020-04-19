//
// Created by jona on 2019-06-25.
//

#include "NBTTagList.hpp"
#include "NBTTagByte.hpp"
#include "NBTTagShort.hpp"
#include "NBTTagInt.hpp"
#include "NBTTagLong.hpp"
#include "NBTTagFloat.hpp"
#include "NBTTagDouble.hpp"
#include "NBTTagByteArray.hpp"
#include "NBTTagString.hpp"

namespace nbt {

    NBTTagList::NBTTagList() : NBTTagBase(LIST), containedType(END) {

    }

    NBTTagList::NBTTagList(std::string name) : NBTTagBase(LIST, std::move(name)) {

    }

    NBTTagList::~NBTTagList() {
        for (auto &element: elements) {
            delete element;
        }
    }

    void NBTTagList::parsePayload(std::FILE *stream, bool named) {
        if (named) {
            parseName(stream);
        }
        std::fread(&containedType, 1, 1, stream);
        int32_t length = readInt(stream);
        elements = std::list<NBTTagBase *>(length);
        for (int i = 0; i < length; i++) {
            NBTTagBase *value;
            switch (containedType) {
                case END:
                    return;
                case BYTE:
                    value = new NBTTagByte();
                    break;
                case SHORT:
                    value = new NBTTagShort();
                    break;
                case INT:
                    value = new NBTTagInt();
                    break;
                case LONG:
                    value = new NBTTagLong();
                    break;
                case FLOAT:
                    value = new NBTTagFloat();
                    break;
                case DOUBLE:
                    value = new NBTTagDouble();
                    break;
                case BYTE_ARRAY:
                    value = new NBTTagByteArray();
                    break;
                case STRING:
                    value = new NBTTagString();
                    break;
                case LIST:
                    value = new NBTTagList();
                    break;
                case COMPOUND:
                    value = new NBTTagCompound();
                    break;
                case INT_ARRAY:
                case LONG_ARRAY:
                    value = new NBTTagByte();
                    break;
                default:
                    return;
            }
            value->parsePayload(stream, false);
            elements.push_back(value);
        }
    }

    void NBTTagList::write(std::FILE *stream, bool named) {

    }
}