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

}
