#ifndef __UCPP_SPI_HPP__
#define __UCPP_SPI_HPP__

#include "uCCommon.hpp"
#include "ISPI.hpp"
#include <hal.h>

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

#if HAL_USE_SPI

class SPI : public ISPI
{
public:
    SPI(SPIDriver* spi);
    ~SPI() {}

public:
    void Start(SPIDevice* device) override final;
    void Stop() override final;
    void Select() override final;
    void Unselect() override final;
    void Read(void* rxbuf, size_t len) override final;
    void Write(void* txbuf, size_t len) override final;
    void Exchange(void* txbuf, void* rxbuf, size_t len) override final;
    void Acquire() override final;
    void Release() override final;

private:
    SPIDriver* mSPI;
    SPIDevice* mDevice;
    SPIConfig mConfig;
};

#endif // #if HAL_USE_SPI

}
}

#endif // #ifndef __UCPP_SPI_HPP__
