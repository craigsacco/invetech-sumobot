#include <ff.h>

WCHAR ff_convert(WCHAR char_code, UINT to_unicode)
{
    // only convert ANSI characters (0x20 - 0x7E) ...
    // or else convert non-conforming characters to a hash
    if (to_unicode == 1) {
        return char_code;
    } else {
        if (char_code >= 0x20 && char_code <= 0x7E) {
            return char_code;
        } else {
            return '#';
        }
    }
}

WCHAR ff_wtoupper(WCHAR char_code)
{
    // only convert ANSI lower-case characters ...
    // or else return as-is
    if (char_code >= 'a' && char_code <= 'z') {
        return char_code + ('A' - 'a');
    } else {
        return char_code;
    }
}
