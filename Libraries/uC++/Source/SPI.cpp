#include "SPI.hpp"
#include "InternalGPIO.hpp"
#include <chdebug.h>

namespace uCpp
{

#if HAL_USE_SPI

#if !defined(HAL_USE_PAL)
#error Cannot use SPI without PAL enabled
#endif // #if !defined(HAL_USE_PAL)

SPI::SPI(SPIDriver* spi) :
    mSPI(spi),
    mConfig()
{
}

void SPI::Start(SPI::Config config)
{
    if (mSPI->state != SPI_STOP) {
        Stop();
    }

    IGPIO* chipSelectPort = config.ChipSelect->GetGPIO();
    uint16_t chipSelectPad = config.ChipSelect->GetIndex();

#ifdef STM32F40_41xxx
    chDbgPanic(chipSelectPort->IsOnMicro() == true);
    chDbgPanic(config.BaudRateSelection >= 0 &&
               config.BaudRateSelection < 8);
    mConfig.ssport = reinterpret_cast<InternalGPIO*>(chipSelectPort)->GetIOPort();
    mConfig.sspad = chipSelectPad;
    mConfig.cr1 = (config.ClockPhase ? SPI_CR1_CPHA : 0) |
            (config.ClockPolarity ? SPI_CR1_CPOL : 0) |
            (static_cast<uint16_t>(config.BaudRate) << 3) |
            (config.SendLSBFirst ? SPI_CR1_LSBFIRST : 0) |
            (config.FrameFormat ? SPI_CR1_DFF : 0);
    mSPI->spi->CRCPR = config.CRCPolynomial;
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

SPI::Config::BaudRateSelection_t SPI::GetBaudRateSelection(uint32_t frequency)
{
#ifdef STM32F40_41xxx
    chDbgAssert(frequency > (STM32_SPII2S_MAX / 2),
                "GetBaudRateSelection, #1",
                "SPI frequency setting too high");
    uint32_t clock = STM32_SPII2S_MAX / 2;
    for (int i = 0; i < 8; i++) {
        if (clock <= frequency) {
            return static_cast<SPI::Config::BaudRateSelection_t>(i);
        }
        clock /= 2;
    }
    chDbgAssert(false,
                "GetBaudRateSelection, #2",
                "SPI frequency setting too low");
#else
    return frequency;
#endif
}

#endif // #if HAL_USE_SPI

}
