#pragma once
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
#include <conio.h> //for _getch() (input key)
#include <chrono> // for std::chrono (key delay)

#include "strings_defined.h"

typedef enum sceneNum {
    _out,
    _mainMenu,
    _dataView,
    _dataMange,
    _credit,
    _dataCreate,
    _dataModify
}sceneNum;

// clear the console screen
// referenced from : https://stackoverflow.com/a/6487534
void consoleClear() {
    COORD _topLeft = { 0,0 };
    HANDLE _console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO _screen;
    DWORD _written;

    GetConsoleScreenBufferInfo(_console, &_screen);
    FillConsoleOutputCharacterA(_console, ' ', ((_screen.dwSize.X) * (_screen.dwSize.Y)), _topLeft, &_written);
    FillConsoleOutputAttribute(_console,
        (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE),
        ((_screen.dwSize.X) * (_screen.dwSize.Y)), _topLeft, &_written);

    SetConsoleCursorPosition(_console, _topLeft); // reset the position of cursor in console screen
}

// terminate the program with desired message
void terminateProgram(int code_exit, bool console_clear, const char* msg = (str_u8_none.c_str()), const char* msg_prefix = (str_u8_none.c_str()))
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

void printConsole(std::string cntr[], int size, int idx) {
    int i = 0;
    for (; i < idx; i++) {
        std::cout << "[ ] " << cntr[i] << std::endl;
    }
    std::cout << "[��] " << cntr[i++] << std::endl;
    for (; i < size; i++) {
        std::cout << "[ ] " << cntr[i] << std::endl;

    }
}

// Scene 1
sceneNum mainMenu() {
    int idx = 0, size = 4;
    std::string cntr[4] = { "������ ����","������ ����" ,"ũ����","���α׷� ����" };
    auto delay = std::chrono::steady_clock::now();
    std::chrono::milliseconds ms(100);

    consoleClear();
    std::cout << "= PMS V1.0 =\n-���� �޴�/...\n" << std::endl;
    printConsole(cntr, size, idx);

    while (1) {
        int input;
        input = _getch();

        if (input == 224 && std::chrono::steady_clock::now() - delay >= ms){
            input = _getch();
            switch (input) {
            case 72:
                idx--;
                break;
            case 80:
                idx++;
                break;
            }
            idx = (idx + size) % size;
            consoleClear();
            std::cout << "= PMS V1.0 =\n-���� �޴�/...\n" << std::endl;
            printConsole(cntr, size, idx);
            delay = std::chrono::steady_clock::now();
        }
        if (input == 13) {
            switch (idx) {
            case 0:
                return _dataView;
            case 1:
                return _dataMange;
            case 2:
                return _credit;
            case 3:
                return _out;
            }
        }
    }
}

// Scene 2
sceneNum dataView() {
    int idx = 0, size = 6;
    std::string cntr[6] = { "���ư���","ī�װ� ����" ,"Product ����","Item ����", "Package ����", "SPackage ����"};
    auto delay = std::chrono::steady_clock::now();
    std::chrono::milliseconds ms(100);

    consoleClear();
    std::cout << "= PMS V1.0 =\n-���� �޴�/������ ����/...\n" << std::endl;
    printConsole(cntr, size, idx);

    while (1) {
        int input;
        input = _getch();

        if (input == 224 && std::chrono::steady_clock::now() - delay >= ms) {
            input = _getch();
            switch (input) {
            case 72:
                idx--;
                break;
            case 80:
                idx++;
                break;
            }
            idx = (idx + size) % size;
            consoleClear();
            std::cout << "= PMS V1.0 =\n-���� �޴�/������ ����/...\n" << std::endl;
            printConsole(cntr, size, idx);
            delay = std::chrono::steady_clock::now();
        }
        if (input == 13) {
            switch (idx) {
            case 0:
                return _mainMenu;
            case 1:
                return _dataView;
            case 2:
                return _dataView;
            case 3:
                return _dataView;
            case 4:
                return _dataView;
            case 5:
                return _dataView;
            }
        }
    }
}


// Scene 3
sceneNum dataManage() {
    int idx = 0, size = 3;
    std::string cntr[3] = { "���ư���","�ű� ������ ����" ,"���� ������ ����"};
    auto delay = std::chrono::steady_clock::now();
    std::chrono::milliseconds ms(100);

    consoleClear();
    std::cout << "= PMS V1.0 =\n-���� �޴�/������ ����/...\n" << std::endl;
    printConsole(cntr, size, idx);

    while (1) {
        int input;
        input = _getch();

        if (input == 224 && std::chrono::steady_clock::now() - delay >= ms) {
            input = _getch();
            switch (input) {
            case 72:
                idx--;
                break;
            case 80:
                idx++;
                break;
            }
            idx = (idx + size) % size;
            consoleClear();
            std::cout << "= PMS V1.0 =\n-���� �޴�/������ ����/...\n" << std::endl;
            printConsole(cntr, size, idx);
            delay = std::chrono::steady_clock::now();
        }
        if (input == 13) {
            switch (idx) {
            case 0:
                return _mainMenu;
            case 1:
                return _dataCreate;
            case 2:
                return _dataModify;
            }
        }
    }
}

// Scene 4
sceneNum credit() {
    consoleClear();
    std::cout << "PMS(Product Management System)\nVersion: 1.0.0 at 2025.6.1\n\n������ :\n- ������\n- ������\n- �����\n- ���쿺 �� ������\n= ��ü�������α׷��� ���� Ȱ�� ���� = " << std::endl;
    
    while (1) {
        int input;
        input = _getch();

        if (input == 13) {
            return _mainMenu;
        }
    }
}


// Scene 5
sceneNum dataCreate() {
    int idx = 0, size = 6;
    std::string cntr[6] = { "���ư���","ī�װ� ����" ,"Product ����","Item ����", "Package ����", "SPackage ����" };
    auto delay = std::chrono::steady_clock::now();
    std::chrono::milliseconds ms(100);

    consoleClear();
    std::cout << "= PMS V1.0 =\n-���� �޴�/������ ����/�ű� ������ ����/...\n" << std::endl;
    printConsole(cntr, size, idx);

    while (1) {
        int input;
        input = _getch();

        if (input == 224 && std::chrono::steady_clock::now() - delay >= ms) {
            input = _getch();
            switch (input) {
            case 72:
                idx--;
                break;
            case 80:
                idx++;
                break;
            }
            idx = (idx + size) % size;
            consoleClear();
            std::cout << "= PMS V1.0 =\n-���� �޴�/������ ����/�ű� ������ ����/...\n" << std::endl;
            printConsole(cntr, size, idx);
            delay = std::chrono::steady_clock::now();
        }
        if (input == 13) {
            switch (idx) {
            case 0:
                return _dataMange;
            case 1:
                return _dataCreate;
            case 2:
                return _dataCreate;
            case 3:
                return _dataCreate;
            case 4:
                return _dataCreate;
            case 5:
                return _dataCreate;
            }
        }
    }
}

// Scene 6
sceneNum dataModify() {
    int idx = 0, size = 5;
    std::string cntr[5] = { "���ư���","ī�װ� ����","Item ����", "Package ����", "SPackage ����" };
    auto delay = std::chrono::steady_clock::now();
    std::chrono::milliseconds ms(100);

    consoleClear();
    std::cout << "= PMS V1.0 =\n-���� �޴�/������ ����/���� ������ ����/...\n" << std::endl;
    printConsole(cntr, size, idx);

    while (1) {
        int input;
        input = _getch();

        if (input == 224 && std::chrono::steady_clock::now() - delay >= ms) {
            input = _getch();
            switch (input) {
            case 72:
                idx--;
                break;
            case 80:
                idx++;
                break;
            }
            idx = (idx + size) % size;
            consoleClear();
            std::cout << "= PMS V1.0 =\n-���� �޴�/������ ����/���� ������ ����/...\n" << std::endl;
            printConsole(cntr, size, idx);
            delay = std::chrono::steady_clock::now();
        }
        if (input == 13) {
            switch (idx) {
            case 0:
                return _dataMange;
            case 1:
                return _dataModify;
            case 2:
                return _dataModify;
            case 3:
                return _dataModify;
            case 4:
                return _dataModify;
            case 5:
                return _dataModify;
            }
        }
    }
}

#endif // end of the conditional compile
