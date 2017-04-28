#include "MapViewerTangram.hpp"
MapViewerTangram::MapViewerTangram(std::shared_ptr<Tangram::Platform> platform)
	: map(new Tangram::Map(platform))
 {}

void MapViewerTangram::UpdatePosition(double longitude, double latitude)
{

}

void MapViewerTangram::Run()
{
	map = new Tangram::Map(platform);
}

void MapViewerTangram::Exit()
{

}

