#include <iostream>
#include "ConsoleMenu.h"

#ifdef _WIN32
    #include <windows.h>
#endif

using namespace std;

int main() {
    // Вот здесь нужен #ifdef, чтобы Linux не пытался вызывать виндовые функции
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    ConsoleMenu menu;
    menu.runInteractive();

    return 0;
}