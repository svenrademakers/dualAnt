#include "AntParser.h"
#include <algorithm>

namespace {

bool isSyncByte(uint8_t b) {
	return b == ANT_SYNCA || b == ANT_SYNCB;
}

}

AntParser::AntParser()
{
}

void AntParser::notification(const etl::ivector<uint8_t>& message) {

	if (!message.empty()) {
		etl::ivector<uint8_t>::const_iterator it = std::find_if(
				message.cbegin(), message.cend(), isSyncByte);

		etl::ivector<uint8_t>::const_iterator end = message.end();

		if (it != message.end())
		{
			factory.createMessage(0x0, this->message);
			if (this->message.is_valid()) {
				this->message.get<AntMessage>().Parse(it, end);
			}
		}
	}
}

void AntParser::GetLastProcessed(AntMessageVariant& message) {
	message = this->message;
}
