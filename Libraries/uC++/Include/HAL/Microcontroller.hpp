#ifndef __UCPP_MICROCONTROLLER_HPP__
#define __UCPP_MICROCONTROLLER_HPP__

#include "uCCommon.hpp"
#include "InternalGPIO.hpp"
#include "SPI.hpp"
#include <hal.h>

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

class Microcontroller
{
public:
    Microcontroller() {}
    ~Microcontroller() {}

// GPIO definitions
#define MCU_DEFINE_GPIO(name, driver) \
    public: \
        inline InternalGPIO* Get##name() { return &m##name; } \
    private: \
        InternalGPIO m##name { driver };
#ifdef STM32F40_41xxx
#if STM32_HAS_GPIOA
MCU_DEFINE_GPIO(GPIOA, GPIOA)
#endif // #if STM32_HAS_GPIOA
#if STM32_HAS_GPIOB
MCU_DEFINE_GPIO(GPIOB, GPIOB)
#endif // #if STM32_HAS_GPIOB
#if STM32_HAS_GPIOC
MCU_DEFINE_GPIO(GPIOC, GPIOC)
#endif // #if STM32_HAS_GPIOC
#if STM32_HAS_GPIOD
MCU_DEFINE_GPIO(GPIOD, GPIOD)
#endif // #if STM32_HAS_GPIOA
#if STM32_HAS_GPIOE
MCU_DEFINE_GPIO(GPIOE, GPIOE)
#endif // #if STM32_HAS_GPIOE
#if STM32_HAS_GPIOF
MCU_DEFINE_GPIO(GPIOF, GPIOF)
#endif // #if STM32_HAS_GPIOF
#if STM32_HAS_GPIOG
MCU_DEFINE_GPIO(GPIOG, GPIOG)
#endif // #if STM32_HAS_GPIOG
#if STM32_HAS_GPIOH
MCU_DEFINE_GPIO(GPIOH, GPIOH)
#endif // #if STM32_HAS_GPIOH
#if STM32_HAS_GPIOI
MCU_DEFINE_GPIO(GPIOI, GPIOI)
#endif // #if STM32_HAS_GPIOI
#endif // #ifdef STM32F40_41xxx

// SPI definitions
#define MCU_DEFINE_SPI(name, driver) \
    public: \
        inline SPI* Get##name() { return &m##name; } \
    private: \
        SPI m##name { &driver };
#ifdef STM32F40_41xxx
#if STM32_SPI_USE_SPI1
MCU_DEFINE_SPI(SPI1, SPID1)
#endif // #if STM32_SPI_USE_SPI1
#if STM32_SPI_USE_SPI2
MCU_DEFINE_SPI(SPI2, SPID2)
#endif // #if STM32_SPI_USE_SPI2
#if STM32_SPI_USE_SPI3
MCU_DEFINE_SPI(SPI3, SPID3)
#endif // #if STM32_SPI_USE_SPI3
#endif // #ifdef STM32F40_41xxx
};

}
}

#endif // #ifndef __UCPP_MICROCONTROLLER_HPP__
