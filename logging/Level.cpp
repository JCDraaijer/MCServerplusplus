//
// Created by jona on 2019-06-09.
//

#include "Level.h"

namespace logging {

    const Level Level::ALL = Level(500);
    const Level Level::DEBUG = Level(400);
    const Level Level::WARNING = Level(300);
    const Level Level::ERROR = Level(200);
    const Level Level::INFO = Level(100);
    const Level Level::NONE = Level(0);

    Level::Level(int priority) : priority(priority) {

    }
}