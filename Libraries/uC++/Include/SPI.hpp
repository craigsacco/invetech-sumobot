#ifndef __UCPP_SPI_HPP__
#define __UCPP_SPI_HPP__

#include "IGPIO.hpp"
#include "DigitalOutput.hpp"
#include <hal.h>

namespace uCpp
{

#if HAL_USE_SPI

class SPI
{
public:
    SPI(SPIDriver* spi);
    ~SPI() {}

public:
#ifdef STM32F40_41xxx
    struct Config
    {
        //! baud rate selection options
        enum BaudRateSelection_t
        {
            PeripheralClockDiv2, // 21MHz
            PeripheralClockDiv4, // 10.5MHz
            PeripheralClockDiv8, // 5.25MHz
            PeripheralClockDiv16, // 2.625MHz
            PeripheralClockDiv32, // 1.3125MHz
            PeripheralClockDiv64, // 656.25kHz
            PeripheralClockDiv128, // 328.125kHz
            PeripheralClockDiv256, // 164062.5kHz
        };
        //! digital output for chip selection
        DigitalOutput* ChipSelect = nullptr;
        //! set if second clock transition is capture edge (by default it is first clock transition)
        bool ClockPhase = false;
        //! set if line is high when idle (by default it is low)
        bool ClockPolarity = false;
        //! baud rate selection
        BaudRateSelection_t BaudRateSelection = PeripheralClockDiv256;
        //! set if sending LSB first (by default it is MSB sent first)
        bool SendLSBFirst = false;
        //! set if using wide 16-bit frames (by default it is 8)
        bool FrameFormat = false;
        //! value to set for the CRCPR register
        uint16_t CRCPolynomial = 7;
    };
#endif // #ifdef STM32F40_41xxx

public:
    inline void Start(Config config);
    inline void Stop();
    inline void Select();
    inline void Unselect();
    inline void Read(void* rxbuf, size_t len);
    inline void Write(void* txbuf, size_t len);
    inline void Exchange(void* txbuf, void* rxbuf, size_t len);
    inline void Acquire();
    inline void Release();

private:
    SPIDriver* mSPI;
    SPIConfig mConfig;
};

#endif // #if HAL_USE_SPI

}

#endif // #ifndef __UCPP_SPI_HPP__
