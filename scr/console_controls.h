// console_controls.h
// 2025-05-13 by XERONAME
// latest edit at 2025-05-25

// conditional compiling to compile only once
#ifndef COMPILED_CONSOLECTRLS // compiled the code from #ifndef to #endif, if the macro 'COMPILED_CONSOLECTRLS' was not defined before
#define COMPILED_CONSOLECTRLS // define macro for conditional compile

#include <windows.h>
#include <iostream> // for std::cout and std::cin
#include <cstring> // for c-styled string related functions
#include <string> // for std::string
#include <vector> // for std::vector

#include "strings_defined.h"



typedef struct ConsoleHandler_CommandNode {
    /*
    command types :
    1 = print text to console in 'content'
    2 = print line-ending character(\n) to console
    3 = print space to console
    4 = print tab to console
    5 = clear the console screen
    6 = get current location of cursor in console
    7 = move cursor in console to desired position
    8 = delete characters by length of 'numeric' from current location of cursor
    */
    int command;
    char* content;
    int numeric;

    ConsoleHandler_CommandNode(int _command) : command(_command) {}
} CHNode;



class ConsoleHandler {
    private :
        std::vector<CHNode> command_nodes;

    public :
        // clear nodes in output array
        void clearNodes() { command_nodes.clear(); }
    
        // add string to next-of-end of output array
        std::vector<CHNode>::iterator addNode(CHNode _node) {
            std::vector<CHNode>::iterator target_iter = (command_nodes.end());
            command_nodes.insert(target_iter, _node);
            return target_iter;
        }

        // perform whole node in 'command_nodes' array
        void performNodes() {
            for (int i=0; i<(command_nodes.size()); i++) {
                CHNode node_current = command_nodes[i];
                switch (node_current.command) {
                    default : break;

                    case 1 : std::cout << (node_current.content); break;

                    case 2 : std::cout << "\n"; break;

                    case 3 : std::cout << " "; break;

                    case 4 : std::cout << str_u8_tab; break;

                    case 5 : consoleClear(); break;
                }
            }
        }
};



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

// terminate the program with desired message
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
