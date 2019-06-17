//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_LEVEL_H
#define MCSERVER_LEVEL_H

#include <string>

namespace logging {
    class Level {
    private:
        const int priority;
    public:
        explicit Level(uint32_t priority);
        static const Level ALL;
        static const Level DEBUG;
        static const Level WARNING;
        static const Level ERROR;
        static const Level INFO;
        static const Level NONE;
        inline bool operator < (const Level &l) const {
            return priority < l.priority;
        }
        inline bool operator > (const Level &l) const {
            return priority > l.priority;
        }
        inline bool operator == (const Level &l) const {
            return priority == l.priority;
        }
    };
}


#endif //MCSERVER_LEVEL_H
