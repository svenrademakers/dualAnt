#include "AntHost.hpp"

bool AntMessageFactory::MessageTypeAvailable(uint8_t id){
	return mObjectCreator.find(id) != mObjectCreator.end();
}

void AntMessageFactory::CreateMessage(uint8_t id, AntMessage& message) {
	typename AntMessageCreationMap::iterator iter =
			mObjectCreator.find(id);
	if (iter != mObjectCreator.end()) {
		(*(iter->second))(message);
	}
	else {
		message = ErrorMessage(ErrorMessage::Reason::messageNotSupported);
	}
}
