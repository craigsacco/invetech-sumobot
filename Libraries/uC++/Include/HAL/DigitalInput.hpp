#ifndef __UCPP_DIGITALINPUT_HPP__
#define __UCPP_DIGITALINPUT_HPP__

#include "uCCommon.hpp"
#include "IGPIO.hpp"
#include <hal.h>

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

class DigitalInput
{
public:
    DigitalInput(IGPIO* gpio, uint8_t index);
    ~DigitalInput() {}

public:
    bool Get() const;
    IGPIO* GetGPIO() const;
    uint8_t GetIndex() const;

private:
    IGPIO* mGPIO;
    uint8_t mIndex;
};

}
}

#endif // #ifndef __UCPP_DIGITALINPUT_HPP__
