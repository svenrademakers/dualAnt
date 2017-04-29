#include "MapController.hpp"
#include "IMapViewer.hpp"

MapController::MapController(IMapViewer& map)
 : mapviewer(map)
{
	Start();
}

MapController::~MapController()
{
	mapviewer.Exit();
}

void MapController::Start()
{
	mapviewer.Run();
}

void MapController::PositionUpdate(double longitude, double latitude)
{
	mapviewer.UpdatePosition(longitude, latitude);
}
