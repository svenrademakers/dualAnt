#include "AntParser.h"
#include <algorithm>

namespace
{

bool isSyncByte(uint8_t b)
{
	return b == ANT_SYNCA || b == ANT_SYNCB;
}

}

AntParser::AntParser()
: recvBuffer(0)
{
}

void AntParser::notification(const uint8_t byte)
{
	if ((recvBuffer.size()) == 0 && !isSyncByte(byte))
		return;

	recvBuffer.push_back(byte);

	if (recvBuffer.size() == 1)
		return;

	uint8_t size = MESSAGE_HEADER_SIZE + recvBuffer[1];
	if (recvBuffer.size() >= size)
	{
		notify_observers(1);
	}
}

void AntParser::GetLastProcessed(AntMessageVariant& message)
{
	if (recvBuffer.size() >= recvBuffer[1])
	{
		factory.createMessage(recvBuffer[2], message);
		message.get<AntBaseMessage>().Parse(recvBuffer);
		recvBuffer.clear();
	}
}
