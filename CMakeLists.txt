cmake_minimum_required(VERSION 3.14)
project(MCServer)

set(CMAKE_CXX_STANDARD 14)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(MCServer main.cpp network/Connection.cpp
        network/Connection.hpp server/Position.cpp server/Position.hpp
        server/UUID.cpp server/UUID.hpp network/Service.cpp
        network/Service.hpp protocol/in/PacketInBase.hpp protocol/in/PacketInHandshake.cpp
        protocol/in/PacketInHandshake.hpp protocol/util/Util.cpp protocol/util/Util.hpp
        protocol/in/PacketInBase.cpp network/State.cpp network/State.hpp logging/Level.cpp
        logging/Level.h logging/Logger.cpp logging/Logger.h protocol/in/PacketInPing.cpp
        protocol/in/PacketInPing.hpp protocol/in/PacketInRequest.cpp protocol/in/PacketInRequest.hpp
        protocol/out/PacketOutResponse.cpp protocol/out/PacketOutResponse.hpp protocol/PacketBase.cpp
        protocol/PacketBase.hpp protocol/out/PacketOutBase.cpp protocol/out/PacketOutBase.hpp
        protocol/PacketSerializer.cpp protocol/PacketSerializer.hpp protocol/out/PacketOutPong.cpp
        protocol/out/PacketOutPong.hpp network/PacketParser.cpp network/PacketParser.hpp
        protocol/util/OffsetOutOfBoundsException.cpp protocol/util/OffsetOutOfBoundsException.hpp
        protocol/util/Exception.cpp protocol/util/Exception.hpp protocol/in/PacketInLoginStart.cpp
        protocol/in/PacketInLoginStart.hpp protocol/in/PacketInEncryptionResponse.cpp
        protocol/in/PacketInEncryptionResponse.hpp protocol/in/PacketInLoginPluginResponse.cpp
        protocol/in/PacketInLoginPluginResponse.hpp protocol/out/PacketLoginOutDisconnect.cpp
        protocol/out/PacketLoginOutDisconnect.hpp protocol/out/PacketOutEncryptionRequest.cpp
        protocol/out/PacketOutEncryptionRequest.hpp protocol/out/PacketOutSetCompression.cpp
        protocol/out/PacketOutSetCompression.hpp protocol/out/PacketOutLoginSuccess.cpp protocol/out/PacketOutLoginSuccess.hpp)

target_link_libraries(MCServer pthread)
