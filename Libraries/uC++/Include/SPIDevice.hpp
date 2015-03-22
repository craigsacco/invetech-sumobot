#ifndef __UCPP_SPIDEVICE_HPP__
#define __UCPP_SPIDEVICE_HPP__

#include "SPI.hpp"
#include "DigitalOutput.hpp"

namespace uCpp
{

#if HAL_USE_SPI

class SPIDevice
{
public:
    SPIDevice(SPI* spi, DigitalOutput* chipSelect);
    ~SPIDevice() {}

public:
    inline void Start(uint32_t frequency);
    inline void Stop();
    inline void Read(void* rxbuf, size_t len);
    inline void Write(void* txbuf, size_t len);
    inline void Exchange(void* txbuf, void* rxbuf, size_t len);

protected:
    virtual void StartInternal(SPI::Config* config) = 0;
    virtual void StopInternal() = 0;

private:
    SPI* mSPI;
    DigitalOutput* mChipSelect;
};

#endif // #if HAL_USE_SPI

}

#endif // #ifndef __UCPP_SPI_HPP__
