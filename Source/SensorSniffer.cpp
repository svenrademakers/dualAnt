#include "ant/AntMessageFactory.hpp"
#include "SensorSniffer.hpp"
#include "SerialCommunication.h"
#include "ant/AntHost.hpp"

SensorSniffer::SensorSniffer(IAntProxy& antProxy, IAntMessageFactory& factory)
: proxy(antProxy)
, factory(factory)
{ }

void SensorSniffer::Initialize()
{
	auto cmd = SetNetworkKey();
	proxy.ExecuteCommand(cmd);

}
