#ifndef MAP_CONTROLLER_HPP
#define MAP_CONTROLLER_HPP

#include <cstdint>
#include "Gnss.hpp"

class IMapViewer;

class MapController : public IGnssObserver
{
public:
	static const uint8_t height = 20;
	static const uint8_t width = 20;

	MapController(IMapViewer& map);
	virtual ~MapController();
	void Start();

	// IGnssObserver
	virtual void PositionUpdate(double longitude, double latitude);
private:
	IMapViewer& mapviewer;
};

#endif
