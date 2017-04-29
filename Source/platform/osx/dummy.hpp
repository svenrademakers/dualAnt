#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "platform.h"

namespace Tangram
{

class DummyPlatform : public Platform
{
public:
    // Request that a new frame be rendered by the windowing system
    virtual void requestRender() const;
    virtual bool startUrlRequest(const std::string& _url, UrlCallback _callback);
    
    // Stop retrieving data from a URL that was previously requested
    virtual void cancelUrlRequest(const std::string& _url);
};
}

#endif
