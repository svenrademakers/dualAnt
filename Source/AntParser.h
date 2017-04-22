#ifndef ANT_PARSER_HPP
#define ANT_PARSER_HPP

#include <stdint.h>
#include "vector.h"
#include "function.h"
#include "observer.h"
#include "AntMessageFactory.h"

#define ANT_SYNCA 0b10100100
#define ANT_SYNCB 0b10100101

class AntParser: public etl::observer<const etl::ivector<uint8_t>&>
{
public:
	AntParser();
    virtual ~AntParser() {}

	virtual void notification(const etl::ivector<uint8_t>& message);
	void GetLastProcessed(AntMessageVariant& message);

private:
	AntMessageFactory factory;
	AntMessageVariant message;
};

#endif
