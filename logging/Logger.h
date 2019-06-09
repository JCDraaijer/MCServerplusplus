//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_LOGGER_H
#define MCSERVER_LOGGER_H

#include "Level.h"

namespace logging {
    class Logger {
    public:
        void log(Level, std::string);
        void log(Level, const char * format, ...);
    };
}

logging::Logger getLogger();

#endif //MCSERVER_LOGGER_H
