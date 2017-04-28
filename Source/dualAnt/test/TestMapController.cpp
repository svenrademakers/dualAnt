#include "gmock/gmock.h"
#include "MapController.hpp"
#include "IMapViewer.hpp"

class MapViewerMock : public IMapViewer
{
public:
	MOCK_METHOD2(UpdatePosition, void(double longitude, double latitude));
	MOCK_METHOD0(Run, void());
	MOCK_METHOD0(Exit, void());
};

class TestMapController : public ::testing::Test
{
protected:
	::testing::StrictMock<MapViewerMock> mapviewer;
	MapController* mapcontroller;

	virtual void SetUp()
	{
		EXPECT_CALL(mapviewer, Run());
		mapcontroller = new MapController(mapviewer);
	}

	virtual void TearDown()
	{
		EXPECT_CALL(mapviewer, Exit());
		delete mapcontroller;
	}
};

TEST_F(TestMapController, update_mapviewer_when_a_position_update_is_received)
{
	EXPECT_CALL(mapviewer, UpdatePosition(123,321));
	mapcontroller->PositionUpdate(123,321);
}

