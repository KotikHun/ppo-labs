#include <iostream>
#include <windows.h>
#include "Alphabet.h"
#include "Rule.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Rule r("aa", "b", false);
    cout << "Правило: " << r << endl;

    string tape = "aab";
    cout << "До: " << tape << endl;

    if (r.isApplicable(tape)) {
        r.apply(tape);
    }

    cout << "После: " << tape << endl;

    return 0;
}