#include "DigitalOutput.hpp"

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

DigitalOutput::DigitalOutput(IGPIO* gpio, uint8_t index) :
    mGPIO(gpio),
    mIndex(index)
{
}

bool DigitalOutput::Get() const
{
    return ((mGPIO->GetLatch() & (1UL << mIndex)) != 0);
}

void DigitalOutput::Set(bool state)
{
    mGPIO->SetPad(mIndex, state);
}

void DigitalOutput::Clear()
{
    mGPIO->ClearPad(mIndex);
}

IGPIO* DigitalOutput::GetGPIO() const
{
    return mGPIO;
}

uint8_t DigitalOutput::GetIndex() const
{
    return mIndex;
}

}
}
