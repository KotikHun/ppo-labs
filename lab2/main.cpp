#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include <cctype>

// Кроссплатформенная поддержка UTF-8 для Windows
#ifdef _WIN32
#include <windows.h>
#endif

// Фасад отеля и менеджеры
#include "Hotel.h"

// Номерной фонд
#include "StandardRoom.h"
#include "LuxRoom.h"
#include "SuiteRoom.h"
#include "Apartment.h"

// Гости
#include "Guest.h"
#include "RegularGuest.h"
#include "VipGuest.h"
#include "CorporateGuest.h"

// Сервисы и заказы
#include "CleaningService.h"
#include "SpaService.h"
#include "FoodService.h"
#include "TransferService.h"
#include "LaundryService.h"
#include "ExcursionService.h"
#include "ServiceOrder.h"

// Платежи
#include "CashPayment.h"
#include "CardPayment.h"
#include "OnlinePayment.h"

// Базовые типы
#include "Money.h"
#include "Currency.h"
#include "RoomStatus.h"
#include "Date.h"
#include "Gender.h"
#include "ContactInfo.h"
#include "HotelException.h"

void initConsoleEncoding() {
#ifdef _WIN32
    // Нативная поддержка кириллицы в консоли Windows
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
}

// Безопасное чтение строки с пробелами (имя, компания, примечания)
std::string readString(const std::string& prompt) {
    std::cout << prompt;
    std::string line;
    while (std::getline(std::cin, line)) {
        size_t first = line.find_first_not_of(" \t\r\n");
        if (first != std::string::npos) {
            size_t last = line.find_last_not_of(" \t\r\n");
            return line.substr(first, (last - first + 1));
        }
    }
    return "";
}

// Умный ввод даты: принимает как "15.05.1998", так и "15 05 1998" или "15/05/1998"
Date inputDate(const std::string& prompt) {
    while (true) {
        std::cout << prompt << " (например, 15.05.1998): ";
        std::string raw;
        if (!std::getline(std::cin, raw)) continue;

        for (char& c : raw) {
            if (c == '.' || c == '/' || c == '-') c = ' ';
        }

        std::stringstream ss(raw);
        int d = 0, m = 0, y = 0;
        if (ss >> d >> m >> y) {
            Date dt(d, m, y);
            if (dt.isValid()) {
                return dt;
            }
        }
        std::cout << ">> [Ошибка] Неверная дата. Пожалуйста, введите существующий день, месяц и год.\n";
    }
}

// Безопасный ввод целых чисел
int readInt(const std::string& prompt, int minVal = 0, int maxVal = 1000000) {
    while (true) {
        std::cout << prompt;
        std::string s;
        if (std::getline(std::cin, s)) {
            std::stringstream ss(s);
            int val;
            if (ss >> val && val >= minVal && val <= maxVal) {
                return val;
            }
        }
        std::cout << ">> [Ошибка] Введите корректное число от " << minVal << " до " << maxVal << ".\n";
    }
}

// Безопасный ввод вещественных чисел
double readDouble(const std::string& prompt, double minVal = 0.0) {
    while (true) {
        std::cout << prompt;
        std::string s;
        if (std::getline(std::cin, s)) {
            std::stringstream ss(s);
            double val;
            if (ss >> val && val >= minVal) {
                return val;
            }
        }
        std::cout << ">> [Ошибка] Введите положительное число.\n";
    }
}

void printMainMenu() {
    std::cout << "\n=======================================================\n";
    std::cout << "        СИСТЕМА УПРАВЛЕНИЯ ГОСТИНИЦЕЙ (версия 2.1.1)   \n";
    std::cout << "=======================================================\n";
    std::cout << " [1] Регистрация гостей (Regular / VIP / Corporate)\n";
    std::cout << " [2] Список всех зарегистрированных гостей\n";
    std::cout << " [3] Добавить номер в фонд (Standard / Lux / Suite / Apt)\n";
    std::cout << " [4] Состояние номерного фонда\n";
    std::cout << " [5] Оформление бронирования номера\n";
    std::cout << " [6] Журнал активных бронирований\n";
    std::cout << " [7] Заказ сервиса в номер (Cleaning / Spa / Food / Transfer)\n";
    std::cout << " [8] Кассовый модуль: приём оплаты счетов\n";
    std::cout << " [9] Сводный аналитический отчёт отеля\n";
    std::cout << " [0] Выход из системы\n";
    std::cout << "=======================================================\n";
    std::cout << "Выберите действие: ";
}

int main() {
    initConsoleEncoding();

    Hotel hotel;
    hotel.setHotelName("Grand Royal Palace");
    hotel.setStarRating(5);
    hotel.setContactPhone("+375 (29) 111-22-33");
    hotel.setContactEmail("info@grandroyal.by");

    std::cout << "[LOG] Отель \"" << hotel.getHotelName() << "\" ("
              << hotel.getStarRating() << "*) успешно инициализирован.\n";

    // 1. Демонстрационный номерной фонд (сразу готов к работе)
    hotel.getRoomManager().addRoom(new StandardRoom(101, 2, RoomStatus::Available, Money(3500, Currency::RUB), true));
    hotel.getRoomManager().addRoom(new LuxRoom(201, 2, RoomStatus::Available, Money(7500, Currency::RUB), true));
    hotel.getRoomManager().addRoom(new SuiteRoom(301, 4, RoomStatus::Available, Money(15000, Currency::RUB), true));

    // 2. Демонстрационные гости (чтобы сразу можно было проверить бронь)
    {
        RegularGuest g1;
        g1.setFirstName("Александр");
        g1.setLastName("Пушкин");
        g1.setBirthDate(Date(6, 6, 1999));
        g1.setGender(Gender::Male);
        g1.setContacts(ContactInfo("+375291234567", "pushkin@mail.ru"));
        g1.setPassportNumber("MP1234567");
        g1.setPreferredLanguage("ru");
        g1.setNotes("Вид на исторический центр");
        g1.setVisitCount(3);
        hotel.getGuestManager().addGuest(g1);

        VipGuest g2;
        g2.setFirstName("Елена");
        g2.setLastName("Романова");
        g2.setBirthDate(Date(12, 4, 1995));
        g2.setGender(Gender::Female);
        g2.setContacts(ContactInfo("+375299876543", "romanova@vip.com"));
        g2.setPassportNumber("KB7654321");
        g2.setPreferredLanguage("ru");
        g2.setNotes("Постоянный почетный гость");
        g2.setDiscountPercent(15);
        hotel.getGuestManager().addGuest(g2);
    }

    int choice = -1;
    while (choice != 0) {
        printMainMenu();
        std::string choiceStr;
        if (!std::getline(std::cin, choiceStr)) continue;
        std::stringstream ss(choiceStr);
        if (!(ss >> choice)) continue;

        try {
            switch (choice) {
                case 1: { // 1. Регистрация гостя
                    std::cout << "\n--- Регистрация нового гостя ---\n";
                    std::cout << "1. Обычный гость (RegularGuest)\n";
                    std::cout << "2. VIP-клиент с персональной скидкой (VipGuest)\n";
                    std::cout << "3. Корпоративный клиент (CorporateGuest)\n";
                    int gType = readInt("Выберите категорию (1-3): ", 1, 3);

                    std::string first = readString("Имя: ");
                    std::string last = readString("Фамилия: ");
                    Date birth = inputDate("Дата рождения");

                    std::cout << "Пол (1 - Мужской, 2 - Женский, 3 - Другой): ";
                    int gGender = readInt("", 1, 3);
                    Gender gender = Gender::Other;
                    if (gGender == 1) gender = Gender::Male;
                    else if (gGender == 2) gender = Gender::Female;

                    std::string passport = readString("Номер паспорта: ");
                    std::string phone = readString("Контактный телефон: ");
                    std::string email = readString("Электронная почта: ");
                    std::string lang = readString("Предпочитаемый язык (ru/en): ");
                    std::string notes = readString("Примечания и пожелания: ");

                    ContactInfo contacts(phone, email);

                    if (gType == 2) {
                        int discount = readInt("Процент персональной скидки (0-100%): ", 0, 100);
                        VipGuest vip;
                        vip.setFirstName(first);
                        vip.setLastName(last);
                        vip.setBirthDate(birth);
                        vip.setGender(gender);
                        vip.setContacts(contacts);
                        vip.setPassportNumber(passport);
                        vip.setPreferredLanguage(lang);
                        vip.setNotes(notes);
                        vip.setDiscountPercent(discount);

                        hotel.getGuestManager().addGuest(vip);
                        std::cout << "\n>> [УСПЕХ] VIP-клиент " << first << " " << last
                                  << " зарегистрирован! Системный ID для бронирования: "
                                  << vip.getId().getValue() << "\n";
                    } else if (gType == 3) {
                        std::string company = readString("Название организации: ");
                        CorporateGuest corp;
                        corp.setFirstName(first);
                        corp.setLastName(last);
                        corp.setBirthDate(birth);
                        corp.setGender(gender);
                        corp.setContacts(contacts);
                        corp.setPassportNumber(passport);
                        corp.setPreferredLanguage(lang);
                        corp.setNotes(notes);
                        corp.setCompanyName(company);

                        hotel.getGuestManager().addGuest(corp);
                        std::cout << "\n>> [УСПЕХ] Корпоративный клиент компании \"" << company
                                  << "\" зарегистрирован! Системный ID для бронирования: "
                                  << corp.getId().getValue() << "\n";
                    } else {
                        int visits = readInt("Число предыдущих посещений: ", 0, 1000);
                        RegularGuest reg;
                        reg.setFirstName(first);
                        reg.setLastName(last);
                        reg.setBirthDate(birth);
                        reg.setGender(gender);
                        reg.setContacts(contacts);
                        reg.setPassportNumber(passport);
                        reg.setPreferredLanguage(lang);
                        reg.setNotes(notes);
                        reg.setVisitCount(visits);

                        hotel.getGuestManager().addGuest(reg);
                        std::cout << "\n>> [УСПЕХ] Гость " << first << " " << last
                                  << " зарегистрирован! Системный ID для бронирования: "
                                  << reg.getId().getValue() << "\n";
                    }
                    break;
                }

                case 2: { // 2. Просмотр реестра гостей
                    std::cout << "\n--- РЕЕСТР ЗАРЕГИСТРИРОВАННЫХ КЛИЕНТОВ ---\n";
                    hotel.getGuestManager().printAllGuests();
                    break;
                }

                case 3: { // 3. Добавление номеров
                    std::cout << "\n--- Добавление номера в номерной фонд ---\n";
                    std::cout << "1. Стандарт (StandardRoom)\n";
                    std::cout << "2. Люкс с джакузи (LuxRoom)\n";
                    std::cout << "3. Президентский люкс с бассейном (SuiteRoom)\n";
                    std::cout << "4. Многокомнатные апартаменты (Apartment)\n";
                    int rType = readInt("Выберите тип категории (1-4): ", 1, 4);

                    int number = readInt("Номер комнаты (например, 102): ", 1, 9999);
                    int capacity = readInt("Вместимость гостей: ", 1, 20);
                    int floor = readInt("Этаж: ", 1, 100);
                    double area = readDouble("Площадь помещения (кв. м): ", 10.0);
                    double price = readDouble("Базовая стоимость за сутки (RUB): ", 100.0);

                    Money baseCost(price, Currency::RUB);
                    Room* newRoom = nullptr;

                    if (rType == 2) {
                        std::string ans = readString("Наличие гидромассажной ванны/джакузи (y/n): ");
                        bool hasJacuzzi = (ans == "y" || ans == "Y" || ans == "д" || ans == "Д");
                        newRoom = new LuxRoom(number, capacity, RoomStatus::Available, baseCost, hasJacuzzi);
                    } else if (rType == 3) {
                        std::string ans = readString("Наличие приватного бассейна (y/n): ");
                        bool hasPool = (ans == "y" || ans == "Y" || ans == "д" || ans == "Д");
                        newRoom = new SuiteRoom(number, capacity, RoomStatus::Available, baseCost, hasPool);
                    } else if (rType == 4) {
                        int roomsCount = readInt("Число изолированных комнат: ", 1, 10);
                        newRoom = new Apartment(number, capacity, RoomStatus::Available, baseCost, roomsCount);
                    } else {
                        std::string ans = readString("Наличие балкона/террасы (y/n): ");
                        bool hasBalcony = (ans == "y" || ans == "Y" || ans == "д" || ans == "Д");
                        newRoom = new StandardRoom(number, capacity, RoomStatus::Available, baseCost, hasBalcony);
                    }

                    newRoom->setFloorNumber(floor);
                    newRoom->setAreaSquareMeters(area);

                    hotel.getRoomManager().addRoom(newRoom);
                    std::cout << "\n>> [УСПЕХ] Номер #" << number << " добавлен в активный фонд отеля!\n";
                    break;
                }

                case 4: { // 4. Показать все комнаты
                    std::cout << "\n--- ТЕКУЩЕЕ СОСТОЯНИЕ НОМЕРНОГО ФОНДА ---\n";
                    hotel.getRoomManager().printAllRooms();
                    break;
                }

                case 5: { // 5. Наглядное оформление бронирования
                    std::cout << "\n=======================================================\n";
                    std::cout << "               ОФОРМЛЕНИЕ БРОНИРОВАНИЯ                 \n";
                    std::cout << "=======================================================\n";

                    if (hotel.getGuestManager().getGuestCount() == 0) {
                        std::cout << ">> [ВНИМАНИЕ] В базе ещё нет гостей!\n";
                        std::cout << ">> Сначала зарегистрируйте клиента через пункт меню [1].\n";
                        break;
                    }

                    // 1. Показываем комнаты
                    std::cout << "\n--- Доступные номера фонда: ---\n";
                    hotel.getRoomManager().printAllRooms();
                    int roomNum = readInt("Введите номер комнаты для брони: ", 1, 9999);

                    Room* room = hotel.getRoomManager().findRoomByNumber(roomNum);
                    if (room->getStatus() != RoomStatus::Available) {
                        std::cout << ">> [Ошибка] Номер #" << roomNum << " занят или закрыт на уборку/ремонт!\n";
                        break;
                    }

                    // 2. Показываем гостей
                    std::cout << "\n--- Зарегистрированные клиенты отеля: ---\n";
                    hotel.getGuestManager().printAllGuests();
                    std::cout << "Подсказка: найдите нужного гостя выше и введите число из поля id=ID-X.\n";

                    int guestIdNum = readInt("Введите числовой ID гостя (например, 1): ", 1);
                    Guest* guest = hotel.getGuestManager().findGuestById(Id(guestIdNum));

                    std::cout << "\nВыбран клиент: " << guest->getFirstName() << " " << guest->getLastName() << "\n";
                    Date startDate = inputDate("Дата заселения");
                    Date endDate = inputDate("Дата выселения");

                    if (!(startDate < endDate)) {
                        std::cout << ">> [Ошибка] Дата выезда не может быть раньше или равна дате заезда!\n";
                        break;
                    }

                    int nights = startDate.daysBetween(endDate);
                    Money total = room->calculatePrice().multiply(nights);

                    hotel.getBookingManager().makeReservation(guest->getId(), room->getId(), startDate, endDate, total);
                    room->setStatus(RoomStatus::Occupied);

                    std::cout << "\n>> [УСПЕХ] Бронь подтверждена и внесена в журнал!\n";
                    std::cout << ">> Номер: #" << roomNum << " | Ночей: " << nights << "\n";
                    std::cout << ">> Период: с " << startDate.toString() << " по " << endDate.toString() << "\n";
                    std::cout << ">> Итого к оплате: " << total.toString() << "\n";
                    break;
                }

                case 6: { // 6. Список бронирований
                    std::cout << "\n--- ЖУРНАЛ АКТИВНЫХ БРОНИРОВАНИЙ ---\n";
                    if (hotel.getBookingManager().getReservationCount() == 0) {
                        std::cout << "Активных бронирований пока нет.\n";
                    } else {
                        hotel.getBookingManager().printAllReservations();
                    }
                    break;
                }

                case 7: { // 7. Заказ услуги
                    std::cout << "\n--- КАТАЛОГ ГОСТИНИЧНЫХ СЕРВИСОВ ---\n";
                    if (hotel.getGuestManager().getGuestCount() == 0) {
                        std::cout << ">> [ВНИМАНИЕ] В базе нет гостей для оформления счёта!\n";
                        break;
                    }

                    std::cout << "1. Spa & Wellness массаж (SpaService)\n";
                    std::cout << "2. Доставка еды и напитков в номер (FoodService)\n";
                    std::cout << "3. Внеплановая уборка номера (CleaningService)\n";
                    std::cout << "4. Услуги прачечной / химчистки (LaundryService)\n";
                    std::cout << "5. Индивидуальная экскурсия по городу (ExcursionService)\n";
                    std::cout << "6. Трансфер на автомобиле отеля (TransferService)\n";
                    int sType = readInt("Выберите услугу (1-6): ", 1, 6);

                    std::unique_ptr<Service> service;

                    if (sType == 1) {
                        int hours = readInt("Длительность сеанса (часов): ", 1, 12);
                        service = std::make_unique<SpaService>("Спа-релакс комплекс", Money(2000, Currency::RUB), hours);
                    } else if (sType == 2) {
                        std::string ans = readString("Доставка непосредственно в апартаменты? (y/n): ");
                        bool isRoom = (ans == "y" || ans == "Y" || ans == "д" || ans == "Д");
                        service = std::make_unique<FoodService>("Ресторанный сет", Money(900, Currency::RUB), isRoom);
                    } else if (sType == 3) {
                        int rooms = readInt("Количество комнат для клининга: ", 1, 10);
                        service = std::make_unique<CleaningService>("Клининг номеров", Money(750, Currency::RUB), rooms);
                    } else if (sType == 4) {
                        int items = readInt("Количество вещей: ", 1, 50);
                        service = std::make_unique<LaundryService>("Стирка и глажка", Money(300, Currency::RUB), items);
                    } else if (sType == 5) {
                        int people = readInt("Количество участников: ", 1, 30);
                        service = std::make_unique<ExcursionService>("Экскурсия", Money(1500, Currency::RUB), people);
                    } else {
                        double dist = readDouble("Расстояние поездки (км): ", 1.0);
                        service = std::make_unique<TransferService>("Трансфер отеля", Money(120, Currency::RUB), dist);
                    }

                    Money cost = service->calculateCost();
                    std::cout << ">> Выбран сервис: " << service->toString() << "\n";
                    std::cout << ">> Рассчитанная стоимость: " << cost.toString() << "\n";

                    std::cout << "\n--- Зарегистрированные гости: ---\n";
                    hotel.getGuestManager().printAllGuests();
                    int guestIdNum = readInt("Введите числовой ID клиента: ", 1);

                    ServiceOrder order(Id(guestIdNum), service->getId(), 1, cost);
                    hotel.getServiceManager().addOrder(order);
                    std::cout << "\n>> [УСПЕХ] Заказ добавлен в чек клиента: " << order.toString() << "\n";
                    break;
                }

                case 8: { // 8. Модуль оплаты
                    std::cout << "\n--- КАССОВЫЙ МОДУЛЬ ПРИЁМА ПЛАТЕЖЕЙ ---\n";
                    std::cout << "1. Наличный расчёт с выдачей сдачи (CashPayment)\n";
                    std::cout << "2. Банковская карта (CardPayment)\n";
                    std::cout << "3. Онлайн-платёж (OnlinePayment)\n";
                    int pType = readInt("Выберите метод оплаты (1-3): ", 1, 3);

                    // Показываем текущие бронирования для ориентира по ценам
                    std::cout << "\nЖурнал бронирований для справки по суммам:\n";
                    hotel.getBookingManager().printAllReservations();

                    double amount = readDouble("Сумма к оплате (RUB): ", 1.0);
                    Date today = inputDate("Дата расчёта");
                    Money total(amount, Currency::RUB);

                    Payment* payment = nullptr;

                    if (pType == 1) {
                        double given = readDouble("Внесено клиентом наличными (RUB): ", amount);
                        double change = (given > amount) ? (given - amount) : 0.0;
                        payment = new CashPayment(total, today, Money(change, Currency::RUB));
                        payment->processPayment();
                        hotel.getPaymentManager().addPayment(payment);

                        std::cout << "\n>> [УСПЕХ] Платёж принят! Сдача клиенту: " << change << " RUB\n";
                        std::cout << ">> " << payment->toString() << "\n";
                    } else if (pType == 2) {
                        std::string card = readString("Введите 16 цифр банковской карты: ");
                        payment = new CardPayment(total, today, card);
                        if (payment->processPayment()) {
                            std::cout << "\n>> [УСПЕХ] Транзакция по банковской карте авторизована!\n";
                        } else {
                            std::cout << "\n>> [ОТКЛОНЕНО] Неверный номер карты!\n";
                        }
                        hotel.getPaymentManager().addPayment(payment);
                        std::cout << ">> " << payment->toString() << "\n";
                    } else {
                        std::string email = readString("Email для отправки фискального чека: ");
                        payment = new OnlinePayment(total, today, email);
                        if (payment->processPayment()) {
                            std::cout << "\n>> [УСПЕХ] Онлайн-платёж успешно проведён через интернет!\n";
                        } else {
                            std::cout << "\n>> [ОТКЛОНЕНО] Некорректный email адрес!\n";
                        }
                        hotel.getPaymentManager().addPayment(payment);
                        std::cout << ">> " << payment->toString() << "\n";
                    }
                    break;
                }

                case 9: { // 9. Сводный отчёт
                    std::cout << "\n--- СВОДНЫЙ ОПЕРАЦИОННЫЙ ОТЧЁТ ОТЕЛЯ ---\n";
                    std::cout << "Отель: " << hotel.getHotelName()
                              << " (" << hotel.getStarRating() << "*)\n";
                    std::cout << "Контакты: " << hotel.getContactPhone() << " | " << hotel.getContactEmail() << "\n\n";

                    hotel.getReportManager().printSummaryReport(
                        hotel.getGuestManager(),
                        hotel.getRoomManager(),
                        hotel.getBookingManager(),
                        hotel.getPaymentManager()
                    );
                    break;
                }

                case 0:
                    std::cout << "Работа системы гостиницы завершена. До свидания!\n";
                    break;

                default:
                    std::cout << "Неизвестный пункт меню. Повторите выбор.\n";
                    break;
            }
        } catch (const HotelException& e) {
            std::cout << "\n>> [ОШИБКА БИЗНЕС-ЛОГИКИ] " << e.what() << "\n";
        } catch (const std::exception& e) {
            std::cout << "\n>> [СИСТЕМНАЯ ОШИБКА] " << e.what() << "\n";
        }
    }

    return 0;
}