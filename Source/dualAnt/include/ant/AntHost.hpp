#ifndef ANT_PARSER_HPP
#define ANT_PARSER_HPP

#include "AntMessageFactory.hpp"
#include <stdint.h>
#include "vector.h"
#include "function.h"
#include "observer.h"
#include "antmessage.h"

class ISynchronousCommunication;

class IAntProxy
{
public:
	virtual void ExecuteCommand(const AntRequestMessage& message) = 0;
};

class AntHost : public IAntProxy
{
public:
	AntHost(ISynchronousCommunication& communication);
    virtual ~AntHost() {}

    void GetMessage(AntMessage& message);

    virtual void ExecuteCommand(const AntRequestMessage& message);

private:
	bool CrcCheck();
	bool FullFrame();

	ISynchronousCommunication& communication;
	AntMessageFactory factory;
	etl::vector<uint8_t, MESG_BUFFER_SIZE> recvBuffer;
};

#endif
