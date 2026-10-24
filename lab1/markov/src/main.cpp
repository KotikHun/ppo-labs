#include <iostream>
#include <string>   // Добавлено, так как используется std::string

// Подключаем windows.h ТОЛЬКО если собираем на Windows
#ifdef _WIN32
    #include <windows.h>
#endif

#include "ConsoleMenu.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Настраиваем кодировку ТОЛЬКО на Windows
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    ConsoleMenu menu;

    string filePath;
    bool logMode = false;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-log") {
            logMode = true;
        } else {
            filePath = arg;
        }
    }

    if (!filePath.empty()) {
        menu.loadFromFile(filePath);
        menu.setLogMode(logMode);
        menu.runWithLog();
    } else {
        menu.runInteractive();
    }

    return 0;
}