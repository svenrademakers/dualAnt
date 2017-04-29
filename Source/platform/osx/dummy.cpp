#include "dummy.hpp"
namespace Tangram
{
    // Request that a new frame be rendered by the windowing system
    void DummyPlatform::requestRender() const
    {
        
    }
    
    bool DummyPlatform::startUrlRequest(const std::string& _url, UrlCallback _callback)
    {
        return false;
    }
    
    // Stop retrieving data from a URL that was previously requested
    void DummyPlatform::cancelUrlRequest(const std::string& _url)
    {
        
    }

}