#include "SPIDevice.hpp"

namespace uCpp
{

#if HAL_USE_SPI

SPIDevice::SPIDevice(SPI* spi, DigitalOutput* chipSelect) :
    mSPI(spi),
    mChipSelect(chipSelect)
{
}

void SPIDevice::Start(uint32_t frequency)
{
    SPI::Config config;
    config.ChipSelect = mChipSelect;
    config.BaudRate = SPI::GetBaudRateSelection(frequency);
    StartInternal(&config);
    mSPI->Start(config);
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

#endif // #if HAL_USE_SPI

}
