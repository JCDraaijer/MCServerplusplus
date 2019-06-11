cmake_minimum_required(VERSION 3.14)
project(MCServer)

set(CMAKE_CXX_STANDARD 14)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(MCServer main.cpp network/Connection.cpp network/Connection.hpp server/Position.cpp server/Position.hpp server/UUID.cpp server/UUID.hpp network/Service.cpp network/Service.hpp protocol/in/PacketInBase.hpp protocol/in/PacketInHandshake.cpp protocol/in/PacketInHandshake.hpp network/util/Util.cpp network/util/Util.hpp protocol/in/PacketInBase.cpp network/State.cpp network/State.hpp logging/Level.cpp logging/Level.h logging/Logger.cpp logging/Logger.h protocol/in/PacketInPing.cpp protocol/in/PacketInPing.hpp protocol/in/PacketInRequest.cpp protocol/in/PacketInRequest.hpp protocol/out/PacketOutResponse.cpp protocol/out/PacketOutResponse.hpp protocol/PacketBase.cpp protocol/PacketBase.hpp protocol/out/PacketOutBase.cpp protocol/out/PacketOutBase.hpp network/PacketSerializer.cpp network/PacketSerializer.hpp protocol/out/PacketOutPong.cpp protocol/out/PacketOutPong.hpp network/PacketParser.cpp network/PacketParser.hpp network/util/OffsetOutOfBoundsException.cpp network/util/OffsetOutOfBoundsException.hpp network/util/Exception.cpp network/util/Exception.hpp protocol/in/PacketInLoginStart.cpp protocol/in/PacketInLoginStart.hpp protocol/in/PacketInEncryptionResponse.cpp protocol/in/PacketInEncryptionResponse.hpp protocol/in/PacketInLoginPluginResponse.cpp protocol/in/PacketInLoginPluginResponse.hpp protocol/out/PacketOutDisconnect.cpp protocol/out/PacketOutDisconnect.hpp)
target_link_libraries(MCServer pthread)
