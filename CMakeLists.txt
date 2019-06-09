cmake_minimum_required(VERSION 3.14)
project(MCServer)

set(CMAKE_CXX_STANDARD 14)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(MCServer main.cpp network/Connection.cpp network/Connection.h server/Position.cpp server/Position.h server/UUID.cpp server/UUID.h network/Service.cpp network/Service.h network/packet/in/InBase.h network/packet/in/Handshake.cpp network/packet/in/Handshake.h network/Util.cpp network/Util.h network/packet/in/InBase.cpp network/State.cpp network/State.h logging/Level.cpp logging/Level.h logging/Logger.cpp logging/Logger.h network/packet/in/Ping.cpp network/packet/in/Ping.h network/packet/in/Request.cpp network/packet/in/Request.h network/packet/out/Response.cpp network/packet/out/Response.h network/packet/Base.cpp network/packet/Base.h network/packet/out/OutBase.cpp network/packet/out/OutBase.h)
target_link_libraries(MCServer pthread)
