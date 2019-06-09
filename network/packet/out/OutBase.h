//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_OUTBASE_H
#define MCSERVER_OUTBASE_H

#include "../Base.h"

namespace packet {
    namespace out {

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
}


#endif //MCSERVER_OUTBASE_H
