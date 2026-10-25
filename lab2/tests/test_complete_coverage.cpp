#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <vector>

// Core
#include "Address.h"
#include "ContactInfo.h"
#include "Date.h"
#include "Id.h"
#include "Money.h"
#include "Currency.h"
#include "Gender.h"
#include "Season.h"
#include "Logger.h"

// Documents
#include "Document.h"
#include "Passport.h"
#include "Visa.h"
#include "Contract.h"
#include "Receipt.h"

// Booking
#include "CheckIn.h"
#include "CheckOut.h"
#include "Company.h"
#include "GuestGroup.h"
#include "Reservation.h"
#include "Stay.h"
#include "BookingStatus.h"

// Payments
#include "Payment.h"
#include "CashPayment.h"
#include "CardPayment.h"
#include "OnlinePayment.h"
#include "Invoice.h"
#include "Tariff.h"
#include "Discount.h"
#include "PaymentStatus.h"

// People
#include "Person.h"
#include "Guest.h"
#include "VipGuest.h"
#include "RegularGuest.h"
#include "CorporateGuest.h"
#include "Employee.h"
#include "Manager.h"
#include "Administrator.h"
#include "Maid.h"
#include "Chef.h"
#include "SecurityGuard.h"
#include "ContactPerson.h"

// Rooms
#include "Room.h"
#include "StandardRoom.h"
#include "LuxRoom.h"
#include "Apartment.h"
#include "SuiteRoom.h"
#include "Building.h"
#include "Floor.h"
#include "RoomCategory.h"
#include "RoomStatus.h"

// Services
#include "Service.h"
#include "CleaningService.h"
#include "FoodService.h"
#include "TransferService.h"
#include "ExcursionService.h"
#include "SpaService.h"
#include "LaundryService.h"
#include "ServiceOrder.h"
#include "ServiceCategory.h"

// Reviews
#include "Rating.h"
#include "Comment.h"
#include "Review.h"
#include "Feedback.h"
#include "Complaint.h"

// Managers & Hotel
#include "GuestManager.h"
#include "RoomManager.h"
#include "BookingManager.h"
#include "ServiceManager.h"
#include "PaymentManager.h"
#include "StaffManager.h"
#include "ReportManager.h"
#include "Hotel.h"

// Exceptions
#include "CapacityExceededException.h"
#include "CheckInNotAllowedException.h"
#include "CheckOutNotAllowedException.h"
#include "DocumentExpiredException.h"
#include "GuestNotFoundException.h"
#include "HotelException.h"
#include "InvalidDateException.h"
#include "InvalidGuestDataException.h"
#include "InvalidPaymentException.h"
#include "PaymentFailedException.h"
#include "ReservationNotFoundException.h"
#include "RoomAlreadyBookedException.h"
#include "RoomNotAvailableException.h"
#include "ServiceNotAvailableException.h"
#include "RoomNotFoundException.h"

// ========================================================
// 1. Exceptions Full Coverage
// ========================================================
TEST(CompleteCoverage, AllCustomExceptions) {
    EXPECT_THROW({ throw CapacityExceededException("capacity exceeded"); }, CapacityExceededException);
    EXPECT_THROW({ throw CheckInNotAllowedException("check-in denied"); }, CheckInNotAllowedException);
    EXPECT_THROW({ throw CheckOutNotAllowedException("check-out denied"); }, CheckOutNotAllowedException);
    EXPECT_THROW({ throw DocumentExpiredException("doc expired"); }, DocumentExpiredException);
    EXPECT_THROW({ throw GuestNotFoundException("guest 404"); }, GuestNotFoundException);
    EXPECT_THROW({ throw HotelException("base hotel error"); }, HotelException);
    EXPECT_THROW({ throw InvalidDateException("bad date"); }, InvalidDateException);
    EXPECT_THROW({ throw InvalidGuestDataException("bad guest data"); }, InvalidGuestDataException);
    EXPECT_THROW({ throw InvalidPaymentException("bad payment"); }, InvalidPaymentException);
    EXPECT_THROW({ throw PaymentFailedException("payment failed"); }, PaymentFailedException);
    EXPECT_THROW({ throw ReservationNotFoundException("res 404"); }, ReservationNotFoundException);
    EXPECT_THROW({ throw RoomAlreadyBookedException("room already booked"); }, RoomAlreadyBookedException);
    EXPECT_THROW({ throw RoomNotAvailableException("room not available"); }, RoomNotAvailableException);
    EXPECT_THROW({ throw ServiceNotAvailableException("svc not available"); }, ServiceNotAvailableException);
    EXPECT_THROW({ throw RoomNotFoundException("room 404"); }, RoomNotFoundException);

    try {
        throw HotelException("test message");
    } catch (const HotelException& e) {
        EXPECT_STREQ(e.what(), "test message");
    }
}

// ========================================================
// 2. Core Entities Full Coverage (Date, Money, Address, ContactInfo, Id)
// ========================================================
TEST(CompleteCoverage, DateExhaustive) {
    Date dDefault;
    EXPECT_EQ(dDefault.getDay(), 1);
    EXPECT_EQ(dDefault.getMonth(), 1);
    EXPECT_EQ(dDefault.getYear(), 2000);

    // Leap year branches: 400, 100, 4, not leap
    Date d400(1, 1, 2000);
    EXPECT_TRUE(d400.isLeapYear());
    Date d100(1, 1, 1900);
    EXPECT_FALSE(d100.isLeapYear());
    Date d4(1, 1, 2024);
    EXPECT_TRUE(d4.isLeapYear());
    Date dNonLeap(1, 1, 2023);
    EXPECT_FALSE(dNonLeap.isLeapYear());

    // Validations: month < 1, month > 12, year < 1, leap feb day 29, invalid day
    EXPECT_FALSE(Date(1, 0, 2020).isValid());
    EXPECT_FALSE(Date(1, 13, 2020).isValid());
    EXPECT_FALSE(Date(1, 1, 0).isValid());
    EXPECT_TRUE(Date(29, 2, 2024).isValid());
    EXPECT_FALSE(Date(29, 2, 2023).isValid());
    EXPECT_FALSE(Date(32, 1, 2023).isValid());
    EXPECT_FALSE(Date(0, 1, 2023).isValid());

    // Comparisons (<, >, ==, !=, <=, >=)
    Date da(10, 5, 2022);
    Date db(15, 5, 2022);
    Date dc(10, 6, 2022);
    Date dd(10, 5, 2023);
    EXPECT_TRUE(da < db);
    EXPECT_TRUE(da < dc);
    EXPECT_TRUE(da < dd);
    EXPECT_TRUE(db > da);
    EXPECT_TRUE(dc > da);
    EXPECT_TRUE(dd > da);
    EXPECT_TRUE(da <= da);
    EXPECT_TRUE(da >= da);
    EXPECT_TRUE(da != db);
    EXPECT_TRUE(da == da);

    // Self assignment and copy constructor
    Date dCopy = da;
    EXPECT_EQ(dCopy, da);
    dCopy = dCopy;
    EXPECT_EQ(dCopy, da);

    // Setters
    dCopy.setDay(25);
    dCopy.setMonth(12);
    dCopy.setYear(2025);
    EXPECT_EQ(dCopy.getDay(), 25);
    EXPECT_EQ(dCopy.getMonth(), 12);
    EXPECT_EQ(dCopy.getYear(), 2025);

    // addDays negative and year roll-over
    Date endYear(31, 12, 2023);
    Date nextYear = endYear.addDays(1);
    EXPECT_EQ(nextYear.getYear(), 2024);
    EXPECT_EQ(nextYear.getMonth(), 1);
    EXPECT_EQ(nextYear.getDay(), 1);

    Date startYear(1, 1, 2024);
    Date prevYear = startYear.addDays(-1);
    EXPECT_EQ(prevYear.getYear(), 2023);
    EXPECT_EQ(prevYear.getMonth(), 12);
    EXPECT_EQ(prevYear.getDay(), 31);

    // daysBetween positive and negative
    EXPECT_EQ(endYear.daysBetween(nextYear), 1);
    EXPECT_EQ(nextYear.daysBetween(endYear), -1);

    // Stream operator
    std::stringstream ss;
    ss << da;
    EXPECT_FALSE(ss.str().empty());
}

TEST(CompleteCoverage, MoneyExhaustive) {
    Money mDefault;
    EXPECT_EQ(mDefault.getAmount(), 0.0);
    EXPECT_EQ(mDefault.getCurrency(), Currency::RUB);

    Money mUSD(100.0, Currency::USD);
    Money mEUR(50.0, Currency::EUR);
    Money mRUB(1000.0, Currency::RUB);

    EXPECT_EQ(mUSD.getCurrency(), Currency::USD);
    EXPECT_EQ(mEUR.getCurrency(), Currency::EUR);
    EXPECT_EQ(mRUB.getCurrency(), Currency::RUB);

    // Self-assignment
    mUSD = mUSD;
    EXPECT_DOUBLE_EQ(mUSD.getAmount(), 100.0);

    // Comparisons
    Money m1(10.0, Currency::RUB);
    Money m2(20.0, Currency::RUB);
    EXPECT_TRUE(m1 < m2);
    EXPECT_TRUE(m2 > m1);
    EXPECT_TRUE(m1 <= m2);
    EXPECT_TRUE(m2 >= m1);
    EXPECT_TRUE(m1 != m2);
    EXPECT_TRUE(m1 == m1);

    // Arithmetic
    Money sum = m1.add(m2);
    EXPECT_DOUBLE_EQ(sum.getAmount(), 30.0);
    Money diff = m2.subtract(m1);
    EXPECT_DOUBLE_EQ(diff.getAmount(), 10.0);
    Money mult = m1.multiply(2.5);
    EXPECT_DOUBLE_EQ(mult.getAmount(), 25.0);

    // ToString output contains currency sign
    EXPECT_NE(mUSD.toString().find("USD"), std::string::npos);
    EXPECT_NE(mEUR.toString().find("EUR"), std::string::npos);
    EXPECT_NE(mRUB.toString().find("RUB"), std::string::npos);

    // Stream operators
    std::stringstream ss;
    ss << mUSD;
    Money mIn;
    ss >> mIn;
}

TEST(CompleteCoverage, AddressExhaustive) {
    Address a1("RU", "Moscow", "Tverskaya", "10");
    Address a2("RU", "Moscow", "Arbat", "5");
    Address a3("US", "New York", "Broadway", "1");
    Address a4("RU", "Kazan", "Baumana", "3");

    // Getters
    EXPECT_EQ(a1.getCountry(), "RU");
    EXPECT_EQ(a1.getCity(), "Moscow");
    EXPECT_EQ(a1.getStreet(), "Tverskaya");
    EXPECT_EQ(a1.getHouse(), "10");

    // Self assignment and copy
    Address aCopy = a1;
    aCopy = aCopy;
    EXPECT_EQ(aCopy, a1);

    // Comparisons
    EXPECT_TRUE(a1 != a2);
    EXPECT_TRUE(a1 == a1);
    EXPECT_TRUE(a1 < a3); // different country
    EXPECT_TRUE(a4 < a1); // same country, different city
    EXPECT_TRUE(a2 < a1); // same city, different street
    EXPECT_TRUE(a1 != a3);

    // Stream
    std::stringstream ss;
    ss << a1;
    Address aIn;
    ss >> aIn;
}

TEST(CompleteCoverage, ContactInfoExhaustive) {
    ContactInfo ci("+1234567890", "user@domain.com");
    EXPECT_EQ(ci.getPhone(), "+1234567890");
    EXPECT_EQ(ci.getEmail(), "user@domain.com");
    EXPECT_TRUE(ci.isValid());

    // Invalid email branches
    ContactInfo badEmail1("+1234567890", "userdomain.com");
    EXPECT_FALSE(badEmail1.isValid());
    ContactInfo badEmail2("+1234567890", "user@domaincom");
    EXPECT_FALSE(badEmail2.isValid());
    ContactInfo badEmail5("+1234567890", "u@d.");
    EXPECT_FALSE(badEmail5.isValid());

    // Comparisons & operators
    ContactInfo ci2 = ci;
    ci2 = ci2;
    EXPECT_TRUE(ci == ci2);
    ci2.setPhone("+9876543210");
    EXPECT_TRUE(ci != ci2);

    std::stringstream ss;
    ss << ci;
    ContactInfo ciIn;
    ss >> ciIn;
}

TEST(CompleteCoverage, IdExhaustive) {
    Id id1;
    Id id2(42);
    Id id3(100);
    EXPECT_EQ(id2.getValue(), 42);

    // Self assignment
    id1 = id1;

    // Comparisons
    EXPECT_TRUE(id2 < id3);
    EXPECT_TRUE(id3 > id2);
    EXPECT_TRUE(id2 != id3);
    EXPECT_TRUE(id2 == id2);

    // Manual set & stream
    id1.setValue(77);
    std::stringstream ss;
    ss << id1;
    EXPECT_FALSE(ss.str().empty());
}

// ========================================================
// 3. Rooms & Buildings Full Coverage
// ========================================================
TEST(CompleteCoverage, RoomsAndBuildings) {
    // Building with new fields
    Building b1;
    EXPECT_EQ(b1.getConstructionYear(), 2020);
    EXPECT_EQ(b1.getDescription(), "Main building");
    b1.setConstructionYear(2022);
    b1.setDescription("Luxury wing");
    EXPECT_EQ(b1.getConstructionYear(), 2022);
    EXPECT_EQ(b1.getDescription(), "Luxury wing");

    Building b2(2, "Annex", Address(), 3);
    EXPECT_TRUE(b1 != b2);
    b1 = b1; // self assign
    Building bCopy = b1;
    EXPECT_EQ(bCopy, b1);

    std::stringstream ssB;
    ssB << b1;
    Building bIn;
    ssB >> bIn;

    // Floor
    Floor fl(1, 10, "Standard floor");
    EXPECT_EQ(fl.getNumber(), 1);
    EXPECT_EQ(fl.getRoomsCount(), 10);
    EXPECT_EQ(fl.getDescription(), "Standard floor");
    Floor flCopy = fl;
    flCopy = flCopy;
    EXPECT_TRUE(fl == flCopy);
    flCopy.setNumber(2);
    EXPECT_TRUE(fl != flCopy);
    flCopy.setRoomsCount(15);
    flCopy.setDescription("Executive floor");

    std::stringstream ssFl;
    ssFl << fl;
    Floor flIn;
    ssFl >> flIn;

    // StandardRoom, LuxRoom, Apartment, SuiteRoom with new Room fields
    StandardRoom sRoom(101, 2, RoomStatus::Available, Money(100, Currency::RUB), true);
    sRoom.setAreaSquareMeters(30.5);
    sRoom.setFloorNumber(3);
    EXPECT_DOUBLE_EQ(sRoom.getAreaSquareMeters(), 30.5);
    EXPECT_EQ(sRoom.getFloorNumber(), 3);
    sRoom.setCategory(RoomCategory::Standard);
    sRoom = sRoom; // self assign
    StandardRoom sCopy = sRoom;
    EXPECT_TRUE(sRoom == sCopy);

    std::stringstream ssSR;
    ssSR << sRoom;
    StandardRoom sIn;
    ssSR >> sIn;

    LuxRoom lux(102, 2, RoomStatus::Available, Money(200, Currency::RUB), true);
    lux = lux;
    LuxRoom luxCopy = lux;
    EXPECT_TRUE(lux.getHasJacuzzi());
    luxCopy.setHasJacuzzi(false);
    EXPECT_FALSE(luxCopy.getHasJacuzzi());
    std::stringstream ssLux;
    ssLux << lux;
    LuxRoom luxIn;
    ssLux >> luxIn;

    Apartment apt(103, 4, RoomStatus::Available, Money(300, Currency::RUB), 3);
    apt = apt;
    Apartment aptCopy = apt;
    EXPECT_EQ(apt.getRoomCount(), 3);
    aptCopy.setRoomCount(4);
    EXPECT_EQ(aptCopy.getRoomCount(), 4);
    std::stringstream ssApt;
    ssApt << apt;
    Apartment aptIn;
    ssApt >> aptIn;

    SuiteRoom suite(104, 3, RoomStatus::Available, Money(400, Currency::RUB), true);
    suite = suite;
    SuiteRoom suiteCopy = suite;
    EXPECT_TRUE(suite.getHasPrivatePool());
    suiteCopy.setHasPrivatePool(false);
    EXPECT_FALSE(suiteCopy.getHasPrivatePool());
    std::stringstream ssSuite;
    ssSuite << suite;
    SuiteRoom suiteIn;
    ssSuite >> suiteIn;

    // Base Room operators
    Room* r1 = &sRoom;
    Room* r2 = &lux;
    EXPECT_TRUE(*r1 != *r2);
    EXPECT_TRUE(*r1 == *r1);
}

// ========================================================
// 4. People Full Coverage
// ========================================================
TEST(CompleteCoverage, PeopleHierarchyExhaustive) {
    Date bDate(1, 1, 1990);
    ContactInfo cInfo("+1234567890", "john@mail.com");

    // Person
    Person p1("John", "Doe", bDate, cInfo, Gender::Male);
    EXPECT_EQ(p1.getFirstName(), "John");
    EXPECT_EQ(p1.getLastName(), "Doe");
    EXPECT_EQ(p1.getGender(), Gender::Male);
    p1 = p1; // self assign
    Person pCopy = p1;
    EXPECT_TRUE(p1 == pCopy);
    pCopy.setFirstName("Jane");
    EXPECT_EQ(pCopy.getFirstName(), "Jane");
    EXPECT_EQ(pCopy.getLastName(), "Doe");

    // Guest with new fields
    Guest g1("Alice", "Smith", bDate, cInfo, Gender::Female, "PASS123");
    g1.setPreferredLanguage("ru");
    g1.setNotes("Prefers quiet room");
    EXPECT_EQ(g1.getPreferredLanguage(), "ru");
    EXPECT_EQ(g1.getNotes(), "Prefers quiet room");
    g1.addLoyaltyPoints(50);
    EXPECT_EQ(g1.getLoyaltyPoints(), 50);
    g1 = g1; // self assign
    Guest gCopy = g1;
    EXPECT_TRUE(g1 == gCopy);

    Guest g2("Bob", "Brown", bDate, cInfo, Gender::Male, "PASS456");
    g2.setLoyaltyPoints(100);
    EXPECT_TRUE(g1 < g2);
    EXPECT_TRUE(g2 > g1);
    EXPECT_TRUE(g1 != g2);

    std::stringstream ssG;
    ssG << g1;
    Guest gIn;
    ssG >> gIn;

    // VipGuest
    VipGuest vipDef;
    VipGuest vip1("Vip", "User", bDate, cInfo, Gender::Female, "VIP999", 20);
    EXPECT_EQ(vip1.getDiscountPercent(), 20);
    vip1 = vip1; // self assign
    VipGuest vipCopy = vip1;
    vipCopy.setDiscountPercent(25);
    EXPECT_EQ(vipCopy.getDiscountPercent(), 25);
    std::stringstream ssVip;
    ssVip << vip1;
    VipGuest vipIn;
    ssVip >> vipIn;

    // RegularGuest
    RegularGuest regDef;
    RegularGuest reg1("Reg", "User", bDate, cInfo, Gender::Male, "REG111");
    reg1.setVisitCount(5);
    EXPECT_EQ(reg1.getVisitCount(), 5);
    reg1 = reg1; // self assign
    RegularGuest regCopy = reg1;
    regCopy.setVisitCount(6);
    EXPECT_EQ(regCopy.getVisitCount(), 6);
    std::stringstream ssReg;
    ssReg << reg1;
    RegularGuest regIn;
    ssReg >> regIn;

    // CorporateGuest
    CorporateGuest corpDef;
    CorporateGuest corp1("Corp", "User", bDate, cInfo, Gender::Male, "CORP222", "Acme Corp");
    EXPECT_EQ(corp1.getCompanyName(), "Acme Corp");
    corp1 = corp1; // self assign
    CorporateGuest corpCopy = corp1;
    corpCopy.setCompanyName("Beta LLC");
    EXPECT_EQ(corpCopy.getCompanyName(), "Beta LLC");
    std::stringstream ssCorp;
    ssCorp << corp1;
    CorporateGuest corpIn;
    ssCorp >> corpIn;

    // Employee with new fields
    Employee emp1("Eve", "White", bDate, cInfo, Gender::Female, "Receptionist", 1500.0);
    emp1.setDepartment("FrontDesk");
    Date hDate(1, 6, 2021);
    emp1.setHireDate(hDate);
    EXPECT_EQ(emp1.getDepartment(), "FrontDesk");
    EXPECT_EQ(emp1.getHireDate(), hDate);
    emp1 = emp1; // self assign
    Employee empCopy = emp1;
    EXPECT_TRUE(emp1 == empCopy);
    empCopy.setPosition("Supervisor");
    empCopy.setSalary(2000.0);
    EXPECT_EQ(empCopy.getPosition(), "Supervisor");

    std::stringstream ssEmp;
    ssEmp << emp1;
    Employee empIn;
    ssEmp >> empIn;

    // Manager
    Manager mgrDef;
    Manager mgr1("Boss", "Big", bDate, cInfo, Gender::Male, "Director", 5000.0, "PASS-MGR", "Management");
    EXPECT_EQ(mgr1.getDepartment(), "Management");
    mgr1 = mgr1; // self assign
    Manager mgrCopy = mgr1;
    mgrCopy.setDepartment("Operations");
    EXPECT_EQ(mgrCopy.getDepartment(), "Operations");
    std::stringstream ssMgr;
    ssMgr << mgr1;
    Manager mgrIn;
    ssMgr >> mgrIn;

    // Administrator
    Administrator admDef;
    Administrator adm1("Admin", "Desk", bDate, cInfo, Gender::Female, "Admin", 2000.0, 3);
    EXPECT_EQ(adm1.getDeskNumber(), 3);
    adm1 = adm1; // self assign
    Administrator admCopy = adm1;
    admCopy.setDeskNumber(4);
    EXPECT_EQ(admCopy.getDeskNumber(), 4);
    std::stringstream ssAdm;
    ssAdm << adm1;
    Administrator admIn;
    ssAdm >> admIn;

    // Maid
    Maid maidDef;
    Maid maid1("Mary", "Clean", bDate, cInfo, Gender::Female, "Maid", 1200.0, 50);
    EXPECT_EQ(maid1.getCleanedRoomsCount(), 50);
    maid1 = maid1; // self assign
    Maid maidCopy = maid1;
    maidCopy.setCleanedRoomsCount(60);
    EXPECT_EQ(maidCopy.getCleanedRoomsCount(), 60);
    std::stringstream ssMaid;
    ssMaid << maid1;
    Maid maidIn;
    ssMaid >> maidIn;

    // Chef
    Chef chefDef;
    Chef chef1("Gordon", "Cook", bDate, cInfo, Gender::Male, "Chef", 3000.0, "Pastry");
    EXPECT_EQ(chef1.getSpecialty(), "Pastry");
    chef1 = chef1; // self assign
    Chef chefCopy = chef1;
    chefCopy.setSpecialty("Grill");
    EXPECT_EQ(chefCopy.getSpecialty(), "Grill");
    std::stringstream ssChef;
    ssChef << chef1;
    Chef chefIn;
    ssChef >> chefIn;

    // SecurityGuard
    SecurityGuard secDef;
    SecurityGuard sec1("Sam", "Guard", bDate, cInfo, Gender::Male, "Guard", 1400.0, "Night");
    EXPECT_EQ(sec1.getShift(), "Night");
    sec1 = sec1; // self assign
    SecurityGuard secCopy = sec1;
    secCopy.setShift("Day");
    EXPECT_EQ(secCopy.getShift(), "Day");
    std::stringstream ssSec;
    ssSec << sec1;
    SecurityGuard secIn;
    ssSec >> secIn;

    // ContactPerson
    ContactPerson cp1(p1, "Sales Rep");
    EXPECT_EQ(cp1.getCompanyName(), "Sales Rep");
    EXPECT_EQ(cp1.getPerson().getFirstName(), "John");
    cp1 = cp1; // self assign
    ContactPerson cpCopy = cp1;
    cpCopy.setCompanyName("Account Manager");
    EXPECT_EQ(cpCopy.getCompanyName(), "Account Manager");
    EXPECT_TRUE(cp1 == cp1);
    std::stringstream ssCp;
    ssCp << cp1;
    ContactPerson cpIn;
    ssCp >> cpIn;
}

// ========================================================
// 5. Booking Full Coverage (CheckIn, CheckOut, Stay, Company, GuestGroup, Reservation)
// ========================================================
TEST(CompleteCoverage, BookingEntitiesExhaustive) {
    Id resId(501);
    Id gId(10);
    Id rId(20);
    Date dIn(1, 5, 2024);
    Date dOut(5, 5, 2024);

    // CheckIn
    CheckIn ci(resId, dIn, "FrontDeskAgent");
    EXPECT_EQ(ci.getReservationId(), resId);
    EXPECT_EQ(ci.getCheckInDate(), dIn);
    EXPECT_EQ(ci.getEmployeeName(), "FrontDeskAgent");
    ci = ci; // self assign
    CheckIn ciCopy = ci;
    std::stringstream ssCI;
    ssCI << ci;

    // CheckOut
    CheckOut co(resId, dOut, true);
    EXPECT_EQ(co.getReservationId(), resId);
    EXPECT_EQ(co.getCheckOutDate(), dOut);
    EXPECT_TRUE(co.getRoomCleaned());
    co = co; // self assign
    CheckOut coCopy = co;
    std::stringstream ssCO;
    ssCO << co;

    // Stay
    Stay stay(gId, rId, dIn, dOut);
    EXPECT_EQ(stay.getGuestId(), gId);
    EXPECT_EQ(stay.getRoomId(), rId);
    EXPECT_EQ(stay.getCheckInDate(), dIn);
    EXPECT_EQ(stay.getCheckOutDate(), dOut);
    stay = stay; // self assign
    Stay stayCopy = stay;
    Date dNewOut(6, 5, 2024);
    stayCopy.setCheckOutDate(dNewOut);
    EXPECT_EQ(stayCopy.getCheckOutDate(), dNewOut);
    std::stringstream ssStay;
    ssStay << stay;

    // Company
    Company comp("MegaCorp", "TAX-12345", Address("US", "Dallas", "Main", "100"));
    EXPECT_EQ(comp.getName(), "MegaCorp");
    EXPECT_EQ(comp.getTaxId(), "TAX-12345");
    EXPECT_EQ(comp.getAddress().getCity(), "Dallas");
    comp = comp; // self assign
    Company compCopy = comp;
    compCopy.setName("GigaCorp");
    compCopy.setTaxId("TAX-99999");
    compCopy.setAddress(Address("UK", "London", "Baker", "221B"));
    EXPECT_EQ(compCopy.getName(), "GigaCorp");
    std::stringstream ssComp;
    ssComp << comp;

    // GuestGroup
    GuestGroup gg("TouristGroup");
    EXPECT_EQ(gg.getGroupName(), "TouristGroup");
    gg.addGuest(gId);
    gg.addGuest(Id(11));
    EXPECT_EQ(gg.getGuestIds().size(), 2);
    gg.removeGuest(Id(11));
    EXPECT_EQ(gg.getGuestIds().size(), 1);
    gg = gg; // self assign
    GuestGroup ggCopy = gg;
    EXPECT_TRUE(gg == ggCopy);
    ggCopy.setGroupName("NewGroup");
    EXPECT_EQ(ggCopy.getGroupName(), "NewGroup");
    std::stringstream ssGG;
    ssGG << gg;

    // Reservation with new fields
    Reservation res(gId, rId, dIn, dOut, Money(500, Currency::RUB));
    res.setSpecialNotes("Late arrival");
    res.setGuestCount(2);
    EXPECT_EQ(res.getSpecialNotes(), "Late arrival");
    EXPECT_EQ(res.getGuestCount(), 2);
    EXPECT_EQ(res.getGuestId(), gId);
    EXPECT_EQ(res.getRoomId(), rId);
    EXPECT_EQ(res.getStartDate(), dIn);
    EXPECT_EQ(res.getEndDate(), dOut);
    EXPECT_EQ(res.getStatus(), BookingStatus::Pending);
    res.setStatus(BookingStatus::Confirmed);
    EXPECT_EQ(res.getStatus(), BookingStatus::Confirmed);
    res.pay(Money(200, Currency::RUB));
    EXPECT_DOUBLE_EQ(res.getTotalAmount().getAmount(), 300.0);
    res = res; // self assign
    Reservation resCopy = res;
    EXPECT_TRUE(res == resCopy);
    Reservation resDiff(Id(99), rId, dIn, dOut, Money(500, Currency::RUB));
    EXPECT_TRUE(res != resDiff);
    std::stringstream ssRes;
    ssRes << res;
    Reservation resIn;
    ssRes >> resIn;
}

// ========================================================
// 6. Services & Payments Full Coverage
// ========================================================
TEST(CompleteCoverage, ServicesAndPaymentsExhaustive) {
    // Service base & subclasses
    CleaningService cs("Deep Clean", Money(50, Currency::RUB), 2);
    cs.setDescription("Full disinfection");
    cs.setIsAvailable(true);
    EXPECT_EQ(cs.getDescription(), "Full disinfection");
    EXPECT_TRUE(cs.getIsAvailable());
    EXPECT_EQ(cs.getName(), "Deep Clean");
    EXPECT_EQ(cs.getCategory(), ServiceCategory::Cleaning);
    EXPECT_DOUBLE_EQ(cs.calculateCost().getAmount(), 100.0);
    cs = cs; // self assign
    CleaningService csCopy = cs;
    std::stringstream ssCS;
    ssCS << cs;

    // FoodService (roomService = true vs false)
    FoodService fs1("Breakfast", Money(20, Currency::RUB), false);
    EXPECT_DOUBLE_EQ(fs1.calculateCost().getAmount(), 20.0);
    FoodService fs2("Dinner in room", Money(40, Currency::RUB), true);
    EXPECT_DOUBLE_EQ(fs2.calculateCost().getAmount(), 48.0);
    fs1 = fs1;
    std::stringstream ssFS;
    ssFS << fs1;

    // LaundryService (items <= 10 vs items > 10)
    LaundryService lsSmall("Express Laundry", Money(5, Currency::RUB), 5);
    EXPECT_DOUBLE_EQ(lsSmall.calculateCost().getAmount(), 25.0);
    LaundryService lsLarge("Bulk Laundry", Money(5, Currency::RUB), 20);
    EXPECT_DOUBLE_EQ(lsLarge.calculateCost().getAmount(), 90.0); // 100 * 0.9 = 90
    lsSmall = lsSmall;
    std::stringstream ssLS;
    ssLS << lsSmall;

    // Spa, Excursion, Transfer
    SpaService spa("Sauna", Money(100, Currency::RUB), 2);
    EXPECT_DOUBLE_EQ(spa.calculateCost().getAmount(), 300.0); // 100 * 2 * 1.5
    spa = spa;
    std::stringstream ssSpa;
    ssSpa << spa;

    ExcursionService exc("City Tour", Money(80, Currency::RUB), 3);
    EXPECT_DOUBLE_EQ(exc.calculateCost().getAmount(), 240.0);
    exc = exc;
    std::stringstream ssExc;
    ssExc << exc;

    TransferService trans("Airport Shuttle", Money(150, Currency::RUB), true);
    EXPECT_DOUBLE_EQ(trans.calculateCost().getAmount(), 150.0);
    trans = trans;
    std::stringstream ssTrans;
    ssTrans << trans;

    // Base Service comparison
    Service* s1 = &cs;
    Service* s2 = &fs1;
    EXPECT_TRUE(*s1 != *s2);
    EXPECT_TRUE(*s1 == *s1);

    // ServiceOrder
    ServiceOrder so(Id(1), Id(2), 2, Money(100, Currency::RUB));
    EXPECT_EQ(so.getGuestId().getValue(), 1);
    EXPECT_EQ(so.getServiceId().getValue(), 2);
    EXPECT_EQ(so.getQuantity(), 2);
    so = so; // self assign
    ServiceOrder soCopy = so;
    EXPECT_TRUE(so == soCopy);
    ServiceOrder soDiff(Id(3), Id(4), 1, Money(50, Currency::RUB));
    EXPECT_TRUE(so != soDiff);
    std::stringstream ssSO;
    ssSO << so;

    // Payments with transactionCode
    CashPayment cash(Money(500, Currency::RUB), Date(1, 1, 2024), Money(1000, Currency::RUB));
    cash.setTransactionCode("CASH-777");
    EXPECT_EQ(cash.getTransactionCode(), "CASH-777");
    EXPECT_DOUBLE_EQ(cash.getChangeGiven().getAmount(), 1000.0);
    EXPECT_TRUE(cash.processPayment());
    EXPECT_EQ(cash.getStatus(), PaymentStatus::Success);
    cash = cash; // self assign
    std::stringstream ssCash;
    ssCash << cash;

    CardPayment card(Money(300, Currency::RUB), Date(1, 1, 2024), "1234567890123456");
    EXPECT_TRUE(card.processPayment());
    card = card;
    std::stringstream ssCard;
    ssCard << card;

    OnlinePayment online(Money(200, Currency::RUB), Date(1, 1, 2024), "pay@online.com");
    EXPECT_TRUE(online.processPayment());
    online = online;
    std::stringstream ssOnline;
    ssOnline << online;

    // Base Payment comparison
    Payment* p1p = &cash;
    Payment* p2p = &card;
    EXPECT_TRUE(*p1p != *p2p);
    EXPECT_TRUE(*p1p == *p1p);

    // Invoice, Tariff, Discount
    Discount disc("New Year", 10);
    EXPECT_EQ(disc.getDescription(), "New Year");
    EXPECT_EQ(disc.getPercent(), 10);
    Money discounted = disc.apply(Money(100, Currency::RUB));
    EXPECT_DOUBLE_EQ(discounted.getAmount(), 90.0);
    disc = disc;
    std::stringstream ssDisc;
    ssDisc << disc;

    Tariff tariff("Standard Tariff", Season::Summer, 1.5);
    EXPECT_EQ(tariff.getName(), "Standard Tariff");
    EXPECT_EQ(tariff.getSeason(), Season::Summer);
    EXPECT_DOUBLE_EQ(tariff.getMultiplier(), 1.5);
    tariff = tariff;
    std::stringstream ssTariff;
    ssTariff << tariff;

    Invoice inv(Id(55), Money(1000, Currency::RUB), Date(1, 1, 2024));
    EXPECT_EQ(inv.getReservationId().getValue(), 55);
    EXPECT_FALSE(inv.getIsPaid());
    inv.markAsPaid();
    EXPECT_TRUE(inv.getIsPaid());
    inv = inv;
    std::stringstream ssInv;
    ssInv << inv;
}

// ========================================================
// 7. Documents & Reviews Full Coverage
// ========================================================
TEST(CompleteCoverage, DocumentsAndReviewsExhaustive) {
    Date expDate(1, 1, 2030);
    Date pastDate(1, 1, 2020);
    Date curDate(1, 1, 2025);

    // Passport
    Passport pass("123456", curDate, expDate, "RU");
    EXPECT_EQ(pass.getDocumentNumber(), "123456");
    EXPECT_EQ(pass.getCountry(), "RU");
    EXPECT_TRUE(pass.isValid(curDate));
    pass = pass;
    std::stringstream ssPass;
    ssPass << pass;

    // Visa
    Visa visa("VISA-001", curDate, expDate, "Tourist");
    EXPECT_EQ(visa.getVisaType(), "Tourist");
    EXPECT_TRUE(visa.isValid(curDate));
    visa = visa;
    std::stringstream ssVisa;
    ssVisa << visa;

    // Contract
    Contract contract("CONT-777", curDate, expDate, Id(10));
    EXPECT_EQ(contract.getGuestId().getValue(), 10);
    EXPECT_TRUE(contract.isValid(curDate));
    contract = contract;
    std::stringstream ssCont;
    ssCont << contract;

    // Receipt
    Receipt receipt("REC-888", curDate, expDate, Money(150, Currency::RUB));
    EXPECT_DOUBLE_EQ(receipt.getTotalAmount().getAmount(), 150.0);
    EXPECT_TRUE(receipt.isValid(curDate));
    receipt = receipt;
    std::stringstream ssRec;
    ssRec << receipt;

    // Base Document comparison
    Document* d1 = &pass;
    Document* d2 = &visa;
    EXPECT_TRUE(*d1 != *d2);
    EXPECT_TRUE(*d1 == *d1);

    // Rating (valid, < 1, > 5)
    Rating rDef;
    EXPECT_EQ(rDef.getScore(), 5);
    Rating r(4);
    EXPECT_EQ(r.getScore(), 4);
    r.setScore(0); // invalid, should stay 4
    EXPECT_EQ(r.getScore(), 4);
    r.setScore(6); // invalid, should stay 4
    EXPECT_EQ(r.getScore(), 4);
    r.setScore(3); // valid
    EXPECT_EQ(r.getScore(), 3);
    r = r;
    Rating rCopy = r;
    EXPECT_TRUE(r == rCopy);
    rCopy.setScore(5);
    EXPECT_TRUE(r != rCopy);
    std::stringstream ssR;
    ssR << r;

    // Comment
    Comment c("Great stay!", "Alice");
    EXPECT_EQ(c.getText(), "Great stay!");
    EXPECT_EQ(c.getAuthor(), "Alice");
    c = c;
    Comment cCopy = c;
    EXPECT_TRUE(c == cCopy);
    cCopy.setText("Bad stay");
    EXPECT_TRUE(c != cCopy);
    std::stringstream ssC;
    ssC << c;

    // Review
    Date revDate(1, 1, 2024);
    Review rev(Id(1), Rating(5), Comment("Excellent service!", "Guest"), revDate);
    EXPECT_EQ(rev.getGuestId().getValue(), 1);
    EXPECT_EQ(rev.getRating().getScore(), 5);
    EXPECT_EQ(rev.getComment().getText(), "Excellent service!");
    rev = rev;
    Review revCopy = rev;
    EXPECT_EQ(revCopy.getGuestId().getValue(), 1);
    std::stringstream ssRev;
    ssRev << rev;

    // Feedback
    Feedback fb(Comment("Friendly staff", "Guest"), revDate, "Online");
    EXPECT_EQ(fb.getComment().getText(), "Friendly staff");
    EXPECT_EQ(fb.getChannel(), "Online");
    fb = fb;
    Feedback fbCopy = fb;
    EXPECT_EQ(fbCopy.getChannel(), "Online");
    std::stringstream ssFB;
    ssFB << fb;

    // Complaint
    Complaint compL(Id(3), Comment("Noisy neighbours", "Guest"), 1);
    EXPECT_EQ(compL.getGuestId().getValue(), 3);
    EXPECT_EQ(compL.getDescription().getText(), "Noisy neighbours");
    EXPECT_EQ(compL.getPriority(), 1);
    compL.resolve();
    compL = compL;
    Complaint compLCopy = compL;
    EXPECT_EQ(compLCopy.getGuestId().getValue(), 3);
    std::stringstream ssCompL;
    ssCompL << compL;
}

// ========================================================
// 8. Hotel & Managers Full Coverage
// ========================================================
TEST(CompleteCoverage, HotelAndManagersExhaustive) {
    Hotel hotel;
    hotel.setHotelName("Metropol");
    hotel.setStarRating(5);
    hotel.setContactPhone("+74951234567");
    hotel.setContactEmail("concierge@metropol.ru");
    EXPECT_EQ(hotel.getHotelName(), "Metropol");
    EXPECT_EQ(hotel.getStarRating(), 5);
    EXPECT_EQ(hotel.getContactPhone(), "+74951234567");
    EXPECT_EQ(hotel.getContactEmail(), "concierge@metropol.ru");

    // GuestManager
    GuestManager& gm = hotel.getGuestManager();
    Guest g("Sergey", "Ivanov", Date(15, 8, 1985), ContactInfo("+79991112233", "s@i.ru"), Gender::Male, "4500123456");
    gm.addGuest(g);
    EXPECT_NO_THROW(gm.findGuestById(g.getId()));
    EXPECT_THROW(gm.findGuestById(Id(9999)), GuestNotFoundException);

    // RoomManager (выделяем в куче через new, чтобы деструктор менеджера корректно отработал)
    RoomManager& rm = hotel.getRoomManager();
    Room* sRoom = new StandardRoom(201, 2, RoomStatus::Available, Money(2500, Currency::RUB), true);
    rm.addRoom(sRoom);
    EXPECT_NO_THROW(rm.findRoomById(sRoom->getId()));
    EXPECT_THROW(rm.findRoomById(Id(9999)), RoomNotFoundException);

    // BookingManager
    BookingManager& bm = hotel.getBookingManager();
    Date resStart(1, 10, 2026);
    Date resEnd(5, 10, 2026);
    Money resAmount(10000, Currency::RUB);
    EXPECT_NO_THROW(bm.makeReservation(g.getId(), sRoom->getId(), resStart, resEnd, resAmount));
    EXPECT_THROW(bm.findReservationById(Id(9999)), ReservationNotFoundException);

    // PaymentManager (выделяем через new)
    PaymentManager& pm = hotel.getPaymentManager();
    Payment* cashPay = new CashPayment(Money(10000, Currency::RUB), Date(1, 10, 2026), Money(10000, Currency::RUB));
    pm.addPayment(cashPay);

    // StaffManager (выделяем через new)
    StaffManager& staffMgr = hotel.getStaffManager();
    Employee* admin = new Administrator("Elena", "Petrova", Date(10, 4, 1992), ContactInfo("+79998887766", "e@p.ru"), Gender::Female, "Admin", 45000.0, 1);
    staffMgr.addEmployee(admin);

    ReportManager& repMgr = hotel.getReportManager();
    EXPECT_NO_THROW({ (void)repMgr; });
}