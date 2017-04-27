#ifndef MAP_VIEWER_TANGRAM_HPP
#define MAP_VIEWER_TANGRAM_HPP
#include "IMapViewer.hpp"

class MapViewerTangram : public IMapViewer
{
public:
	MapViewerTangram();
	virtual ~MapViewerTangram() {};

	// IMapViewer
	virtual void UpdatePosition(double longitude, double latitude);
	virtual void Run();
	virtual void Exit();
};

#endif
