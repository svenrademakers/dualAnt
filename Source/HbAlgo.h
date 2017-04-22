#ifndef HB_ALG_HPP
#define HB_ALG_HPP

#include <stdint.h>
#include "array.h"

class HbAlgo
{
public:
    HbAlgo(uint8_t defaultAge);
    virtual ~HbAlgo() {}
    
    uint32_t HrPercentage(uint32_t RRinterval);
    uint16_t HrZone(uint32_t RRInterval);
    
private:
    void CalculateDefaultZones();
    uint16_t RRInterval(uint8_t percentageMaxRR);
    
    uint32_t fastestRR;
    etl::array<uint16_t, 6> hrZone;
};

#endif
