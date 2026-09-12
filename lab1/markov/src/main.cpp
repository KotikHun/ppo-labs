#include <iostream>
#include <Alphabet.h>
#include <windows.h>

using namespace std;

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Alphabet a;
    a.add('x');
    a.add('y');
    a.add('z');

    cout << "Алфавит: " << a << endl;
    cout << "Размер: " << a.size() << endl;
    cout << "Содержит 'x': " << (a.contains('x') ? "да" : "нет") << endl;
    cout << "Содержит 'w': " << (a.contains('w') ? "да" : "нет") << endl;

    return 0;

}