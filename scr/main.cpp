// main.cpp
// 2025-05-13 by XERONAME
// latest edit at 2025-05-25

#include <iostream> // for std::cin and std::cout
#include <vector> // for std::vector

#include "datetimes.h"
#include "console_controls.h"
#include "productDB.h"
#include "itemDB.h"

//=========== Scene (parent) ============
// 1 : main menu
// 2 : data view            (1)
// 3 : data manage          (1)
// 4 : credit               (1)
// 5 : data create          (3)
// 6 : data modify          (3) 
//=======================================

int main(void) {
    sceneNum scene = _mainMenu;

    while (scene != _out) {
        switch (scene) {
        default:
            terminateProgram(1, true, (str_err_u8_invalidScene.c_str()), (str_u8_debug.c_str()));
            break;
        case _mainMenu:
            // Scene : Main menu
            scene = mainMenu();
            break;
        case _dataView:
            // Scene : data view
            scene = dataView();
            break;
        case _dataManage:
            // Scene : data manage
            scene = dataManage();
            break;
        case _credit:
            // Scene : credit
            scene = credit();
            break;
        case _dataCreate:
            // Scene : data create
            scene = dataCreate();
            break;
        case _dataModify:
            // Scene : data modify
            scene = dataModify();
            break;
        }
    }

    terminateProgram(0, true); // terminate the program with normal exit
    return 0; // end program
}
