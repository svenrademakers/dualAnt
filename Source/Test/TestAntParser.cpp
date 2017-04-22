#include "gtest/gtest.h"
#include "AntParser.h"

#define ANT_SYNCA 0b10100100
#define ANT_SYNCB 0b10100101

class TestAntParser : public ::testing::Test
{
public:
	TestAntParser() {
    }

protected:
	AntParser parser;
	AntMessageVariant message;
};

TEST_F(TestAntParser, ignore_message_without_sync_byte) {
	std::vector<uint8_t> vec = { 0x11, 0x22, 0x33 };
	auto etlVec = etl::vector<uint8_t, 3>(vec.begin(), vec.end());
	parser.notification(etlVec);
	parser.GetLastProcessed(message);

	EXPECT_FALSE(message.is_valid());
}

TEST_F(TestAntParser, get_unparsable_ant_message_ignore_unexpected_start_bytes) {
	std::vector<uint8_t> vec = { 0x11, ANT_SYNCA, 0x33, 0xAA, 0xBB };
	auto etlVec = etl::vector<uint8_t, 5>(vec.begin(), vec.end());
	parser.notification(etlVec);
	parser.GetLastProcessed(message);

	EXPECT_TRUE(message.is_valid());
    EXPECT_TRUE(message.is_type<AntMessage>());

	auto ant = message.get<AntMessage>();
	auto rawOutput = std::vector<uint8_t>(vec.begin() + 1, vec.end());
	auto rawMessage = std::vector<uint8_t>(ant.begin, ant.end);

	EXPECT_EQ(rawMessage, rawOutput);
}
