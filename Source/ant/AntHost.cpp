#include "AntHost.hpp"
#include <algorithm>
#include "SerialCommunication.h"

namespace
{
bool isSyncByte(uint8_t b)
{
	return b == MESG_RX_SYNC;
}
}

AntHost::AntHost(ISynchronousCommunication& communication)
: recvBuffer(0)
, communication(communication)
{
	communication.Init();

	factory.registerClass<UnassignChannel>(0x41);
}

void AntHost::GetMessage(AntMessage& message)
{
    while(!FullFrame())
    {
        uint8_t byte = communication.ReadByte();

        if (recvBuffer.size() == 0 && !isSyncByte(byte))
            continue;
        else
            recvBuffer.push_back(byte);
    }

    if (CrcCheck())
    {
		factory.CreateMessage(recvBuffer[2], message);
		message.get<AntResponseMessage>().Parse(recvBuffer);
    }
    else
    	message = ErrorMessage(ErrorMessage::Reason::invalidCRC);

	recvBuffer.clear();

}

void AntHost::ExecuteCommand(const AntRequestMessage& message)
{
	// TODO
}

bool AntHost::CrcCheck()
{
	uint8_t crc = 0;
	for(auto it = recvBuffer.begin(); it < (recvBuffer.end()-1); it++)
	{
		crc ^= *it;
	}

	uint8_t val =  recvBuffer.back();
	return crc == val;
}

bool AntHost::FullFrame()
{
	return (recvBuffer.size() > 2 ) &&
			(recvBuffer.size() >= (MESG_FRAME_SIZE + recvBuffer[1]));
}
