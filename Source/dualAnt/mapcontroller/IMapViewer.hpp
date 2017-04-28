#ifndef MAP_VIEWER_INTERFACE_HPP
#define MAP_VIEWER_INTERFACE_HPP

class IMapViewer
{
public:
	virtual void UpdatePosition(double longitude, double latitude) = 0;
	virtual void Run() = 0;
	virtual void Exit() = 0;
};

#endif
