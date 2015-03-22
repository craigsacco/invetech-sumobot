#ifndef __UCPP_IGPIO_HPP__
#define __UCPP_IGPIO_HPP__

#include <stdint.h>

namespace uCpp
{

class IGPIO
{
public:
    virtual uint8_t GetWidth() const = 0;
    virtual uint32_t GetPort() const = 0;
    virtual uint32_t GetLatch() const = 0;
    virtual void SetPort(uint32_t value) = 0;
    virtual void ClearPort() = 0;
    virtual bool GetPad(uint8_t index) const = 0;
    virtual void SetPad(uint8_t index, bool state = true) = 0;
    virtual void ClearPad(uint8_t index) = 0;
};

}

#endif // #ifndef __UCPP_IGPIO_HPP__
