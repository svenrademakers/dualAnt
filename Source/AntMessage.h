#ifndef ANT_MESSAGE_HPP
#define ANT_MESSAGE_HPP

#include "variant.h"
#include "vector.h"

#define ANT_HEADERSIZE 5

class AntMessage {
public:
	virtual ~AntMessage() {
	}

	virtual void Parse(etl::ivector<uint8_t>& data) = 0;
};

class AntBaseMessage: public AntMessage {
public:
    AntBaseMessage()
    : rawBuffer(nullptr)
    {
        
    }
	virtual void Parse(etl::ivector<uint8_t>& data) {
		rawBuffer = &data;
	}

	etl::ivector<uint8_t>* rawBuffer;
};

class UnassignChannel: public AntMessage {
public:
	uint8_t channelId;

	virtual void Parse(etl::ivector<uint8_t>& data) {
		channelId = data[3];
	}
};

typedef etl::variant<AntBaseMessage, UnassignChannel> AntMessageVariant;

#endif
