#include "gtest/gtest.h"
#include "HbAlgo.hpp"

class TestHbAlgo : public ::testing::Test
{
public:
    TestHbAlgo()
    : heartbeatAlgo(20)
    {
    }

protected:
    HbAlgo heartbeatAlgo;
    etl::array<uint8_t, 4> zones;
};

TEST_F(TestHbAlgo, get_percentage_of_max_interval_given_RRInterval)
{
    int rr = 332; // ~180 bpm
    EXPECT_EQ(heartbeatAlgo.HrPercentage(rr), 90);

    rr = 300;
    EXPECT_EQ(heartbeatAlgo.HrPercentage(rr), 100);

    rr = 0; // ~180 bpm
    EXPECT_EQ(heartbeatAlgo.HrPercentage(rr), 0);
}

TEST_F(TestHbAlgo, RRInterval_faster_as_Max_still_returns_max)
{
    int rr = 2;
    EXPECT_EQ(100, heartbeatAlgo.HrPercentage(rr));
}

TEST_F(TestHbAlgo, value_in_zones)
{
    int out = heartbeatAlgo.HrZone(320);
    EXPECT_GE(out, 50);
    EXPECT_LT(out, 60);

    out = heartbeatAlgo.HrZone(333);
    EXPECT_GE(out, 40);
    EXPECT_LT(out, 50);

    out = heartbeatAlgo.HrZone(362);
    EXPECT_GE(out, 30);
    EXPECT_LT(out, 40);

    out = heartbeatAlgo.HrZone(391);
    EXPECT_GE(out, 20);
    EXPECT_LT(out, 30);

    out = heartbeatAlgo.HrZone(500);
    EXPECT_GE(out, 10);
    EXPECT_LT(out, 20);
}

TEST_F(TestHbAlgo, values_faster_as_max_result_in_0)
{
    int out = heartbeatAlgo.HrZone(0);
    EXPECT_EQ(0, out);

    out = heartbeatAlgo.HrZone(33);
    EXPECT_EQ(0, out);
}

TEST_F(TestHbAlgo, calculate_detailed_zone_based_on_Age)
{
    EXPECT_EQ(49, heartbeatAlgo.HrZone(332));
    EXPECT_EQ(59, heartbeatAlgo.HrZone(300));
    EXPECT_EQ(5, heartbeatAlgo.HrZone(435));
    EXPECT_EQ(40, heartbeatAlgo.HrZone(360));
}
