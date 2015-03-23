#include "VS1003.hpp"

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

#if HAL_USE_SPI

VS1003::VS1003(ISPI* spi, DigitalOutput* chipSelect) :
    SPIDevice(spi, chipSelect)
{
}

void VS1003::StartInternal(SPIDeviceConfig* config)
{
    config->ClockPhase = false;
    config->ClockPolarity = false;
    config->SendLSBFirst = false;
    config->FrameFormat = false;
    config->CRCPolynomial = 7;
}

void VS1003::StopInternal()
{
}

#endif // #if HAL_USE_SPI

}
}
