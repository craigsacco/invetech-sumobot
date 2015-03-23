#ifndef __UCPP_VS1003_HPP__
#define __UCPP_VS1003_HPP__

#include "uCCommon.hpp"
#include "SPIDevice.hpp"

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

#if HAL_USE_SPI

class VS1003 : public SPIDevice
{
public:
    VS1003(ISPI* spi, DigitalOutput* chipSelect);
    ~VS1003() {}

protected:
    void StartInternal(SPIDeviceConfig* config) override final;
    void StopInternal() override final;
};

#endif // #if HAL_USE_SPI

}
}

#endif // #ifndef __UCPP_VS1003_HPP__
