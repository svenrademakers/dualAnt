#ifndef MAP_VIEWER_TANGRAM_HPP
#define MAP_VIEWER_TANGRAM_HPP
#include "IMapViewer.hpp"
#include "tangram.h"
#include "platform.h"

class MapViewerTangram : public IMapViewer
{
public:
	MapViewerTangram(std::shared_ptr<Tangram::Platform> platform);
	virtual ~MapViewerTangram() {};

	// IMapViewer
	virtual void UpdatePosition(double longitude, double latitude);
	virtual void Run();
	virtual void Exit();
private:
	Tangram::Map* map;
	std::shared_ptr<Tangram::Platform> platform;
};

#endif