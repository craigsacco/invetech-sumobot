#ifndef __UCPP_INTERNALGPIO_HPP__
#define __UCPP_INTERNALGPIO_HPP__

#include "IGPIO.hpp"
#include <hal.h>

namespace uCpp
{

class InternalGPIO : public IGPIO
{
public:
    InternalGPIO(ioportid_t port);
    ~InternalGPIO() {}

public:
    inline uint8_t GetWidth() const override final;
    inline uint32_t GetPort() const override final;
    inline uint32_t GetLatch() const override final;
    inline void SetPort(uint32_t value) override final;
    inline void ClearPort() override final;
    inline bool GetPad(uint8_t index) const override final;
    inline void SetPad(uint8_t index, bool state = true) override final;
    inline void ClearPad(uint8_t index) override final;

private:
    ioportid_t mPort;
};

}

#endif // #ifndef __UCPP_INTERNALGPIO_HPP__
