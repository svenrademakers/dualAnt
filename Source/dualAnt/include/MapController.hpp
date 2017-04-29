#ifndef MAP_CONTROLLER_HPP
#define MAP_CONTROLLER_HPP

#include "Gnss.hpp"

class IMapViewer;

class MapController : public IGnssObserver
{
public:
	MapController(IMapViewer& map);
	virtual ~MapController();
	void Start();

	// IGnssObserver
	virtual void PositionUpdate(double longitude, double latitude);
private:
	IMapViewer& mapviewer;
};

#endif
