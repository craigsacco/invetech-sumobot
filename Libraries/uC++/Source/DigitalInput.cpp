#include "DigitalInput.hpp"

namespace uCpp
{

DigitalInput::DigitalInput(IGPIO* gpio, uint8_t index) :
    mGPIO(gpio),
    mIndex(index)
{
}

bool DigitalInput::Get() const
{
    return mGPIO->GetPad(mIndex);
}

IGPIO* DigitalInput::GetGPIO() const
{
    return mGPIO;
}

uint8_t DigitalInput::GetIndex() const
{
    return mIndex;
}

}
