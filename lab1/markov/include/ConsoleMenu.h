#pragma once

#include <string>
#include "MarkovAlgorithm.h"

/**
 * @brief Консольное меню для работы с нормальным алгорифмом Маркова.
 *
 * Предоставляет пользователю интерактивный интерфейс: загрузку,
 * сохранение, редактирование правил, работу с лентой и запуск алгоритма.
 */

class ConsoleMenu {
private:
    MarkovAlgorithm algorithm;
    bool logMode;
public:
    ConsoleMenu();

    void setAlgorithm(const MarkovAlgorithm& newAlgorithm);
    MarkovAlgorithm getAlgorithm() const;
    void setLogMode(bool enabled);
    bool isLogMode() const;

    void runInteractive();
    void runWithLog();
    void loadFromFile(const std::string& path);

private:
    void showMainMenu() const;
    int readChoice() const;
    void processChoice(int choice);

    void handleLoad();
    void handleSave();
    void handleSetAlphabet();
    void handleAddRule();
    void handleRemoveRule();
    void handleShowRules();
    void handleSetTape();
    void handleShowTape();
    void handleStep();
    void handleRun();

};









