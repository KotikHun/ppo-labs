#include <iostream>
#include <windows.h>
#include "Alphabet.h"
#include "Rule.h"
#include "MarkovAlgorithm.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    MarkovAlgorithm m;

    Alphabet a;
    a.add('a');
    a.add('b');
    m.setAlphabet(a);

    m.setTape("aab");

    m.addRule(Rule("aa", "b", false));
    m.addRule(Rule("b", "a", true));

    cout << "До: " << m.getTape() << endl;
    m.run();
    cout << "После: " << m.getTape() << endl;

    return 0;
}