#pragma once
// console_controls.h
// 2025-05-13 by XERONAME
// latest edit at 2025-05-25

// conditional compiling to compile only once
#ifndef COMPILED_CONSOLECTRLS // compiled the code from #ifndef to #endif, if the macro 'COMPILED_CONSOLECTRLS' was not defined before
#define COMPILED_CONSOLECTRLS // define macro for conditional compile

#define KEY_HOME 71
#define KEY_UP 72
#define KEY_DOWN 80

#include <windows.h>
#include <iostream> // for std::cout and std::cin
#include <cstring> // for c-styled string related functions
#include <string> // for std::string 
#include <conio.h> //for _getch() (input key)
#include <chrono> // for std::chrono (key delay)
#include <vector>

#include "strings_defined.h"

typedef enum sceneNum {
    _out,
    _mainMenu,
    _dataView,
    _dataManage,
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

void printConsole(const std::string& path,const std::vector<std::string>& cntr, int size, int idx) {
    std::cout << "= PMS V1.0 =" << std::endl;
    std::cout << "-" << path << "/...\n" << std::endl;
    int i = 0;
    for (; i < idx; i++) {
        std::cout << "[ ] " << cntr[i] << std::endl;
    }
    std::cout << "[▶] " << cntr[i++] << std::endl;
    for (; i < size; i++) {
        std::cout << "[ ] " << cntr[i] << std::endl;
    }
}

sceneNum showMenu(const std::string& path, const std::vector<std::string>& options, const std::vector<sceneNum>& transitions) {
    int idx = 0;
    const int size = options.size();
    auto delay = std::chrono::steady_clock::now();
    std::chrono::milliseconds ms(100);

    while (1) {
        consoleClear();
        printConsole(path, options, size, idx);

        int input = _getch();
        
        if (input == 224 && std::chrono::steady_clock::now() - delay >= ms) {
            input = _getch();
            switch (input) {
            case KEY_HOME:
                return _mainMenu;
            case KEY_UP:
                idx--;
                break;
            case KEY_DOWN:
                idx++;
                break;
            }
            idx = (idx + size) % size;
            delay = std::chrono::steady_clock::now();
        }
        if (input == 13) {
            if (idx >= 0 && idx < transitions.size()) {
                return transitions[idx];
            }
        }
    }
}

// Scene 1
sceneNum mainMenu() {
    std::vector<std::string> options = {"데이터 열람","데이터 관리" ,"크레딧","프로그램 종료"};
    std::vector<sceneNum> sceneOptions = { _dataView, _dataManage, _credit, _out };
    return showMenu("메인 메뉴", options, sceneOptions);
}

// Scene 2
sceneNum dataView() {
    std::vector<std::string> options =  { "돌아가기","카테고리 열람" ,"Product 열람","Item 열람", "Package 열람", "SPackage 열람" };
    std::vector<sceneNum> sceneOptions = { _mainMenu, _dataView, _dataView, _dataView,_dataView };
    return showMenu("메인 메뉴", options, sceneOptions);
}


// Scene 3
sceneNum dataManage() {
    std::vector<std::string> options = { "돌아가기","신규 데이터 생성" ,"기존 데이터 수정" };
    std::vector<sceneNum> sceneOptions = { _mainMenu, _dataCreate, _dataModify };
    return showMenu("메인 메뉴", options, sceneOptions);
}

// Scene 4
sceneNum credit() {
    consoleClear();
    std::cout << "PMS(Product Management System)\nVersion: 1.0.0 at 2025.6.1\n\n제작자 :\n- 전형진\n- 이현준\n- 노승준\n- 응우옌 만 히에우\n= 객체지향프로그래밍 조별 활동 과제 = " << std::endl;
    
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
    std::vector<std::string> options = { "돌아가기","카테고리 생성" ,"Product 생성","Item 생성", "Package 생성", "SPackage 생성" };
    std::vector<sceneNum> sceneOptions = { _dataManage, _dataCreate, _dataCreate, _dataCreate, _dataCreate, _dataCreate };
    return showMenu("메인 메뉴", options, sceneOptions);
}

// Scene 6
sceneNum dataModify() {
    std::vector<std::string> options = { "돌아가기","카테고리 수정","Item 수정", "Package 수정", "SPackage 수정" };
    std::vector<sceneNum> sceneOptions = { _dataManage, _dataModify, _dataModify, _dataModify, _dataModify };
    return showMenu("메인 메뉴", options, sceneOptions);
}

#endif // end of the conditional compile
