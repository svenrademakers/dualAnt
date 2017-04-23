#ifndef SENSOR_SNIFFER_HPP
#define SENSOR_SNIFFER_HPP

#include "AntMessage.hpp"

class IAntMessageFactory;
class IAntProxy;

class SensorSniffer
{
public:
	SensorSniffer(IAntProxy& antProxy, IAntMessageFactory& factory);
	void Initialize();

private:
	IAntProxy& proxy;
	IAntMessageFactory& factory;
};
#endif
