// console_controls.h
// 2025-05-13

// conditional compiling to compile only once
#ifndef COMPILED_CONSOLECTRLS // compiled the code from #ifndef to #endif, if the macro 'COMPILED_CONSOLECTRLS' was not defined before
#define COMPILED_CONSOLECTRLS // define macro for conditional compile

#include <windows.h>
#include <iostream> // for std::cout and std::cin
#include <cstring> // for c-styled string related functions

#include "strings_defined.h"



// clear the console screen
// referenced from : https://stackoverflow.com/a/6487534
void consoleClear() {
    COORD _topLeft = {0,0};
    HANDLE _console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO _screen;
    DWORD _written;

    GetConsoleScreenBufferInfo(_console, &_screen);
    FillConsoleOutputCharacterA(_console, ' ', ((_screen.dwSize.X) *(_screen.dwSize.Y)), _topLeft, &_written);
    FillConsoleOutputAttribute(_console,
        (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE),
        ((_screen.dwSize.X) *(_screen.dwSize.Y)), _topLeft, &_written);

    SetConsoleCursorPosition(_console, _topLeft); // reset the position of cursor in console screen
}

void terminateProgram(int code_exit, bool console_clear, const char* msg=(str_u8_none.c_str()), const char* msg_prefix=(str_u8_none.c_str()))
{
    if (console_clear) { consoleClear(); }

    // print terminate message if exist
    if (strcmp(msg, (str_u8_none.c_str())) != 0) {
        if (strcmp(msg_prefix, (str_u8_none.c_str())) == 0) {
            std::cout << msg << std::endl;
        }
        else { std::cout << "[" << msg_prefix << "] " << msg << std::endl; }
    }

    exit(code_exit); // terminate program (0=normal exit, 1=exit with error)
}

#endif // end of the conditional compile
