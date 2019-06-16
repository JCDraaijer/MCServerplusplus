//
// Created by jona on 2019-06-13.
//

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
