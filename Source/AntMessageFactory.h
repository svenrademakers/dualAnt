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
	typedef etl::ifunction<AntMessageVariant&>* createObjectFunc;
	typedef etl::map<uint8_t, createObjectFunc, MAX_SIZE_FACTORY_MESSAGE_BUFFER> AntMessageCreationMap;

public:
	AntMessageFactory() = default;

	template<typename T>
	void registerClass(uint8_t id) {
		if (mObjectCreator.find(id) != mObjectCreator.end()) {
			//your error handling here
		}
		mObjectCreator[id] = &createObject<T>;
	}

	bool ContainsMessage(uint8_t id) {
		return mObjectCreator.find(id) != mObjectCreator.end();
	}

	void createMessage(uint8_t id, AntMessageVariant& message) {
		typename AntMessageCreationMap::iterator iter =
				mObjectCreator.find(id);
		if (iter != mObjectCreator.end()) {
			(*(iter->second))(message);
		}
		else {
			message = AntMessage();
		}
	}

private:
	AntMessageCreationMap mObjectCreator;

	template<typename T>
	static void createObject(etl::variant<AntMessage>& message) {
		message = T();
	}
};

#endif
