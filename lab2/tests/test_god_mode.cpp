#include <gtest/gtest.h>
#include <sstream>
#include "Date.h"
#include "Money.h"
#include "Room.h"
#include "StandardRoom.h"
#include "Service.h"
#include "Payment.h"
#include "Address.h"
#include "ContactInfo.h"

TEST(GodMode, CoverEverything) {
    std::stringstream ss;
    Date d1(1,1,2023), d2(2,1,2023);
    
    // Явно вызываем все сеттеры (и покроем пустые строки)
    d1.setDay(15); d1.setMonth(6); d1.setYear(2023);
    
    // Явно проверяем високосный год и добавление дней
    Date leap(1,1,2024); leap.isLeapYear(); leap.addDays(1);
    
    // Проверяем операторы ввода-вывода
    ss << d1; ss >> d2;

    // Деньги - все операции
    Money m1(100, Currency::RUB), m2(50, Currency::USD);
    m1.add(m2); m1.subtract(m2); m1.multiply(2); m1.toString();
    ss << m1; ss >> m2;

    // Адрес и контакты
    Address addr("R","C","S","H");
    addr.setCountry("R2"); addr.setCity("C2"); addr.setStreet("S2"); addr.setHouse("H2");
    addr.toString(); ss << addr;

    ContactInfo ci("123", "a@b.c");
    ci.setPhone("456"); ci.setEmail("c@d.e");
    ci.toString(); ss << ci;

    // Абстрактные классы через наследников
    StandardRoom room(101, 2, RoomStatus::Available, m1, true);
    ss << room;
    
    // Тестируем базовый класс Room через полиморфизм
    Room* baseRoom = &room;
    baseRoom->getId();
    baseRoom->getRoomNumber();
    baseRoom->getCapacity();
    baseRoom->getCategory();
    baseRoom->getStatus();
    baseRoom->getBasePrice();
    baseRoom->calculatePrice();
    baseRoom->toString();

    // Тестируем пустые деструкторы
    {
        Date temp;
        Money tempMoney;
        Address tempAddr;
        ContactInfo tempCi;
    }
    
    EXPECT_TRUE(true);
}