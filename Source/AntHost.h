#ifndef ANT_PARSER_HPP
#define ANT_PARSER_HPP

#include "AntMessageFactory.h"
#include <stdint.h>
#include "vector.h"
#include "function.h"
#include "observer.h"
#include "antmessage.h"
#include "SerialCommunication.h"

class ISynchronousCommunication;

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
