#ifndef __UCPP_DIGITALOUTPUT_HPP__
#define __UCPP_DIGITALOUTPUT_HPP__

#include "IGPIO.hpp"
#include <hal.h>

namespace uCpp
{

class DigitalOutput
{
public:
    DigitalOutput(IGPIO* gpio, uint8_t index);
    ~DigitalOutput() {}

public:
    inline bool Get() const;
    inline void Set(bool state = true);
    inline void Clear();

private:
    IGPIO* mGPIO;
    uint8_t mIndex;
};

}

#endif // #ifndef __UCPP_DIGITALOUTPUT_HPP__
