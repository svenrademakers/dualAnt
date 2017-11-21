#ifndef MAP_VIEWER_INTERFACE_HPP
#define MAP_VIEWER_INTERFACE_HPP

class IMapViewer
{
public:
	virtual bool Init(int width, int height) = 0;
	virtual void UpdatePosition(double longitude, double latitude) = 0;
	virtual void Run() = 0;
};

#endif
