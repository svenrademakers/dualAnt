#ifndef ANT_MESSAGE_FACTORY_HPP
#define ANT_MESSAGE_FACTORY_HPP

#include "AntMessage.hpp"
#include <stdint.h>
#include "vector.h"
#include "function.h"
#include "observer.h"
#include "map.h"
#include "variant.h"

#define MAX_SIZE_FACTORY_MESSAGE_BUFFER 5

class IAntMessageFactory
{
public:
	virtual void CreateMessage(uint8_t id, AntMessage& message) = 0;
	virtual bool MessageTypeAvailable(uint8_t id) = 0;
};

class AntMessageFactory : public IAntMessageFactory{
private:
	typedef void (*createObjectFunc)(AntMessage&);
	typedef etl::map<uint8_t, createObjectFunc, MAX_SIZE_FACTORY_MESSAGE_BUFFER> AntMessageCreationMap;

public:
	template<typename T>
	void registerClass(uint8_t id) {
		if (mObjectCreator.find(id) != mObjectCreator.end()) {

		}
		mObjectCreator[id] = *createObject<T>;
	}

	virtual bool MessageTypeAvailable(uint8_t id);
	virtual void CreateMessage(uint8_t id, AntMessage& message);

private:
	AntMessageCreationMap mObjectCreator;

	template<typename T>
	static void createObject(AntMessage& message) {
		message = T();
	}
};

#endif
