#ifndef __UCPP_SPIDEVICE_HPP__
#define __UCPP_SPIDEVICE_HPP__

#include "uCCommon.hpp"
#include "SPIDeviceConfig.hpp"
#include <hal.h>

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

#if HAL_USE_SPI

class ISPI;
class DigitalOutput;

class SPIDevice
{
public:
    SPIDevice(ISPI* spi, DigitalOutput* chipSelect);
    ~SPIDevice() {}

public:
    void Start(uint32_t frequency);
    void Stop();
    void Read(void* rxbuf, size_t len);
    void Write(void* txbuf, size_t len);
    void Exchange(void* txbuf, void* rxbuf, size_t len);
    const SPIDeviceConfig* GetConfig() const;

private:
    void Select();
    void Unselect();

protected:
    virtual void StartInternal(SPIDeviceConfig* config) = 0;
    virtual void StopInternal() = 0;

private:
    ISPI* mSPI;
    SPIDeviceConfig mDeviceConfig;

public:
    friend class SPIConversation;
};

#endif // #if HAL_USE_SPI

}
}

#endif // #ifndef __UCPP_SPI_HPP__
