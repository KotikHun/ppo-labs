#include <ConsoleMenu.h>
#include <iostream>
#include <fstream>

using namespace std;

ConsoleMenu::ConsoleMenu() : logMode(false) {
}

void ConsoleMenu::setAlgorithm(const MarkovAlgorithm& newAlgorithm) {
    algorithm = newAlgorithm;
}

MarkovAlgorithm ConsoleMenu::getAlgorithm() const {
    return algorithm;
}

void ConsoleMenu::setLogMode(bool enabled) {
    logMode = enabled;
}

bool ConsoleMenu::isLogMode() const {
    return logMode;
}

void ConsoleMenu::runInteractive() {
    int choice = 0;
    while (choice != 11) {
        showMainMenu();
        choice = readChoice();
        processChoice(choice);
    }
}

void ConsoleMenu::runWithLog() {
    cout << "Начальная лента: " << algorithm.getTape() << endl;

    while (algorithm.step()) {
        if (logMode) {
            cout << "Лента: " << algorithm.getTape() << endl;
        }
    }

    cout << "Результат: " << algorithm.getTape() << endl;
}

bool ConsoleMenu::loadFromFile(const string& path) {
    ifstream file(path);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << path << endl;
        return false;
    }
    algorithm.loadFromStream(file);
    file.close();
    return true;
}

void ConsoleMenu::showMainMenu() const {
    cout << "\n=== Нормальный алгорифм Маркова ===\n";
    cout << " 1. Загрузить алгоритм из файла\n";
    cout << " 2. Сохранить алгоритм в файл\n";
    cout << " 3. Задать алфавит\n";
    cout << " 4. Добавить правило\n";
    cout << " 5. Удалить правило\n";
    cout << " 6. Показать все правила\n";
    cout << " 7. Задать ленту\n";
    cout << " 8. Показать текущую ленту\n";
    cout << " 9. Сделать один шаг\n";
    cout << "10. Запустить до конца\n";
    cout << "11. Выход\n";
    cout << "Выбор: ";
}

int ConsoleMenu::readChoice() const {
    int choice = 0;
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(10000, '\n');
        choice = 0;
    }
    return choice;
}

void ConsoleMenu::processChoice(int choice) {
    switch (choice) {
        case 1:  handleLoad();          break;
        case 2:  handleSave();          break;
        case 3:  handleSetAlphabet();   break;
        case 4:  handleAddRule();       break;
        case 5:  handleRemoveRule();    break;
        case 6:  handleShowRules();     break;
        case 7:  handleSetTape();       break;
        case 8:  handleShowTape();      break;
        case 9:  handleStep();          break;
        case 10: handleRun();           break;
        case 11:                        break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
    }
}

void ConsoleMenu::handleLoad() {
    cout << "Введите путь к файлу: ";
    string path;
    cin >> path;

    if (loadFromFile(path)) {
        cout << "Алгоритм загружен." << endl;
    }
}

void ConsoleMenu::handleSave() {
    cout << "Введите путь к файлу: ";
    string path;
    cin >> path;

    ofstream file(path);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << path << endl;
        return;
    }
    algorithm.saveToStream(file);
    file.close();
    cout << "Алгоритм сохранён." << endl;
}

void ConsoleMenu::handleSetAlphabet() {
    cout << "Введите символы алфавита (без пробелов): ";
    string symbols;
    cin >> symbols;

    Alphabet newAlphabet;
    for (char c : symbols) {
        newAlphabet.add(c);
    }
    algorithm.setAlphabet(newAlphabet);
    cout << "Алфавит установлен." << endl;
}

void ConsoleMenu::handleAddRule() {
    cout << "Введите правило в формате 'left -> right' или 'left ->. right':" << endl;
    Rule newRule;
    cin >> newRule;
    algorithm.addRule(newRule);
    cout << "Правило добавлено." << endl;
}

void ConsoleMenu::handleRemoveRule() {
    if (algorithm.ruleCount() == 0) {
        cout << "Правил нет." << endl;
        return;
    }
    cout << "Введите номер правила (от 0 до " << algorithm.ruleCount() - 1 << "): ";
    size_t index;
    cin >> index;

    if (index >= algorithm.ruleCount()) {
        cout << "Неверный номер." << endl;
        return;
    }
    algorithm.removeRule(index);
    cout << "Правило удалено." << endl;
}

void ConsoleMenu::handleShowRules() {
    if (algorithm.ruleCount() == 0) {
        cout << "Правил нет." << endl;
        return;
    }
    cout << "Правила:" << endl;
    vector<Rule> rules = algorithm.getRules();
    for (size_t i = 0; i < rules.size(); ++i) {
        cout << "  " << i << ": " << rules[i] << endl;
    }
}

void ConsoleMenu::handleSetTape() {
    cout << "Введите строку ленты: ";
    string newTape;
    cin >> newTape;
    algorithm.setTape(newTape);
    cout << "Лента установлена." << endl;
}

void ConsoleMenu::handleShowTape() {
    cout << "Лента: " << algorithm.getTape() << endl;
}

void ConsoleMenu::handleStep() {
    cout << "До шага: " << algorithm.getTape() << endl;
    bool hasNext = algorithm.step();
    cout << "После шага: " << algorithm.getTape() << endl;

    if (!hasNext) {
        cout << "Алгоритм остановлен." << endl;
    }
}

void ConsoleMenu::handleRun() {
    runWithLog();
}