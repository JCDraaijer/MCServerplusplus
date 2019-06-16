//
// Created by jona on 2019-06-13.
//

#include "World.hpp"

namespace server {

    void World::tickEntities() {

    }

    Block *World::getBlockAt(Location location) {
        return getBlockAt(location.toBlockLocation());
    }

    Block *World::getBlockAt(BlockLocation location) {
        uint32_t x = location.getX() / 16;
        uint32_t z = location.getZ() / 16;

        auto chunkExists = loadedChunks.find(chunkLocationKey(x, z));
        if (chunkExists == loadedChunks.end()) {
            return nullptr;
        }
        std::pair<uint64_t, Chunk> theActualChunk = *chunkExists;
        Chunk chunkToGet = theActualChunk.second;

        uint32_t blockX = location.getX() % 16;
        uint32_t blockZ = location.getZ() % 16;

        return chunkToGet.getBlock(blockX, location.getY(), blockZ);
    }

    uint64_t World::chunkLocationKey(uint32_t x, uint32_t z) {
        return (uint64_t) ((uint64_t) x << 32u) | (z);
    }

    bool World::spawnEntity(Entity *someEntity) {
        return false;
    }

    bool World::spawnPlayer(Player *somePlayer) {
        return false;
    }

    bool World::removeEntity(Entity *someEntity) {
        return false;
    }

    bool World::removePlayer(Player *somePlayer) {
        return false;
    }
}