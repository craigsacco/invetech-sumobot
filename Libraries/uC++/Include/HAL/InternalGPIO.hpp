#ifndef __UCPP_INTERNALGPIO_HPP__
#define __UCPP_INTERNALGPIO_HPP__

#include "uCCommon.hpp"
#include "IGPIO.hpp"
#include <hal.h>

namespace NS_UCPP
{
namespace NS_UCPP_HAL
{

#if HAL_USE_PAL

class InternalGPIO : public IGPIO
{
public:
    InternalGPIO(ioportid_t port);
    ~InternalGPIO() {}

public:
    uint8_t GetWidth() const override final;
    bool IsOnMicro() const override final;
    uint32_t GetPort() const override final;
    uint32_t GetLatch() const override final;
    void SetPort(uint32_t value) override final;
    void ClearPort() override final;
    bool GetPad(uint8_t index) const override final;
    void SetPad(uint8_t index, bool state = true) override final;
    void ClearPad(uint8_t index) override final;
    ioportid_t GetIOPort();

private:
    ioportid_t mPort;
};

#endif // #if HAL_USE_PAL

}
}

#endif // #ifndef __UCPP_INTERNALGPIO_HPP__
