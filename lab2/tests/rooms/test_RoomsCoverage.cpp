#include <gtest/gtest.h>
#include "Room.h"
#include "StandardRoom.h"
#include "LuxRoom.h"
#include "Apartment.h"
#include "SuiteRoom.h"
#include "Building.h"
#include "Floor.h"

TEST(RoomsCoverage, AllMethods) {
    StandardRoom sr(1, 2, RoomStatus::Available, Money(100, Currency::RUB), true);
    sr.getRoomNumber(); sr.getCapacity(); sr.getCategory(); sr.getStatus(); sr.getBasePrice(); sr.getId();
    sr.setRoomNumber(2); sr.setCapacity(3); sr.setStatus(RoomStatus::Occupied); sr.setBasePrice(Money(200, Currency::RUB)); sr.setHasBalcony(false);
    sr.toString(); sr.getHasBalcony(); sr.calculatePrice();
    EXPECT_NO_THROW(std::cout << sr);

    LuxRoom lr(1, 2, RoomStatus::Available, Money(100, Currency::RUB), true);
    lr.setHasJacuzzi(false); lr.getHasJacuzzi(); lr.toString(); lr.calculatePrice();

    Apartment apt(1, 4, RoomStatus::Available, Money(100, Currency::RUB), 2);
    apt.setRoomCount(3); apt.getRoomCount(); apt.toString(); apt.calculatePrice();

    SuiteRoom suite(1, 4, RoomStatus::Available, Money(100, Currency::RUB), true);
    suite.setHasPrivatePool(false); suite.getHasPrivatePool(); suite.toString(); suite.calculatePrice();

    Building b(1, "Main", Address(), 5);
    b.getNumber(); b.getName(); b.getAddress(); b.getFloorsCount();
    b.setNumber(2); b.setName("B"); b.setAddress(Address()); b.setFloorsCount(6);
    b.toString();
    EXPECT_NO_THROW(std::cout << b);

    Floor f(1, 10, "Floor");
    f.getNumber(); f.getRoomsCount(); f.getDescription();
    f.setNumber(2); f.setRoomsCount(12); f.setDescription("New");
    f.toString();
    EXPECT_NO_THROW(std::cout << f);
}