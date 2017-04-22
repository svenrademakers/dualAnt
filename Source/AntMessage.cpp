#include "AntMessage.h"

void AntMessage::Parse(etl::ivector<uint8_t>::const_iterator& begin,
		etl::ivector<uint8_t>::const_iterator& end) {
	this->begin = begin;
	this->end = end;
}
