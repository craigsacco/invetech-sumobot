#ifndef __UCPP_DIGITALINPUT_HPP__
#define __UCPP_DIGITALINPUT_HPP__

#include "IGPIO.hpp"
#include <hal.h>

namespace uCpp
{

class DigitalInput
{
public:
    DigitalInput(IGPIO* gpio, uint8_t index);
    ~DigitalInput() {}

public:
    inline bool Get() const;

private:
    IGPIO* mGPIO;
    uint8_t mIndex;
};

}

#endif // #ifndef __UCPP_DIGITALINPUT_HPP__
