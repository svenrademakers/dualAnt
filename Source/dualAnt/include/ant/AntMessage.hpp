#ifndef ANT_MESSAGE_HPP
#define ANT_MESSAGE_HPP
#include "vector.h"

#include "variant.h"

#define ANT_HEADERSIZE 5

class AntResponseMessage
{
public:
	virtual ~AntResponseMessage() {}

	virtual void Parse(const etl::ivector<uint8_t>& data) = 0;
};

class AntRequestMessage
{
public:
	virtual ~AntRequestMessage() {}
	virtual void Serialize(etl::ivector<uint8_t>& data) = 0;
};

class SetNetworkKey : public AntRequestMessage
{
public:
	virtual void Serialize(etl::ivector<uint8_t>& data){
		data.insert((data.begin()+ 3), networkKey.begin(), networkKey.end());
	}
private:
	// ANT+ key
	static const etl::array<uint8_t, 8> networkKey;
};

class ErrorMessage : public AntResponseMessage
{
public:
	enum Reason
	{
		invalidCRC,
		messageNotSupported
	};

	ErrorMessage(Reason reason)
	: reason(reason)
	{}

	virtual void Parse(const etl::ivector<uint8_t>& data) {
	}

	Reason reason;
};

class OpenChannel : public AntResponseMessage
{
public:
	virtual void Parse(const etl::ivector<uint8_t>& data) {
		channelId = data[3];
	}

	uint8_t channelId;
};

class UnassignChannel: public AntResponseMessage
{
public:

	virtual void Parse(const etl::ivector<uint8_t>& data) {
		channelId = data[3];
	}

	uint8_t channelId;
};

typedef etl::variant<AntResponseMessage, UnassignChannel, ErrorMessage, OpenChannel> AntMessage;

#endif
