#include "AntParser.h"

bool AntMessageFactory::MessageRegistered(uint8_t id){
	return mObjectCreator.find(id) != mObjectCreator.end();
}

void AntMessageFactory::createMessage(uint8_t id, AntMessageVariant& message) {
	typename AntMessageCreationMap::iterator iter =
			mObjectCreator.find(id);
	if (iter != mObjectCreator.end()) {
		(*(iter->second))(message);
	}
	else {
		message = AntBaseMessage(0xFF);
	}
}
