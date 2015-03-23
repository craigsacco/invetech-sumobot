#ifndef __UCPP_SPICONFIG_HPP__
#define __UCPP_SPICONFIG_HPP__

#include "uCCommon.hpp"
#include "DigitalOutput.hpp"

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

#if !defined(HAL_USE_PAL)
#error Cannot use SPIDeviceConfig without PAL enabled
#endif // #if !defined(HAL_USE_PAL)

struct SPIDeviceConfig
{
    //! digital output for chip selection
    DigitalOutput* ChipSelect = nullptr;
    //! peripheral clock frequency (in hertz)
    uint32_t Frequency = 0;
#ifdef STM32F40_41xxx
    //! set if second clock transition is capture edge (by default it is first clock transition)
    bool ClockPhase = false;
    //! set if line is high when idle (by default it is low)
    bool ClockPolarity = false;
    //! set if sending LSB first (by default it is MSB sent first)
    bool SendLSBFirst = false;
    //! set if using wide 16-bit frames (by default it is 8)
    bool FrameFormat = false;
    //! value to set for the CRCPR register
    uint16_t CRCPolynomial = 7;
#endif // #ifdef STM32F40_41xxx
};

}
}

#endif // #ifndef __UCPP_SPICONFIG_HPP__
