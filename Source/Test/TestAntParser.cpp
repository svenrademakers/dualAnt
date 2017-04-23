#include "gmock/gmock.h"
#include "AntParser.h"
#include <algorithm>

#define ANT_SYNCA 0b10100100
#define ANT_SYNCB 0b10100101

class MessageObserver: public MessagePending
{
public:
	MOCK_METHOD1(notify, void(int));

	void notification(int a)
	{
		notify(a);
	}
};

class TestAntParser : public ::testing::Test
{
public:
	TestAntParser() {
		parser.add_observer(observer_mock);
    }

protected:
	AntParser parser;
	::testing::StrictMock<MessageObserver> observer_mock;

	void PushData(std::vector<uint8_t>& data) {
		for (auto i = data.begin(); i != data.end(); i++)
	{
		parser.notification(*i);
	}
}
};

TEST_F(TestAntParser, ignore_message_without_sync_byte) {
	AntMessage message;
	std::vector<uint8_t> vec = { 0x11, 0x22, 0x33 };
	PushData(vec);

	EXPECT_CALL(observer_mock, notify(::testing::_)).Times(0);
	EXPECT_FALSE(message.is_valid());
}

TEST_F(TestAntParser, ignore_message_with_invalid_crc) {
	AntMessage message;
	std::vector<uint8_t> vec = { ANT_SYNCA, 0x01, 0x41, 0xFF, 0xAA};
	PushData(vec);

	EXPECT_CALL(observer_mock, notify(::testing::_)).Times(0);
	EXPECT_FALSE(message.is_valid());
}


TEST_F(TestAntParser, internal_buffer_is_cleared_after_processing) {
	AntMessage message;
	EXPECT_CALL(observer_mock, notify(::testing::_)).Times(2);

	std::vector<uint8_t> vec = { ANT_SYNCA, 0x01, 0x41, 0xFF, 0x1B};
	PushData(vec);

	parser.GetLastProcessed(message);
	EXPECT_TRUE(message.is_valid());

	 vec = { ANT_SYNCA, 0x01, 0x41, 0xAA, 0x4E};
	 PushData(vec);

	parser.GetLastProcessed(message);
	EXPECT_TRUE(message.is_valid());
}

TEST_F(TestAntParser, parse_unassignedChannel_message)
{
	AntMessage message;
	EXPECT_CALL(observer_mock, notify(::testing::_)).Times(1);
	std::vector<uint8_t> vec = { 0xBB, ANT_SYNCA, 0x01, 0x41, 0xFF, 0x1B};
    PushData(vec);

	parser.GetLastProcessed(message);
	EXPECT_TRUE(message.is_valid());
	EXPECT_TRUE(message.is_type<UnassignChannel>());
	EXPECT_EQ(message.get<UnassignChannel>().channelId, 0xFF);
}
