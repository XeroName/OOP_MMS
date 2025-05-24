// strings_defined.h
//2025-05-05 by XERONAME

// conditional compiling to compile only once
#ifndef COMPILED_STRDEFINED // compiled the code from #ifndef to #endif, if the macro 'COMPILED_STRDEFINED' was not defined before
#define COMPILED_STRDEFINED // define macro for conditional compile

#include <string> // for std::string data type



// pre-declared noun strings, encoded to UTF-8
const std::string str_u8_unknown = u8"unknown"; // unknown
const std::string str_u8_na = u8"N/A"; // not available
const std::string str_u8_debug = u8"DEBUG"; // DEBUG

// pre-declared sentence strings, encoded to UTF-8
const std::string str_u8_none = u8"";
const std::string str_u8_helloworld = u8"hello, world!";
const std::string str_err_u8_containerExceededMaxSize = u8"Container exceeded its maximum size allowed";
const std::string str_err_u8_dataAlreadyExist = u8"Data with non-duplicatable property already exist";

#endif // end of the conditional compile
