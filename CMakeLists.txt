cmake_minimum_required(VERSION 3.14)
project(MCServer)

set(CMAKE_CXX_STANDARD 14)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(MCServer main.cpp network/Connection.cpp
        network/Connection.hpp server/world/Location.cpp server/world/Location.hpp
        server/UUID.cpp server/UUID.hpp network/Service.cpp
        network/Service.hpp protocol/in/PacketInBase.hpp protocol/in/PacketHandshakeIn.cpp
        protocol/in/PacketHandshakeIn.hpp
        protocol/in/PacketInBase.cpp protocol/ConnectionState.cpp protocol/ConnectionState.hpp logging/Level.cpp
        logging/Level.h logging/Logger.cpp logging/Logger.h protocol/in/PacketStatusInPing.cpp
        protocol/in/PacketStatusInPing.hpp protocol/in/PacketStatusInRequest.cpp protocol/in/PacketStatusInRequest.hpp
        protocol/out/PacketStatusOutResponse.cpp protocol/out/PacketStatusOutResponse.hpp protocol/PacketBase.cpp
        protocol/PacketBase.hpp protocol/out/PacketOutBase.cpp protocol/out/PacketOutBase.hpp
        protocol/PacketSerializer.cpp protocol/PacketSerializer.hpp protocol/out/PacketStatusOutPong.cpp
        protocol/out/PacketStatusOutPong.hpp protocol/PacketParser.cpp protocol/PacketParser.hpp
        protocol/exception/OffsetOutOfBoundsException.cpp protocol/exception/OffsetOutOfBoundsException.hpp
        protocol/exception/Exception.cpp protocol/exception/Exception.hpp protocol/in/PacketInLoginStart.cpp
        protocol/in/PacketInLoginStart.hpp protocol/in/PacketLoginInEncryptionResponse.cpp
        protocol/in/PacketLoginInEncryptionResponse.hpp protocol/in/PacketInLoginPluginResponse.cpp
        protocol/in/PacketInLoginPluginResponse.hpp protocol/out/PacketLoginOutDisconnect.cpp
        protocol/out/PacketLoginOutDisconnect.hpp protocol/out/PacketLoginOutEncryptionRequest.cpp
        protocol/out/PacketLoginOutEncryptionRequest.hpp protocol/out/PacketLoginOutSetCompression.cpp
        protocol/out/PacketLoginOutSetCompression.hpp protocol/out/PacketLoginOutLoginSuccess.cpp protocol/out/PacketLoginOutLoginSuccess.hpp server/world/BlockLocation.cpp server/world/BlockLocation.hpp server/entity/Entity.cpp server/entity/Entity.hpp server/world/World.cpp server/world/World.hpp server/world/Chunk.cpp server/world/Chunk.hpp server/Server.cpp server/Server.hpp server/world/Block.cpp server/world/Block.hpp server/Vector3D.cpp server/Vector3D.hpp server/Material.cpp server/Material.hpp protocol/out/PacketPlayOutJoinGame.cpp protocol/out/PacketPlayOutJoinGame.hpp protocol/exception/UnknownPacketException.cpp protocol/exception/UnknownPacketException.hpp protocol/in/PacketPlayInPluginMessage.cpp protocol/in/PacketPlayInPluginMessage.hpp protocol/Identifier.cpp protocol/Identifier.hpp protocol/in/PacketPlayInClientSettings.cpp protocol/in/PacketPlayInClientSettings.hpp)

target_link_libraries(MCServer pthread)
