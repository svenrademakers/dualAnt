#include "AntMessageFactory.h"
#include "SensorSniffer.h"
#include "antmessage.h"
#include "SerialCommunication.h"

SensorSniffer::SensorSniffer(IAntProxy& antProxy, IAntMessageFactory& factory)
: proxy(antProxy)
, factory(factory)
{ }

void SensorSniffer::Initialize()
{
	auto cmd = SetNetworkKey();
	proxy.ExecuteCommand(cmd);

}
