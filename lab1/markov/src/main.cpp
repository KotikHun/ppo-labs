#include <iostream>
#include <windows.h>
#include "ConsoleMenu.h"

using namespace std;

int main(int argc, char* argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

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