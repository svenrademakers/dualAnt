#ifndef ANT_MESSAGE_HPP
#define ANT_MESSAGE_HPP

#include "variant.h"
#include "vector.h"

class AntConfigurationMessage;
class AntMessage;

typedef etl::variant<AntMessage, AntConfigurationMessage> AntMessageVariant;

class AntMessage {

public:

	AntMessage() = default;

	virtual ~AntMessage() {
	}

	virtual void Parse(etl::ivector<uint8_t>::const_iterator& begin,
			etl::ivector<uint8_t>::const_iterator& end);

	etl::ivector<uint8_t>::const_iterator begin;
	etl::ivector<uint8_t>::const_iterator end;

};

class AntConfigurationMessage: public AntMessage {
public:
	AntConfigurationMessage() = default;
};
#endif
