#ifndef SERIAL_COMMUNICATION_HPP
#define SERIAL_COMMUNICATION_HPP

#include "vector.h"

class AntRequestMessage;

class ISerialCommunication
{
public:
	virtual void Write(const etl::ivector<uint8_t>& data) = 0;
};

class IAntProxy
{
public:
	virtual void ExecuteCommand(const AntRequestMessage& message) = 0;
};

#endif
