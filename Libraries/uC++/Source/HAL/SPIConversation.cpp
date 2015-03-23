#include "SPIConversation.hpp"
#include "SPIDevice.hpp"

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

#if HAL_USE_SPI

SPIConversation::SPIConversation(SPIDevice* device) :
    mDevice(device)
{
    mDevice->Select();
}

SPIConversation::~SPIConversation()
{
    mDevice->Unselect();
}

#endif // #if HAL_USE_SPI

}
}
