#ifndef GNSS_INTERFACE_HPP
#define GNSS_INTERFACE_HPP

class IGnssObserver
{
public:
	virtual void PositionUpdate(double longitude, double latitude) = 0;
};

#endif
