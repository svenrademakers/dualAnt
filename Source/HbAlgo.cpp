#include "HbAlgo.h"

namespace
{
    const uint8_t maxBpm = 220;
}

HbAlgo::HbAlgo(uint8_t defaultAge)
: fastestRR(60000/(maxBpm-defaultAge))
, hrZone()
{
    CalculateDefaultZones();
}

void HbAlgo::CalculateDefaultZones()
{
    hrZone[0] = fastestRR;
    hrZone[1] = RRInterval(90);
    hrZone[2] = RRInterval(80);
    hrZone[3] = RRInterval(70);
    hrZone[4] = RRInterval(60);
    hrZone[5] = RRInterval(50);
}

uint16_t HbAlgo::RRInterval(uint8_t percentageMaxRR)
{
    return ((200 - percentageMaxRR)*fastestRR)/100;
}

uint32_t HbAlgo::HrPercentage(uint32_t RRinterval)
{
    if (RRinterval == 0)
        return 0;
    else if ( RRinterval <= fastestRR)
        return 100;
    
    return 200 - ((RRinterval*100)/fastestRR);
}

uint16_t HbAlgo::HrZone(uint32_t RRInterval)
{
    if (RRInterval > hrZone[5])
        RRInterval = hrZone[5];
    else if(RRInterval < hrZone[0])
        return 0;
    else if (RRInterval == hrZone[0])
        return 59;
    
    auto it = hrZone.begin();
    uint8_t i = hrZone.size();
    for (; i > 0 ; i--)
    {
        if (RRInterval < *it)
            break;
        it++;
    }
    
    if (i == 1)
        i = 0;
    
    uint16_t end = *it - *(it-1);
    uint16_t val = *it - RRInterval;
    uint16_t res = (val*1000)/(end);
    return (i*1000 + res)/100;
}