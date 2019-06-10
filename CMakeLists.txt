cmake_minimum_required(VERSION 3.14)
project(MCServer)

set(CMAKE_CXX_STANDARD 14)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(MCServer main.cpp network/Connection.cpp network/Connection.hpp server/Position.cpp server/Position.hpp server/UUID.cpp server/UUID.hpp network/Service.cpp network/Service.hpp network/packet/in/InBase.hpp network/packet/in/Handshake.cpp network/packet/in/Handshake.hpp network/Util.cpp network/Util.hpp network/packet/in/InBase.cpp network/State.cpp network/State.hpp logging/Level.cpp logging/Level.h logging/Logger.cpp logging/Logger.h network/packet/in/Ping.cpp network/packet/in/Ping.hpp network/packet/in/Request.cpp network/packet/in/Request.hpp network/packet/out/Response.cpp network/packet/out/Response.hpp network/packet/Base.cpp network/packet/Base.hpp network/packet/out/OutBase.cpp network/packet/out/OutBase.hpp network/packet/in/Reader.cpp network/packet/in/Reader.hpp network/packet/out/Builder.cpp network/packet/out/Builder.hpp)
target_link_libraries(MCServer pthread)
