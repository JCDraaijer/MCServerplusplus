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


#ifndef MCSERVER_PACKETBASE_HPP
#define MCSERVER_PACKETBASE_HPP

#define enumToStr(x) #x
#define enumToStrx(x) enumToStr(x)

#include <string>

namespace protocol {
    enum InPacketType {
        /* HANDSHAKE packets*/
        HANDSHAKE = 0x00,
        LEGACY_PING = 0xFE,

        /* STATUS packets */
        STATUS_REQUEST = 0x00,
        PING = 0x01,

        /* LOGIN packets */
        LOGIN_START = 0x00,
        ENCRYPTION_RESPONSE = 0x01,
        LOGIN_PLUGIN_RESPONSE = 0x02,

        /* PLAY packets */
        TELEPORT_CONFIRM = 0x00,
        QUERY_BLOCK_NBT = 0x01,
        SET_DIFFICULTY = 0x02,
        SERVER_CHAT_MESSAGE = 0x03,
        CLIENT_STATUS = 0x04,
        CLIENT_SETTINGS = 0x05,
        SERVER_TAB_COMPLETE = 0x06,
        SERVER_CONFIRM_WINDOW = 0x07,
        CLICK_WINDOW_BUTTON = 0x08,
        CLICK_WINDOW = 0x09,
        SERVER_CLOSE_WINDOW = 0x0A,
        SERVER_PLUGIN_MESSAGE = 0x0B,
        EDIT_BOOK = 0x0C,
        QUERY_ENTITY_NBT = 0x0D,
        USE_ENTITY = 0x0E,
        SERVER_KEEP_ALIVE = 0x0F,
        LOCK_DFFICULTY = 0x10,
        PLAYER_POSITION = 0x11,
        SERVER_PLAYER_POSITION_LOOK = 0x12,
        PLAYER_LOOK = 0x13,
        PLAYER = 0x14,
        SERVER_VEHICLE_MOVE = 0x15,
        STEER_BOAT = 0x16,
        PICK_ITEM = 0x17,
        CRAFT_RECIPE_REQUEST = 0x18,
        SERVER_PLAYER_ABILITIES = 0x19,
        PLAYER_DIGGING = 0x1A,
        ENTITY_ACTION = 0x1B,
        STEER_VEHICLE = 0x1C,
        RECIPE_BOOK_DATA = 0x1D,
        NAME_ITEM = 0x1E,
        RESOURCE_PACK_STATUS = 0x1F,
        ADVANCEMENT_TAB = 0x20,
        SELECT_TRADE = 0x21,
        SET_BEACON_EFFECT = 0x22,
        SERVER_HELD_ITEM_CHANGE = 0x23,
        UPDATE_COMMAND_BLOCK = 0x24,
        UPDATE_COMMAND_BLOCK_MINECART = 0x25,
        CREATIVE_INVENTORY_ACTION = 0x26,
        UPDATE_JIGSAW_BLOCK = 0x27,
        UPDATE_STRUCTURE_BLOCK = 0x28,
        UPDATE_SIGN = 0x29,
        SERVER_ANIMATION = 0x2A,
        SPECTATE = 0x2B,
        PLAYER_BLOCK_PLACEMENT = 0x2C,
        USE_ITEM = 0x2D
    };

    enum OutPacketType {
        /* STATUS packets */
        LEGACY_RESPONSE = 0xFF,
        STATUS_RESPONSE = 0x00,
        STATUS_PONG = 0x01,

        /* LOGIN packets */
        LOGIN_DISCONNECT = 0x00,
        LOGIN_ENCRYPTION_REQUEST = 0x01,
        LOGIN_SUCCESS = 0x02,
        LOGIN_SET_COMPRESSION = 0x03,
        LOGIN_PLUGIN_REQUEST = 0x04,

        /* PLAY packets */
        SPAWN_OBJECT = 0x00,
        SPAWN_EXPERIENCE_ORB = 0x01,
        SPAWN_WEATHER_ENTITY = 0x02,
        SPAWN_MOB = 0x03,
        SPAWN_PAINTING = 0x04,
        SPAWN_PLAYER = 0x05,
        CLIENT_ANIMATION = 0x06,
        STATISTICS = 0x07,
        ACKNOWLEDGE_PLAYER_DIGGING = 0x08,
        BLOCK_BREAK_ANIMATION = 0x09,
        BLOCK_ENTITY_DATA = 0x0A,
        BLOCK_ACTION = 0x0B,
        BLOCK_CHANGE = 0x0C,
        BOSS_BAR = 0x0D,
        SERVER_DIFFICULTY = 0x0E,
        CLIENT_CHAT_MESSAGE = 0x0F,
        MULTI_BLOCK_CHANGE = 0x10,
        CLIENT_TAB_COMPLETE = 0x11,
        DECLARE_COMMANDS = 0x12,
        CLIENT_CONFIRM_WINDOW = 0x13,
        CLIENT_CLOSE_WINDOW = 0x14,
        WINDOW_ITEMS = 0x15,
        WINDOW_PROPERTY = 0x16,
        SET_SLOT = 0x17,
        SET_COOLDOWN = 0x18,
        CLIENT_PLUGIN_MESSAGE = 0x19,
        NAMED_SOUNDEFFECT = 0x1A,
        PLAY_DISCONNECT = 0x1B,
        ENTITY_STATUS = 0x1C,
        EXPLOSION = 0x1D,
        UNLOAD_CHUNK = 0x1E,
        CHANGE_GAME_STATE = 0x1F,
        OPEN_HORSE_WINDOW = 0x20,
        CLIENT_KEEP_ALIVE = 0x21,
        CHUNK_DATA = 0x22,
        EFFECT = 0x23,
        PARTICLE = 0x24,
        UPDATE_LIGHT = 0x25,
        JOIN_GAME = 0x26,
        MAP_DATA = 0x27,
        TRADE_LIST = 0x28,
        ENTITY_RELATIVE_MOVE = 0x29,
        ENTITY_LOOK_AND_RELATIVE_MOVE = 0x2A,
        ENTITY_LOOK = 0x2B,
        ENTITY = 0x2C,
        CLIENT_VEHICLE_MOVE = 0x2D,
        OPEN_BOOK = 0x2E,
        OPEN_WINDOW = 0x2F,
        OPEN_SIGN_EDITOR = 0x30,
        CRAFT_RECIPE_RESPONSE = 0x31,
        CLIENT_PLAYER_ABILITIES = 0x32,
        COMBAT_EVENT = 0x33,
        PLAYER_INFO = 0x34,
        FACE_PLAYER = 0x35,
        CLIENT_PLAYER_POSITION_LOOK = 0x36,
        UNLOCK_RECIPES = 0x37,
        DESTROY_ENTITIES = 0x38,
        REMOVE_ENTITY_EFFECT = 0x39,
        RESOURCE_PACK_SEND = 0x3A,
        RESPAWN = 0x3B,
        ENTITY_HEAD_LOOK = 0x3C,
        SELECT_ADVANCEMENT_TAB = 0x3D,
        WORLD_BORDER = 0x3E,
        CAMERA = 0x3F,
        CLIENT_HELD_ITEM_CHANGE = 0x40,
        UPDATE_VIEW_POS = 0x41,
        UPDATE_VIEW_DISTANCE = 0x42,
        DISPLAY_SCOREBOARD = 0x43,
        ENTITY_METADATA = 0x44,
        ATTACH_ENTITY = 0x45,
        ENTITY_VELOCITY = 0x46,
        ENTITY_EQUIPMENT = 0x47,
        SET_EXP = 0x48,
        UPDATE_HEALTH = 0x49,
        SCOREBOARD_OBJECTIVE = 0x4A,
        SET_PASSENGERS = 0x4B,
        TEAMS = 0x4C,
        UPDATE_SCORE = 0x4D,
        SPAWN_POSITION = 0x4E,
        TIME_UPDATE = 0x4F,
        TITLE = 0x50,
        ENTITY_SOUND_EFFECT = 0x51,
        SOUND_EFFECT = 0x52,
        STOP_SOUND = 0x53,
        PLAYER_LIST_HEADER_FOOTER = 0x54,
        NBT_QUERY_RESPONSE = 0x55,
        COLLECT_ITEM = 0x56,
        ENTITY_TELEPORT = 0x57,
        ADVANCEMENTS = 0x58,
        ENTITY_PROPERTIES = 0x59,
        ENTITY_EFFECT = 0x5A,
        DECLARE_RECIPES = 0x5B,
        TAGS = 0x5C,
    };

    class PacketBase {
    private:
        const uint32_t id;
    public:
        explicit PacketBase(uint32_t);

        virtual std::string toString() = 0;

        uint32_t getId();
    };

    std::string enumToString(OutPacketType type);

}
#endif //MCSERVER_PACKETBASE_HPP
