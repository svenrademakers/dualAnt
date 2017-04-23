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
	AntMessageVariant message;
	::testing::StrictMock<MessageObserver> observer_mock;

	void PushData(std::vector<uint8_t>& data) {
		for (auto i = data.begin(); i != data.end(); i++)
	{
		parser.notification(*i);
	}
}
};

TEST_F(TestAntParser, ignore_message_without_sync_byte) {
	std::vector<uint8_t> vec = { 0x11, 0x22, 0x33 };
	PushData(vec);
	parser.GetLastProcessed(message);

	EXPECT_FALSE(message.is_valid());
}
//
//TEST_F(TestAntParser, get_unparsable_ant_message_ignore_unexpected_start_bytes) {
//	std::vector<uint8_t> vec =
//	{ 0x11, ANT_SYNCA, 0x02, 0xAA, 0xBB, 0xAA, 0xFF, 0xFF };
//
//    EXPECT_CALL(observer_mock, notify(::testing::_)).Times(11);
//
//	PushData(vec);
//	parser.GetLastProcessed(message);
//
//	EXPECT_TRUE(message.is_valid());
//    EXPECT_TRUE(message.is_type<AntBaseMessage>());
//
//	auto rawOutput = std::vector<uint8_t>(vec.begin() + 1, vec.end());
//
//	AntBaseMessage& ant = message.get<AntBaseMessage>();
//	auto rawMessage = std::vector<uint8_t>(ant.rawBuffer->begin(),
//			ant.rawBuffer->end());
//
//	EXPECT_EQ(rawMessage, rawOutput);
//}
