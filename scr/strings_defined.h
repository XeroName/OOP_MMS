// strings_defined.h
// 2025-05-05 by XERONAME
// latest edit at 2025-05-28

// conditional compiling to compile only once
#ifndef COMPILED_STRDEFINED // compiled the code from #ifndef to #endif, if the macro 'COMPILED_STRDEFINED' was not defined before
#define COMPILED_STRDEFINED // define macro for conditional compile

#include <string> // for std::string data type



// wrap the target string with desired character
std::string makeWrap(std::string str_target, char character_wrap) {
    switch (character_wrap) {
        default : return (character_wrap +str_target +character_wrap);
        case 40 : case 41 : return ('(' +str_target +')');
        case 123 : case 125 : return ('{' +str_target +'}');
        case 91 : case 93 : return ('[' +str_target +']');
    }
}



// pre-declared noun strings, encoded to UTF-8
const std::string str_u8_none = u8"";
const std::string str_u8_tab = u8"  ";
const std::string str_u8_unknown = u8"unknown"; // unknown
const std::string str_u8_na = u8"N/A"; // not available
const std::string str_u8_debug = u8"DEBUG"; // DEBUG

// pre-declared special characters, encoded to UTF-8
const std::string str_u8_blank = u8"⠀";
const std::string str_u8_triRight = u8"▶";

// pre-declared sentence strings, encoded to UTF-8
const std::string str_u8_helloworld = u8"hello, world!";

// error messages, encoded to UTF-8
const std::string str_err_u8_containerExceededMaxSize = u8"Container exceeded its maximum size allowed";
const std::string str_err_u8_dataAlreadyExist = u8"Data with non-duplicatable property already exist";
const std::string str_err_u8_invalidScene = u8"Invalid scene specified in main loop";

#endif // end of the conditional compile
