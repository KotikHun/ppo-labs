#include "GuestManager.h"
#include <iostream>

using namespace std;

GuestManager::GuestManager() {
    // Вектор инициализируется пустым автоматически
}

GuestManager::~GuestManager() {
}

void GuestManager::addGuest(const Guest& guest) {
    guests.push_back(guest);
}

Guest* GuestManager::findGuestById(const Id& id) {
    // Проходим по всему вектору гостей
    for (size_t i = 0; i < guests.size(); ++i) {
        if (guests[i].getId() == id) {
            return &guests[i]; // Возвращаем указатель на найденного гостя
        }
    }
    // Если никого не нашли, бросаем наше исключение!
    throw GuestNotFoundException("Guest with this ID was not found.");
}

void GuestManager::removeGuest(const Id& id) {
    // Сначала проверяем, существует ли такой гость (если нет, метод бросит исключение)
    findGuestById(id); 

    // Если нашли, удаляем его из вектора
    for (size_t i = 0; i < guests.size(); ++i) {
        if (guests[i].getId() == id) {
            guests.erase(guests.begin() + i);
            return; // Выходим после удаления
        }
    }
}

void GuestManager::printAllGuests() const {
    cout << "--- All Guests ---" << endl;
    if (guests.empty()) {
        cout << "No guests found." << endl;
        return;
    }
    for (size_t i = 0; i < guests.size(); ++i) {
        cout << guests[i].toString() << endl;
    }
    cout << "-------------------" << endl;
}

size_t GuestManager::getGuestCount() const {
    return guests.size();
}