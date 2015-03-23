#include "SPI.hpp"
#include "InternalGPIO.hpp"
#include "SPIDevice.hpp"
#include "Assert.hpp"

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

#if HAL_USE_SPI

SPI::SPI(SPIDriver* spi) :
    mSPI(spi),
    mDevice(nullptr),
    mConfig()
{
}

void SPI::Start(SPIDevice* device)
{
    if (mSPI->state != SPI_STOP) {
        Stop();
    }

    mDevice = device;
    const SPIDeviceConfig* config = mDevice->GetConfig();
    IGPIO* port = config->ChipSelect->GetGPIO();
    uint16_t pad = config->ChipSelect->GetIndex();

#ifdef STM32F40_41xxx
    OS_ASSERT(port->IsOnMicro() == true,
              "SPI chip select pin is not on the micro");
    OS_ASSERT(config->Frequency <= (STM32_SPII2S_MAX >> 1),
              "SPI device frequency too high");
    // determine baud rate prescalar
    uint8_t baudrate = 0;
    uint32_t clock = (STM32_SPII2S_MAX >> 1);
    while (baudrate < 8) {
        if (clock < config->Frequency) {
            break;
        } else {
            clock >>= 1;
            baudrate++;
        }
        if (baudrate == 8) {
            OS_PANIC("SPI device frequency too low");
        }
    }

    mConfig.ssport = reinterpret_cast<InternalGPIO*>(port)->GetIOPort();
    mConfig.sspad = pad;
    mConfig.cr1 = (config->ClockPhase ? SPI_CR1_CPHA : 0) |
            (config->ClockPolarity ? SPI_CR1_CPOL : 0) |
            (baudrate << 3) |
            (config->SendLSBFirst ? SPI_CR1_LSBFIRST : 0) |
            (config->FrameFormat ? SPI_CR1_DFF : 0);
    mSPI->spi->CRCPR = config->CRCPolynomial;
#endif // #ifdef STM32F40_41xxx

    spiStart(mSPI, &mConfig);
}

void SPI::Stop()
{
    spiStop(mSPI);
}

void SPI::Select()
{
    spiSelect(mSPI);
}

void SPI::Unselect()
{
    spiUnselect(mSPI);
}

void SPI::Read(void* rxbuf, size_t len)
{
    spiReceive(mSPI, len, rxbuf);
}

void SPI::Write(void* txbuf, size_t len)
{
    spiSend(mSPI, len, txbuf);
}

void SPI::Exchange(void* txbuf, void* rxbuf, size_t len)
{
    spiExchange(mSPI, len, txbuf, rxbuf);
}

void SPI::Acquire()
{
    spiAcquireBus(mSPI);
}

void SPI::Release()
{
    spiReleaseBus(mSPI);
}

#endif // #if HAL_USE_SPI

}
}
