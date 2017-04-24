#include "gmock/gmock.h"
#include "AntHost.h"
#include <algorithm>
#include "SerialCommunication.h"

#define ANT_SYNCA 0b10100100
#define ANT_SYNC_RECV 0b10100101

class SerialCommuncationMock : public ISynchronousCommunication
{
public:
	MOCK_METHOD1(Write, void(const etl::ivector<uint8_t>& data));
	MOCK_METHOD0(ReadByte, uint8_t());
	MOCK_METHOD0(Init, void());
};

namespace
{
	static std::vector<uint8_t> inputVector;
	uint8_t pushInput()
	{
		uint8_t val = *inputVector.begin();
		inputVector.erase(inputVector.begin());
		return val;
	}

}

class TestAntHost : public ::testing::Test
{
protected:
	SerialCommuncationMock communicationMock;

	AntHost *ant;
	AntMessage message;

	virtual void SetUp()
	{
		EXPECT_CALL(communicationMock, Init());
		ant = new AntHost(communicationMock);
		EXPECT_CALL(communicationMock, ReadByte()).WillRepeatedly(testing::Invoke(pushInput));
	}
};

TEST_F(TestAntHost, invalid_crc)
{
	inputVector = { ANT_SYNC_RECV, 0x01, 0x41, 0xFF, 0xAA};

	ant->GetMessage(message);
	EXPECT_TRUE(message.is_valid());
	EXPECT_TRUE(message.is_type<ErrorMessage>());
	EXPECT_EQ(message.get<ErrorMessage>().reason, ErrorMessage::Reason::invalidCRC);
}


TEST_F(TestAntHost, receiving_unsupported_messages)
{
	inputVector = { ANT_SYNC_RECV, 0x01, 0xFF, 0xFF, 0xA4};
	ant->GetMessage(message);
	EXPECT_TRUE(message.is_valid());
	EXPECT_TRUE(message.is_type<ErrorMessage>());
	EXPECT_EQ(message.get<ErrorMessage>().reason, ErrorMessage::Reason::messageNotSupported);

	inputVector = { ANT_SYNC_RECV, 0x01, 0xFF, 0xAA, 0xF1};
	ant->GetMessage(message);
	EXPECT_TRUE(message.is_valid());
	EXPECT_TRUE(message.is_type<ErrorMessage>());
	EXPECT_EQ(message.get<ErrorMessage>().reason, ErrorMessage::Reason::messageNotSupported);
}

TEST_F(TestAntHost, parse_unassignedChannel_message)
{
	inputVector = { 0xBB, ANT_SYNC_RECV, 0x01, 0x41, 0xFF, 0x1A};
	ant->GetMessage(message);
	EXPECT_TRUE(message.is_valid());
	EXPECT_TRUE(message.is_type<UnassignChannel>());
	EXPECT_EQ(message.get<UnassignChannel>().channelId, 0xFF);
}
