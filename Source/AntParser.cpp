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
	factory.registerClass<UnassignChannel>(0x41);
}

void AntParser::notification(const uint8_t byte)
{
	if ((recvBuffer.size() == 0) && !isSyncByte(byte))
		return;

	recvBuffer.push_back(byte);

	if(ValidMessage())
		notify_observers(1);
}

void AntParser::GetLastProcessed(AntMessage& message)
{
	if (ValidMessage())
	{
		factory.CreateMessage(recvBuffer[2], message);

		// really need
		message.get<AntResponseMessage>().Parse(recvBuffer);
		recvBuffer.clear();
	}
}

bool AntParser::CrcCheck()
{
	uint8_t crc = 0;
	for(auto it = recvBuffer.begin(); it < (recvBuffer.end()-1); it++)
	{
		crc ^= *it;
	}

	uint8_t val =  recvBuffer.back();
	return crc == val;
}

bool AntParser::ValidMessage()
{
	return (recvBuffer.size() > 2 ) &&
			(recvBuffer.size() >= (MESSAGE_HEADER_SIZE + recvBuffer[1]) &&
			CrcCheck());
}
