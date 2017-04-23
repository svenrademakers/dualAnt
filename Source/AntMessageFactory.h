#ifndef ANT_MESSAGE_FACTORY_HPP
#define ANT_MESSAGE_FACTORY_HPP

#include <stdint.h>
#include "vector.h"
#include "function.h"
#include "observer.h"
#include "map.h"
#include "AntMessage.h"
#include "variant.h"

#define MAX_SIZE_FACTORY_MESSAGE_BUFFER 5

class AntMessageFactory {
private:
	typedef etl::ifunction<AntBaseMessage&>* createObjectFunc;
	typedef etl::map<uint8_t, createObjectFunc, MAX_SIZE_FACTORY_MESSAGE_BUFFER> AntMessageCreationMap;

public:
	template<typename T>
	void registerClass(uint8_t id) {
		if (mObjectCreator.find(id) != mObjectCreator.end()) {

		}
		mObjectCreator[id] = &createObject<T>;
	}

	bool MessageRegistered(uint8_t id);
	void createMessage(uint8_t id, AntMessageVariant& message);

private:
	AntMessageCreationMap mObjectCreator;

	template<typename T>
	static void createObject(AntMessageVariant& message) {
		message = T();
	}
};

#endif
