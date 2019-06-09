//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_HANDSHAKE_H
#define MCSERVER_HANDSHAKE_H

#include "InBase.h"
#include "../../State.h"

namespace packet { namespace in {

    class Handshake : public InBase {
    private:
        const int id = 0;
        int protocolVersion;
        std::string address;
        unsigned short port;
        networking::State nextState;

    public:
        explicit Handshake();

        explicit Handshake(int protocolVersion, std::string address, unsigned short port, networking::State nextState);

        void parse(unsigned char *data, int dataLength) override;

        networking::State getNextState();

        int getProtocolVersion();

        std::string getAddress();

        unsigned short getPort();

        std::string toString() override;
    };
} }


#endif //MCSERVER_HANDSHAKE_H
