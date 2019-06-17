cmake_minimum_required(VERSION 3.14)
project(MCServer)

set(CMAKE_CXX_STANDARD 14)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(UUID REQUIRED uuid)

add_executable(MCServer main.cpp network/Connection.cpp
        network/Connection.hpp server/world/Location.cpp server/world/Location.hpp
        network/Service.cpp
        network/Service.hpp protocol/in/PacketInBase.hpp protocol/in/PacketInHandshake.cpp
        protocol/in/PacketInHandshake.hpp
        protocol/in/PacketInBase.cpp protocol/ConnectionState.cpp protocol/ConnectionState.hpp logging/Level.cpp
        logging/Level.h logging/Logger.cpp logging/Logger.h protocol/in/PacketInStatusPing.cpp
        protocol/in/PacketInStatusPing.hpp protocol/in/PacketInStatusRequest.cpp protocol/in/PacketInStatusRequest.hpp
        protocol/out/PacketOutStatusResponse.cpp protocol/out/PacketOutStatusResponse.hpp protocol/PacketBase.cpp
        protocol/PacketBase.hpp protocol/out/PacketOutBase.cpp protocol/out/PacketOutBase.hpp
        protocol/PacketSerializer.cpp protocol/PacketSerializer.hpp protocol/out/PacketOutStatusPong.cpp
        protocol/out/PacketOutStatusPong.hpp protocol/PacketParser.cpp protocol/PacketParser.hpp
        protocol/exception/OffsetOutOfBoundsException.cpp protocol/exception/OffsetOutOfBoundsException.hpp
        protocol/exception/Exception.cpp protocol/exception/Exception.hpp protocol/in/PacketInLoginStart.cpp
        protocol/in/PacketInLoginStart.hpp protocol/in/PacketInLoginEncryptionResponse.cpp
        protocol/in/PacketInLoginEncryptionResponse.hpp protocol/in/PacketInLoginPluginResponse.cpp
        protocol/in/PacketInLoginPluginResponse.hpp protocol/out/PacketOutLoginDisconnect.cpp
        protocol/out/PacketOutLoginDisconnect.hpp protocol/out/PacketOutLoginEncryptionRequest.cpp
        protocol/out/PacketOutLoginEncryptionRequest.hpp protocol/out/PacketOutLoginSetCompression.cpp
        protocol/out/PacketOutLoginSetCompression.hpp protocol/out/PacketOutLoginLoginSuccess.cpp
        protocol/out/PacketOutLoginLoginSuccess.hpp server/world/BlockLocation.cpp server/world/BlockLocation.hpp
        server/entity/Entity.cpp server/entity/Entity.hpp server/world/World.cpp server/world/World.hpp server/world/Chunk.cpp
        server/world/Chunk.hpp server/Server.cpp server/Server.hpp server/world/Block.cpp server/world/Block.hpp server/Vector3D.cpp
        server/Vector3D.hpp server/Material.cpp server/Material.hpp protocol/out/PacketOutPlayJoinGame.cpp protocol/out/PacketOutPlayJoinGame.hpp
        protocol/exception/UnknownPacketException.cpp protocol/exception/UnknownPacketException.hpp protocol/in/PacketInPlayPluginMessage.cpp
        protocol/in/PacketInPlayPluginMessage.hpp protocol/Identifier.cpp protocol/Identifier.hpp protocol/in/PacketInPlayClientSettings.cpp protocol/in/PacketInPlayClientSettings.hpp
        server/UUID.hpp server/UUID.cpp server/world/ChunkSection.cpp server/world/ChunkSection.hpp server/world/ChunkLocation.cpp server/world/ChunkLocation.hpp server/entity/Player.cpp server/entity/Player.hpp protocol/out/PacketOutPlayChunkData.cpp protocol/out/PacketOutPlayChunkData.hpp protocol/out/PacketOutPlayPlayerPositionLook.cpp protocol/out/PacketOutPlayPlayerPositionLook.hpp protocol/in/PacketInPlayTeleportConfirm.cpp protocol/in/PacketInPlayTeleportConfirm.hpp protocol/in/PacketInLegacyPingRequest.cpp protocol/in/PacketInLegacyPingRequest.hpp protocol/out/PacketOutHandshakeLegacyPingResponse.cpp protocol/out/PacketOutHandshakeLegacyPingResponse.hpp protocol/in/PacketInPlayUpdateStructureBlock.cpp protocol/in/PacketInPlayUpdateStructureBlock.hpp)

target_include_directories(MCServer PUBLIC ${UUID_INCLUDE_DIRS})
target_link_libraries(MCServer pthread ${UUID_LIBRARIES})
