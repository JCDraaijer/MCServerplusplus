//
// Created by jona on 2019-06-09.
//

#ifndef MCSERVER_PACKETBASE_HPP
#define MCSERVER_PACKETBASE_HPP

#define enumToStr(x) #x
#define enumToStrx(x) enumToStr(x)

#include <string>

namespace protocol {
    enum InPacketType {
        HANDSHAKE = 0x00,
        LEGACY_PING = 0xFE,
        STATUS_REQUEST = 0x00,
        PING = 0x01,
        LOGIN_START = 0x00,
        ENCRYPTION_RESPONSE = 0x01,
        LOGIN_PLUGIN_RESPONSE = 0x02,
        TELEPORT_CONFIRM = 0x00,
        QUERY_BLOCK_NBT = 0x01,
        SET_DIFFICULTY = 0x02,
        SERVER_CHAT_MESSAGE = 0x03,
        CLIENT_STATUS = 0x04,
        CLIENT_SETTINGS = 0x05,
        SERVER_TAB_COMPLETE = 0x06,
        SERVER_CONFIRM_TRANSACTION = 0x07,
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
        LEGACY_RESPONSE = 0xFF,
        STATUS_RESPONSE = 0x00,
        STATUS_PONG = 0x01,
        LOGIN_DISCONNECT = 0x00,
        LOGIN_ENCRYPTION_REQUEST = 0x01,
        LOGIN_SUCCESS = 0x02,
        LOGIN_SET_COMPRESSION = 0x03,
        SPAWN_OBJECT = 0x00,
        SPAWN_EXPERIENCE_ORB = 0x01,
        SPAWN_GLOBAL_ENTITY = 0x02,
        SPAWN_MOB = 0x03,
        SPAWN_PAINTING = 0x04,
        SPAWN_PLAYER = 0x05,
        CLIENT_ANIMATION = 0x06,
        STATISTICS = 0x07,
        BLOCK_BREAK_ANIMATION = 0x08,
        UPDATE_BLOCK_ENTITYU = 0x09,
        BLOCK_ACTION = 0x0A,
        BLOCK_CHANGE = 0x0B,
        BOSS_BAR = 0x0C,
        SERVER_DIFFICULTY = 0x0D,
        CLIENT_CHAT_MESSAGE = 0x0E,
        MULTI_BLOCK_CHANGE = 0x0F,
        CLIENT_TAB_COMPLETE = 0x10,
        DECLARE_COMMANDS = 0x11,
        CLIENT_CONFIRM_TRANSACTION = 0x12,
        CLIENT_CLOSE_WINDOW = 0x13,
        WINDOW_ITEMS = 0x14,
        WINDOW_PROPERTY = 0x15,
        SET_SLOT = 0x16,
        SET_COOLDOWN = 0x17,
        CLIENT_PLUGIN_MESSAGE = 0x18,
        NAMED_SOUNDEFFECT = 0x19,
        PLAY_DISCONNECT = 0x1A,
        ENTITY_STATUS = 0x1B,
        EXPLOSION = 0x1C,
        UNLOAD_CHUNK = 0x1D,
        CHANGE_GAME_STATE = 0x1E,
        OPEN_HORSE_WINDOW = 0x1F,
        CLIENT_KEEP_ALIVE = 0x20,
        CHUNK_DATA = 0x21,
        EFFECT = 0x22,
        PARTICLE = 0x23,
        UPDATE_LIGHT = 0x24,
        JOIN_GAME = 0x25,
        MAP_DATA = 0x26,
        TRADE_LIST = 0x27,
        ENTITY_RELATIVE_MOVE = 0x28,
        ENTITY_LOOK_AND_RELATIVE_MOVE = 0x29,
        ENTITY_LOOK = 0x2A,
        ENTITY = 0x2B,
        CLIENT_VEHICLE_MOVE = 0x2C,
        OPEN_BOOK = 0x2D,
        OPEN_WINDOW = 0x2E,
        OPEN_SIGN_EDITOR = 0x2F,
        CRAFT_RECIPE_RESPONSE = 0x30,
        CLIENT_PLAYER_ABILITIES = 0x31,
        COMBAT_EVENT = 0x32,
        PLAYER_INFO = 0x33,
        FACE_PLAYER = 0x34,
        CLIENT_PLAYER_POSITION_LOOK = 0x35,
        UNLOCK_RECIPES = 0x36,
        DESTROY_ENTITIES = 0x37,
        REMOVE_ENTITY_EFFECT = 0x38,
        RESOURCE_PACK_SEND = 0x39,
        RESPAWN = 0x3A,
        ENTITY_HEAD_LOOK = 0x3B,
        SELECT_ADVANCEMENT_TAB = 0x3C,
        WORLD_BORDEDR = 0x3D,
        CAMERA = 0x3E,
        CLIENT_HELD_ITEM_CHANGE = 0x3F,
        UPDATE_VIEW_POS = 0x40,
        UPDATE_VIEW_DISTANCE = 0x41,
        DISPLAY_SCOREBOARD = 0x42,
        ENTITY_METADATA = 0x43,
        ATTACH_ENTITY = 0x44,
        ENTITY_VELOCITY = 0x45,
        ENTITY_EQUIPMENT = 0x46,
        SET_EXP = 0x46,
        UPDATE_HEALTH = 0x48,
        SCOREBOARD_OBJECTIVE = 0x49,
        SET_PASSENGERS = 0x4A,
        TEAMS = 0x4B,
        UPDATE_SCORE = 0x4C,
        SPAWN_POSITION = 0x4D,
        TIME_UPDATE = 0x4E,
        TITLE = 0x4F,
        ENTITY_SOUND_EFFECT = 0x50,
        SOUND_EFFECT = 0x51,
        STOP_SOUND = 0x52,
        PLAYER_LIST_HEADER_FOOTER = 0x53,
        NBT_QUERY_RESPONSE = 0x54,
        COLLECT_ITEM = 0x55,
        ENTITY_TELEPORT = 0x56,
        ADVANCEMENTS = 0x57,
        ENTITY_PROPERTIES = 0x58,
        ENTITY_EFFECT = 0x59,
        DECLARE_RECIPES = 0x5A,
        TAGS = 0x5B,
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
