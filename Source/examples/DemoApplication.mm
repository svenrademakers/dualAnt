#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <memory>
//#include "MapViewerTangram.hpp"
//#include "Gnss.hpp"
//#include "MapController.hpp"
#include "platform.h"
namespace
{
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
}

//class GnssDummy
//{
//public:
//	GnssDummy(IGnssObserver& observer)
//	: observer(observer)
//{
//}
//	void RandomLatLon()
//	{
//		observer.PositionUpdate(fRand(-90,90), fRand(-180,180));
//	}
//
//private:
//	IGnssObserver& observer;
//};

namespace Tangram
{
class DummyPlatform : public Platform
{
public:
    // Request that a new frame be rendered by the windowing system
    virtual void requestRender() const
    {
        
    }
    
    virtual bool startUrlRequest(const std::string& _url, UrlCallback _callback)
    {
        return false;
    }
    
    // Stop retrieving data from a URL that was previously requested
    virtual void cancelUrlRequest(const std::string& _url)
    {
        
    }

    
};
}

int main()
{
    auto platform = std::make_shared<Tangram::DummyPlatform>();
//	static MapViewerTangram mapviewerTangram(platform);
//	static MapController controller(mapviewerTangram);
//	static GnssDummy gnss(controller);
//
//	controller.Start();
//
//	while(1)
//	{
//		std::this_thread::sleep_for(std::chrono::seconds(1));
//		gnss.RandomLatLon();
//	}

	return 0;
}
