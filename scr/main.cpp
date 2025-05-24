// main.cpp
// 2025-05-13 by XERONAME
// latest edit at 2025-05-25

#include <iostream> // for std::cin and std::cout
#include <vector> // for std::vector

#include "datetimes.h"
#include "console_controls.h"
#include "productDB.h"
#include "itemDB.h"



int scene = 1; // scene number to switch screen scene
ConsoleHandler cHandler; // create new instance of customized console handler



int main(void) {
    while (scene > 0) {
        switch (scene) {
            default :
                terminateProgram( 1, true, (str_err_u8_invalidScene.c_str()), (str_u8_debug.c_str()) );
                break;

            case 1 :
                // Scene : Main menu
        }
    }

    terminateProgram(0, true); // terminate the program with normal exit
    return 0; // end program
}
