#ifndef __UCPP_SPICONVERSATION_HPP__
#define __UCPP_SPICONVERSATION_HPP__

#include "uCCommon.hpp"
#include <hal.h>

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

#if HAL_USE_SPI

class SPIDevice;

class SPIConversation
{
public:
    SPIConversation(SPIDevice* device);
    ~SPIConversation();

private:
    SPIDevice* mDevice;
};

#endif // #if HAL_USE_SPI

}
}

#endif // #ifndef __UCPP_SPICONVERSATION_HPP__
