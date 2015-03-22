#ifndef __UCPP_MICROCONTROLLER_HPP__
#define __UCPP_MICROCONTROLLER_HPP__

#include "InternalGPIO.hpp"
#include <hal.h>

namespace uCpp
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
#ifdef STM32_HAS_GPIOA
MCU_DEFINE_GPIO(GPIOA, GPIOA)
#endif // #ifdef STM32_HAS_GPIOA
#ifdef STM32_HAS_GPIOB
MCU_DEFINE_GPIO(GPIOB, GPIOB)
#endif // #ifdef STM32_HAS_GPIOB
#ifdef STM32_HAS_GPIOC
MCU_DEFINE_GPIO(GPIOC, GPIOC)
#endif // #ifdef STM32_HAS_GPIOC
#ifdef STM32_HAS_GPIOD
MCU_DEFINE_GPIO(GPIOD, GPIOD)
#endif // #ifdef STM32_HAS_GPIOA
#ifdef STM32_HAS_GPIOE
MCU_DEFINE_GPIO(GPIOE, GPIOE)
#endif // #ifdef STM32_HAS_GPIOE
#ifdef STM32_HAS_GPIOF
MCU_DEFINE_GPIO(GPIOF, GPIOF)
#endif // #ifdef STM32_HAS_GPIOF
#ifdef STM32_HAS_GPIOG
MCU_DEFINE_GPIO(GPIOG, GPIOG)
#endif // #ifdef STM32_HAS_GPIOG
#ifdef STM32_HAS_GPIOH
MCU_DEFINE_GPIO(GPIOH, GPIOH)
#endif // #ifdef STM32_HAS_GPIOH
#ifdef STM32_HAS_GPIOI
MCU_DEFINE_GPIO(GPIOI, GPIOI)
#endif // #ifdef STM32_HAS_GPIOI
#endif // #ifdef STM32F40_41xxx
};

}

#endif // #ifndef __UCPP_MICROCONTROLLER_HPP__
