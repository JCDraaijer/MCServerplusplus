//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_INBASE_H
#define MCSERVER_INBASE_H

#include <string>
#include "../Base.h"

namespace packet {
    namespace in {

        enum PacketType {
            HANDSHAKE,
            REQUEST,
            PING
        };

        class InBase : public Base {
        private:
            const PacketType type;
        public:
            explicit InBase(int id, PacketType type);

            virtual void parse(unsigned char *data, int dataLength) = 0;

        };
    }
}

#endif //MCSERVER_INBASE_H
