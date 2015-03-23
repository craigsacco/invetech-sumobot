#include "SPIDevice.hpp"
#include "ISPI.hpp"
#include "DigitalOutput.hpp"

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

#if HAL_USE_SPI

SPIDevice::SPIDevice(ISPI* spi, DigitalOutput* chipSelect) :
    mSPI(spi),
    mDeviceConfig()
{
    mDeviceConfig.ChipSelect = chipSelect;
}

void SPIDevice::Start(uint32_t frequency)
{
    mDeviceConfig.Frequency = frequency;
    StartInternal(&mDeviceConfig);
    mSPI->Start(this);
}

void SPIDevice::Stop()
{
    StopInternal();
    mSPI->Stop();
}

void SPIDevice::Read(void* rxbuf, size_t len)
{
    mSPI->Read(rxbuf, len);
}

void SPIDevice::Write(void* txbuf, size_t len)
{
    mSPI->Write(txbuf, len);
}

void SPIDevice::Exchange(void* txbuf, void* rxbuf, size_t len)
{
    mSPI->Exchange(txbuf, rxbuf, len);
}

const SPIDeviceConfig* SPIDevice::GetConfig() const
{
    return const_cast<SPIDeviceConfig*>(&mDeviceConfig);
}

void SPIDevice::Select()
{
    mSPI->Select();
}

void SPIDevice::Unselect()
{
    mSPI->Unselect();
}

#endif // #if HAL_USE_SPI

}
}
