#ifndef __UCPP_ASSERT_HPP__
#define __UCPP_ASSERT_HPP__

#include "uCCommon.hpp"
#include <ch.h>

namespace NS_UCPP
{
namespace NS_UCPP_OS
{

// workaround for stringising __LINE__
// http://www.decompile.com/cpp/faq/file_and_line_error_string.htm
#define OS_ASSERT_FILE_LINE() \
    OS_ASSERT_FILE_LINE_TMP1(__FILE__, __LINE__)
#define OS_ASSERT_FILE_LINE_TMP1(file, line) \
    OS_ASSERT_FILE_LINE_TMP2(file, line)
#define OS_ASSERT_FILE_LINE_TMP2(file, line) \
    file ":" #line
#define OS_PANIC(message) \
    chDbgPanic(OS_ASSERT_FILE_LINE() " " message)
#define OS_ASSERT(condition, message) \
    if (!(condition)) { OS_PANIC(message); }

}
}

#endif // #ifndef __UCPP_ASSERT_HPP__
