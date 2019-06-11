//
// Created by jona on 2019-06-11.
//

#include "PacketInLoginPluginResponse.hpp"

namespace protocol {
    PacketInLoginPluginResponse::PacketInLoginPluginResponse(int32_t messageId, bool succesful, uint32_t dataLength,
                                                             uint8_t *data)
            : PacketInBase(0x02, LOGIN_PLUGIN_RESPONSE), messageId(messageId), successful(succesful),
              dataLength(dataLength), data(data) {

    }

    int32_t PacketInLoginPluginResponse::getMessageId() const {
        return messageId;
    }

    bool PacketInLoginPluginResponse::isSuccessful() const {
        return successful;
    }

    uint8_t *PacketInLoginPluginResponse::getData() const {
        return data;
    }

    uint32_t PacketInLoginPluginResponse::getDataLength() const {
        return dataLength;
    }

}