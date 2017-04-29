#include "MapController.hpp"
#include "IMapViewer.hpp"

MapController::MapController(IMapViewer& map)
 : mapviewer(map)
{
	if (mapviewer.Init(width, height))
	Start();
}

MapController::~MapController()
{}

void MapController::Start()
{
	mapviewer.Run();
}

void MapController::PositionUpdate(double longitude, double latitude)
{
	mapviewer.UpdatePosition(longitude, latitude);
}
