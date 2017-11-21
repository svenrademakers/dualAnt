#ifndef SERIAL_COMMUNICATION_HPP
#define SERIAL_COMMUNICATION_HPP

#include "vector.h"

class AntRequestMessage;

class ISynchronousCommunication
{
public:
	virtual void Write(const etl::ivector<uint8_t>& data) = 0;
	virtual uint8_t ReadByte() = 0;
	virtual void Init() = 0;
};

#endif
