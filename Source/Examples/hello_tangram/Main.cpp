#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>

#include "MapViewerTangram.h"
#include "Gnss.hpp"
#include "MapController.hpp"

namespace
{
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
}

class GnssDummy
{
public:
	GnssDummy(IGnssObserver& observer)
	: observer(observer)
{
}
	void RandomLatLon()
	{
		observer.PositionUpdate(fRand(0,30), fRand(0,30));
	}

private:
	IGnssObserver& observer;
};

int main()
{
	static MapViewerTangram mapviewerTangram;
	static MapController controller(mapviewerTangram);
	static GnssDummy gnss(controller);

	controller.Start();

	while(1)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		gnss.RandomLatLon();
	}

	return 0;
}