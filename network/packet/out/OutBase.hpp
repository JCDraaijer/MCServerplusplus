//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_OUTBASE_HPP
#define MCSERVER_OUTBASE_HPP

#include "../Base.hpp"

namespace packet {

    enum PacketType {
        RESPONSE
    };

    class OutBase : public Base {
    private:
        const PacketType type;
    public:
        explicit OutBase(int id, PacketType type);

        PacketType getType();
    };
}


#endif //MCSERVER_OUTBASE_HPP
