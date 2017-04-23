#ifndef ANT_PARSER_HPP
#define ANT_PARSER_HPP

#include <stdint.h>
#include "vector.h"
#include "function.h"
#include "observer.h"
#include "AntMessageFactory.h"

#define ANT_SYNCA 0b10100100
#define ANT_SYNCB 0b10100101
#define PARSE_BUFFER 30
#define MESSAGE_HEADER_SIZE 4

typedef etl::observer<int> MessagePending;

class AntParser: public etl::observer<uint8_t>,
		public etl::observable<MessagePending, 1>
{
public:
	AntParser();
    virtual ~AntParser() {}

	virtual void notification(uint8_t byte);
	void GetLastProcessed(AntMessageVariant& message);

private:
	bool CrcCheck();
	bool ValidMessage();
	AntMessageFactory factory;
	etl::vector<uint8_t, PARSE_BUFFER> recvBuffer;
};

#endif
