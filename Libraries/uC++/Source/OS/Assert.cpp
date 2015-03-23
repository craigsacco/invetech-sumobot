#include "Assert.hpp"
#include <ch.h>

namespace NS_UCPP
{
namespace NS_UCPP_OS
{

void Assert::Test(bool condition, const char* source, const char* message)
{
    chDbgAssert(condition, source, message);
}

void Assert::Panic(const char* source, const char* message)
{
    chDbgAssert(false, source, message)
}

}
}
