#pragma once

#include "Cube.h"
#include <string>

/**
 * @brief Консольное меню для игры в Кубик Рубика.
 */
class ConsoleMenu {
private:
    Cube cube;

public:
    ConsoleMenu();

    void setCube(const Cube& newCube);
    Cube getCube() const;

    void runInteractive();

private:
    void showMainMenu() const;
    int readChoice() const;
    void processChoice(int choice);

    void handleNewGame();
    void handleRandomize();
    void handleLoad();
    void handleSave();
    void handleRotateFace();
    void handleShowCube();
    void handleIsSolved();
};