#include "ConsoleMenu.h"
#ifdef _WIN32
    #include <windows.h>
#endif

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    ConsoleMenu menu;
    menu.runInteractive();

    return 0;
}