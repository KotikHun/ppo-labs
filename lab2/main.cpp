#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Кроссплатформенная поддержка русского языка
#ifdef _WIN32
#include <windows.h>
#endif

// Заголовки системы отеля
#include "HotelSystem.h"
#include "rooms/StandardRoom.h"
#include "rooms/SuiteRoom.h"
#include "rooms/DeluxeRoom.h"
#include "guests/RegularGuest.h"
#include "guests/VipGuest.h"
#include "guests/CorporateGuest.h"
#include "services/FoodService.h"
#include "services/SpaService.h"
#include "services/CleaningService.h"
#include "services/LaundryService.h"
#include "payments/CashPayment.h"
#include "payments/CreditCardPayment.h"

void initConsoleEncoding() {
#ifdef _WIN32
    // Установка кодировки UTF-8 для корректного отображения и ввода кириллицы в Windows
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
}

void printMainMenu() {
    std::cout << "\n=======================================================\n";
    std::cout << "        СИСТЕМА УПРАВЛЕНИЯ ГОСТИНИЦЕЙ (версия 2.0)     \n";
    std::cout << "=======================================================\n";
    std::cout << " [1] Регистрация гостей (Обычный / VIP / Корпоративный)\n";
    std::cout << " [2] Список всех зарегистрированных клиентов\n";
    std::cout << " [3] Добавить номер в фонд (Стандарт / Люкс / Делюкс)\n";
    std::cout << " [4] Состояние и занятость номерного фонда\n";
    std::cout << " [5] Оформление бронирования и Check-in\n";
    std::cout << " [6] Заказ дополнительных услуг (Еда / Спа / Химчистка)\n";
    std::cout << " [7] Расчёт, оплата счёта (Наличные / Карта) и Check-out\n";
    std::cout << " [8] Аналитический финансовый отчёт отеля\n";
    std::cout << " [0] Выход из системы\n";
    std::cout << "=======================================================\n";
    std::cout << "Выберите действие: ";
}

int main() {
    // Включаем UTF-8 для Windows
    initConsoleEncoding();

    HotelSystem hotel("Grand Royal Palace");
    std::cout << "[LOG] Система отеля успешно инициализирована.\n";

    int choice = -1;
    while (choice != 0) {
        printMainMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::string discard;
            std::cin >> discard;
            continue;
        }

        switch (choice) {
            case 1: { // 1. Регистрация гостя
                std::cout << "\n--- Регистрация нового гостя ---\n";
                std::cout << "1. Обычный гость (Regular)\n";
                std::cout << "2. VIP-клиент (VIP - персональная скидка)\n";
                std::cout << "3. Корпоративный клиент (Corporate - договор с компанией)\n";
                std::cout << "Выберите категорию: ";
                int type; std::cin >> type;

                std::string first, last, doc;
                std::cout << "Имя: "; std::cin >> first;
                std::cout << "Фамилия: "; std::cin >> last;
                std::cout << "Номер паспорта/документа: "; std::cin >> doc;

                if (type == 2) {
                    double discount = 15.0; // 15% VIP скидка
                    hotel.addGuest(std::make_shared<VipGuest>(first, last, doc, discount));
                    std::cout << ">> Зарегистрирован VIP-гость со скидкой 15%.\n";
                } else if (type == 3) {
                    std::string company;
                    std::cout << "Название компании: "; std::cin >> company;
                    hotel.addGuest(std::make_shared<CorporateGuest>(first, last, doc, company));
                    std::cout << ">> Зарегистрирован корпоративный гость от компании " << company << ".\n";
                } else {
                    hotel.addGuest(std::make_shared<RegularGuest>(first, last, doc));
                    std::cout << ">> Обычный гость успешно зарегистрирован.\n";
                }
                break;
            }

            case 2: { // 2. Просмотр всех гостей
                std::cout << "\n--- База зарегистрированных клиентов ---\n";
                auto guests = hotel.getAllGuests();
                if (guests.empty()) {
                    std::cout << "В базе пока нет зарегистрированных гостей.\n";
                } else {
                    for (const auto& g : guests) {
                        std::cout << "ID: " << g->getId()
                                  << " | " << g->getFullName()
                                  << " | Категория: " << g->getGuestType()
                                  << " | Документ: " << g->getPassport() << "\n";
                    }
                }
                break;
            }

            case 3: { // 3. Добавление номеров
                std::cout << "\n--- Добавление номера в фонд отеля ---\n";
                std::cout << "1. Стандарт (Standard)\n";
                std::cout << "2. Люкс (Suite)\n";
                std::cout << "3. Делюкс (Deluxe)\n";
                std::cout << "Выберите категорию номера: ";
                int rType; std::cin >> rType;

                int roomNum;
                double price;
                std::cout << "Номер комнаты: "; std::cin >> roomNum;
                std::cout << "Базовая цена за ночь ($): "; std::cin >> price;

                if (rType == 2) {
                    hotel.addRoom(std::make_shared<SuiteRoom>(roomNum, price, 2));
                    std::cout << ">> Двухкомнатный Люкс #" << roomNum << " добавлен.\n";
                } else if (rType == 3) {
                    hotel.addRoom(std::make_shared<DeluxeRoom>(roomNum, price, true));
                    std::cout << ">> Делюкс с видом на море #" << roomNum << " добавлен.\n";
                } else {
                    hotel.addRoom(std::make_shared<StandardRoom>(roomNum, price));
                    std::cout << ">> Стандартный номер #" << roomNum << " добавлен.\n";
                }
                break;
            }

            case 4: { // 4. Состояние комнат
                std::cout << "\n--- Номерной фонд отеля ---\n";
                hotel.showAllRooms();
                break;
            }

            case 5: { // 5. Бронирование и Check-in
                std::cout << "\n--- Оформление бронирования ---\n";
                int guestId, roomNum, nights;
                std::cout << "ID гостя: "; std::cin >> guestId;
                std::cout << "Номер комнаты: "; std::cin >> roomNum;
                std::cout << "Количество ночей: "; std::cin >> nights;

                if (hotel.createBooking(guestId, roomNum, nights)) {
                    std::cout << ">> Бронь подтверждена! Номер закреплен за гостем.\n";
                } else {
                    std::cout << ">> Ошибка: номер занят или указан неверный ID гостя.\n";
                }
                break;
            }

            case 6: { // 6. Заказ услуг
                std::cout << "\n--- Заказ дополнительных услуг в номер ---\n";
                int guestId;
                std::cout << "Введите ID гостя: "; std::cin >> guestId;

                std::cout << "1. Заказ еды / Обслуживание номеров (Food Service)\n";
                std::cout << "2. Спа-процедуры (Spa & Massage)\n";
                std::cout << "3. Химчистка и стирка (Laundry Service)\n";
                std::cout << "4. Внеплановая уборка номера (Cleaning Service)\n";
                std::cout << "Выберите услугу: ";
                int sType; std::cin >> sType;

                if (sType == 1) {
                    hotel.orderServiceForGuest(guestId, std::make_shared<FoodService>("Room Breakfast Set", 25.0));
                    std::cout << ">> Завтрак добавлен в счёт гостя.\n";
                } else if (sType == 2) {
                    hotel.orderServiceForGuest(guestId, std::make_shared<SpaService>("Thai Relaxation Massage", 80.0));
                    std::cout << ">> Спа-процедура добавлена в счёт гостя.\n";
                } else if (sType == 3) {
                    hotel.orderServiceForGuest(guestId, std::make_shared<LaundryService>("Suit Dry Cleaning", 30.0));
                    std::cout << ">> Услуга химчистки добавлена в счёт гостя.\n";
                } else {
                    hotel.orderServiceForGuest(guestId, std::make_shared<CleaningService>("Express Deep Cleaning", 20.0));
                    std::cout << ">> Уборка номера добавлена в счёт гостя.\n";
                }
                break;
            }

            case 7: { // 7. Check-out и оплата
                std::cout << "\n--- Расчёт и выселение (Check-out) ---\n";
                int guestId;
                std::cout << "Введите ID выселяемого гостя: "; std::cin >> guestId;

                double total = hotel.calculateTotalBill(guestId);
                std::cout << "Итого к оплате (номер + услуги с учётом скидок): $" << total << "\n";

                std::cout << "Способ оплаты:\n";
                std::cout << "1. Наличные (Cash)\n";
                std::cout << "2. Банковская карта (Credit Card)\n";
                std::cout << "Выберите вариант: ";
                int pMethod; std::cin >> pMethod;

                if (pMethod == 2) {
                    std::string cardNum;
                    std::cout << "Введите номер карты: "; std::cin >> cardNum;
                    CreditCardPayment payment(cardNum);
                    hotel.processPayment(guestId, payment);
                } else {
                    CashPayment payment;
                    hotel.processPayment(guestId, payment);
                }

                std::cout << ">> Чек закрыт, оплата принята. Номер освобождён!\n";
                break;
            }

            case 8: { // 8. Полный аналитический отчёт
                std::cout << "\n--- Аналитический сводный отчёт отеля ---\n";
                hotel.printSummaryReport();
                break;
            }

            case 0:
                std::cout << "Завершение работы программы. До свидания!\n";
                break;

            default:
                std::cout << "Неверный пункт меню. Повторите ввод.\n";
                break;
        }
    }

    return 0;
}