#include "ConsoleMenu.h"
#include <iostream>
#include <fstream>

using namespace std;

ConsoleMenu::ConsoleMenu() {
}

void ConsoleMenu::setCube(const Cube& newCube) {
    cube = newCube;
}

Cube ConsoleMenu::getCube() const {
    return cube;
}

void ConsoleMenu::runInteractive() {
    int choice = 0;
    while (choice != 8) {
        showMainMenu();
        choice = readChoice();
        processChoice(choice);
    }
}

void ConsoleMenu::showMainMenu() const {
    cout << "\n=== Кубик Рубика ===\n";
    cout << " 1. Новая игра (собранный кубик)\n";
    cout << " 2. Случайное размещение\n";
    cout << " 3. Загрузить из файла\n";
    cout << " 4. Сохранить в файл\n";
    cout << " 5. Повернуть грань\n";
    cout << " 6. Показать кубик\n";
    cout << " 7. Проверить: собран?\n";
    cout << " 8. Выход\n";
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
    case 1: handleNewGame();    break;
    case 2: handleRandomize();  break;
    case 3: handleLoad();       break;
    case 4: handleSave();       break;
    case 5: handleRotateFace(); break;
    case 6: handleShowCube();   break;
    case 7: handleIsSolved();   break;
    case 8:                     break;
    default:
        cout << "Неверный выбор." << endl;
    }
}

void ConsoleMenu::handleNewGame() {
    cube = Cube();
    cout << "Создан собранный кубик." << endl;
}

void ConsoleMenu::handleRandomize() {
    cube.randomize();
    cout << "Кубик перемешан." << endl;
}

void ConsoleMenu::handleLoad() {
    cout << "Введите имя файла: ";
    string path;
    cin >> path;

    ifstream file(path);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << path << endl;
        return;
    }
    cube.loadFromStream(file);
    file.close();
    cout << "Кубик загружен." << endl;
}

void ConsoleMenu::handleSave() {
    cout << "Введите имя файла: ";
    string path;
    cin >> path;

    ofstream file(path);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << path << endl;
        return;
    }
    cube.saveToStream(file);
    file.close();
    cout << "Кубик сохранён." << endl;
}

void ConsoleMenu::handleRotateFace() {
    cout << "Выберите грань:" << endl;
    cout << "  0 - U (верхняя)" << endl;
    cout << "  1 - D (нижняя)" << endl;
    cout << "  2 - L (левая)" << endl;
    cout << "  3 - R (правая)" << endl;
    cout << "  4 - F (передняя)" << endl;
    cout << "  5 - B (задняя)" << endl;
    cout << "Номер грани: ";

    int faceIndex;
    cin >> faceIndex;
    if (faceIndex < 0 || faceIndex > 5) {
        cout << "Неверный номер грани." << endl;
        return;
    }

    cout << "Направление (1 - по часовой, 0 - против): ";
    int dir;
    cin >> dir;
    bool clockwise = (dir == 1);

    cube.rotateFace(faceIndex, clockwise);
    cout << "Грань повёрнута." << endl;
}

void ConsoleMenu::handleShowCube() {
    cout << cube << endl;
}

void ConsoleMenu::handleIsSolved() {
    if (cube.isSolved()) {
        cout << "Кубик собран!" << endl;
    } else {
        cout << "Кубик не собран." << endl;
    }
}