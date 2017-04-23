#include <AntMessageFactory.h>
#include "gmock/gmock.h"
#include "SensorSniffer.h"
#include "antmessage.h"
#include "SerialCommunication.h"
#include "AntMessage.hpp"

using testing::_;
using testing::SetArgReferee;
using testing::ByRef;
using testing::Eq;

class AntProxyMock : public IAntProxy
{
public:
	MOCK_METHOD1(ExecuteCommand, void(const AntRequestMessage&));
};

class SerialCommunicationMock : public ISerialCommunication
{
public:
	MOCK_METHOD1(Write, void(const etl::ivector<uint8_t>&));
};

class AntFactoryMock : public IAntMessageFactory
{
public:
	MOCK_METHOD2(CreateMessage, void(uint8_t id, AntMessage& message));
	MOCK_METHOD1(MessageTypeAvailable, bool(uint8_t id));
};

class TestSensorSniffer : public ::testing::Test
{
public:
	TestSensorSniffer()
	: sniffer(proxy, factory)

    { }

	SensorSniffer sniffer;
	::testing::StrictMock<AntProxyMock> proxy;
	::testing::StrictMock<AntFactoryMock> factory;
	AntMessage messageBuffer;

};

TEST_F(TestSensorSniffer, set_sniffer_configuration_ant_plus)
{
	// fix polymorphic matchers
}
