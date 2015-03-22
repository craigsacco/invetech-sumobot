#include "InternalGPIO.hpp"

namespace uCpp
{

#if HAL_USE_PAL

InternalGPIO::InternalGPIO(ioportid_t port) :
    mPort(port)
{
}

uint8_t InternalGPIO::GetWidth() const
{
    return 16U;
}

bool InternalGPIO::IsOnMicro() const
{
    return true;
}

uint32_t InternalGPIO::GetPort() const
{
    return palReadPort(mPort);
}

uint32_t InternalGPIO::GetLatch() const
{
    return palReadLatch(mPort);
}

void InternalGPIO::SetPort(uint32_t value)
{
    palSetPort(mPort, value);
}

void InternalGPIO::ClearPort()
{
    palClearPort(mPort, static_cast<uint32_t>((1ULL << GetWidth()) - 1));
}

bool InternalGPIO::GetPad(uint8_t index) const
{
    return (palReadPad(mPort, index) == TRUE);
}

void InternalGPIO::SetPad(uint8_t index, bool state)
{
    palWritePad(mPort, index, state ? TRUE : FALSE);
}

void InternalGPIO::ClearPad(uint8_t index)
{
    palClearPad(mPort, index);
}

ioportid_t InternalGPIO::GetIOPort()
{
    return mPort;
}

#endif // #if HAL_USE_PAL

}
