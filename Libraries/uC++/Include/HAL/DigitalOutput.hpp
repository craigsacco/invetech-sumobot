#ifndef __UCPP_DIGITALOUTPUT_HPP__
#define __UCPP_DIGITALOUTPUT_HPP__

#include "uCCommon.hpp"
#include "IGPIO.hpp"
#include <hal.h>

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

class DigitalOutput
{
public:
    DigitalOutput(IGPIO* gpio, uint8_t index);
    ~DigitalOutput() {}

public:
    bool Get() const;
    void Set(bool state = true);
    void Clear();
    IGPIO* GetGPIO() const;
    uint8_t GetIndex() const;

private:
    IGPIO* mGPIO;
    uint8_t mIndex;
};

}
}

#endif // #ifndef __UCPP_DIGITALOUTPUT_HPP__
