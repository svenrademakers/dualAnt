#ifndef ANT_MESSAGE_HPP
#define ANT_MESSAGE_HPP

#include "variant.h"
#include "vector.h"

#define ANT_HEADERSIZE 5

class AntMessage
{
public:
	virtual ~AntMessage() {	}

	virtual void Parse(etl::ivector<uint8_t>& data) = 0;
};

class AntBaseMessage: public AntMessage
{
public:
	AntBaseMessage(uint8_t messageId)
	: messageId(messageId)
	{ }

	virtual void Parse(etl::ivector<uint8_t>& data)
	{ }

	const uint8_t messageId;
};

class UnassignChannel: public AntBaseMessage
{
public:
	UnassignChannel()
	: AntBaseMessage(0x41)
	, channelId(0)
	{ }

	virtual void Parse(etl::ivector<uint8_t>& data) {
		channelId = data[3];
	}

	uint8_t channelId;
};

typedef etl::variant<AntBaseMessage, UnassignChannel> AntMessageVariant;

#endif
