/*
MCpp, a Minecraft Server implementation in C++.
Copyright (C) 2019, 2020 Johannes Draaijer

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
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