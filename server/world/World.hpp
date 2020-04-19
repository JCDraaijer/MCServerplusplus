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

#ifndef MCSERVER_WORLD_HPP
#define MCSERVER_WORLD_HPP

#include <unordered_map>
#include <vector>
#include <list>
#include "Chunk.hpp"
#include "../entity/Entity.hpp"
#include "BlockLocation.hpp"
#include "../entity/Player.hpp"

namespace server {
    class World {
    private:
        std::string name;

        std::vector<Entity*> entities;
        std::unordered_map<uint64_t, Chunk> loadedChunks;

        std::vector<Player*> players;

        float gravity;

    public:
        void tickEntities();

        Block *getBlockAt(Location location);

        Block *getBlockAt(BlockLocation location);

        bool spawnEntity(Entity *entity);

        bool spawnPlayer(Player *player);

        bool removeEntity(Entity *someEntity);

        bool removePlayer(Player *somePlayer);

        static uint64_t chunkLocationKey(uint32_t x, uint32_t z);

    };
}


#endif //MCSERVER_WORLD_HPP
