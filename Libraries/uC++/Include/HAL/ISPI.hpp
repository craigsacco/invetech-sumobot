#ifndef __UCPP_ISPI_HPP__
#define __UCPP_ISPI_HPP__

#include "uCCommon.hpp"

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

class SPIDevice;

class ISPI
{
public:
    virtual void Start(SPIDevice* device) = 0;
    virtual void Stop() = 0;
    virtual void Select() = 0;
    virtual void Unselect() = 0;
    virtual void Read(void* rxbuf, size_t len) = 0;
    virtual void Write(void* txbuf, size_t len) = 0;
    virtual void Exchange(void* txbuf, void* rxbuf, size_t len) = 0;
    virtual void Acquire() = 0;
    virtual void Release() = 0;
};

}
}

#endif // #ifndef __UCPP_ISPI_HPP__
