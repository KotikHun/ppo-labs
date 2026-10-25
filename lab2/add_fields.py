import os

# 1. Hotel.h and Hotel.cpp
hotel_h = '''#pragma once

#include "Logger.h"
#include "GuestManager.h"
#include "RoomManager.h"
#include "BookingManager.h"
#include "ServiceManager.h"
#include "PaymentManager.h"
#include "StaffManager.h"
#include "ReportManager.h"
#include <string>

/**
 * @brief Facade class representing the whole hotel.
 *
 * Inherits privately from Logger (implementation detail).
 */
class Hotel : private Logger {
private:
    GuestManager guestMgr;
    RoomManager roomMgr;
    BookingManager bookingMgr;
    ServiceManager serviceMgr;
    PaymentManager paymentMgr;
    StaffManager staffMgr;
    ReportManager reportMgr;
    std::string hotelName;
    int starRating;
    std::string contactPhone;
    std::string contactEmail;

public:
    Hotel();
    ~Hotel();

    // Делаем метод log публичным с помощью using-директивы (по заданию)
    using Logger::log;

    // Геттеры для доступа к менеджерам (чтобы CLI мог с ними работать)
    GuestManager& getGuestManager();
    RoomManager& getRoomManager();
    BookingManager& getBookingManager();
    ServiceManager& getServiceManager();
    PaymentManager& getPaymentManager();
    StaffManager& getStaffManager();
    ReportManager& getReportManager();

    std::string getHotelName() const;
    void setHotelName(const std::string& name);
    int getStarRating() const;
    void setStarRating(int rating);
    std::string getContactPhone() const;
    void setContactPhone(const std::string& phone);
    std::string getContactEmail() const;
    void setContactEmail(const std::string& email);
};
'''

hotel_cpp = '''#include "Hotel.h"

using namespace std;

Hotel::Hotel()
    : hotelName("Grand Hotel"), starRating(5),
      contactPhone("+1234567890"), contactEmail("info@grandhotel.com") {
    log("Hotel system initialized.");
}

Hotel::~Hotel() {
    log("Hotel system shut down.");
}

GuestManager& Hotel::getGuestManager() { return guestMgr; }
RoomManager& Hotel::getRoomManager() { return roomMgr; }
BookingManager& Hotel::getBookingManager() { return bookingMgr; }
ServiceManager& Hotel::getServiceManager() { return serviceMgr; }
PaymentManager& Hotel::getPaymentManager() { return paymentMgr; }
StaffManager& Hotel::getStaffManager() { return staffMgr; }
ReportManager& Hotel::getReportManager() { return reportMgr; }

string Hotel::getHotelName() const { return hotelName; }
void Hotel::setHotelName(const string& name) { hotelName = name; }
int Hotel::getStarRating() const { return starRating; }
void Hotel::setStarRating(int rating) { starRating = rating; }
string Hotel::getContactPhone() const { return contactPhone; }
void Hotel::setContactPhone(const string& phone) { contactPhone = phone; }
string Hotel::getContactEmail() const { return contactEmail; }
void Hotel::setContactEmail(const string& email) { contactEmail = email; }
'''

with open(r"d:\study\ppois\ppo-labs\lab2\include\Hotel.h", "w", encoding="utf-8") as f:
    f.write(hotel_h)
with open(r"d:\study\ppois\ppo-labs\lab2\src\Hotel.cpp", "w", encoding="utf-8") as f:
    f.write(hotel_cpp)

# 2. Building.h and Building.cpp
building_h = '''#pragma once

#include "Address.h"
#include <string>
#include <iostream>

/**
 * @brief Represents a building in the hotel complex.
 */
class Building {
private:
    int number;
    std::string name;
    Address address;
    int floorsCount;
    int constructionYear;
    std::string description;

public:
    Building();
    Building(int number, const std::string& name, const Address& address, int floorsCount);
    Building(const Building& other);
    Building& operator=(const Building& other);
    ~Building();

    int getNumber() const;
    std::string getName() const;
    Address getAddress() const;
    int getFloorsCount() const;
    int getConstructionYear() const;
    std::string getDescription() const;

    void setNumber(int number);
    void setName(const std::string& name);
    void setAddress(const Address& address);
    void setFloorsCount(int floorsCount);
    void setConstructionYear(int year);
    void setDescription(const std::string& desc);

    std::string toString() const;

    bool operator==(const Building& other) const;
    bool operator!=(const Building& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Building& b);
    friend std::istream& operator>>(std::istream& is, Building& b);
};
'''

building_cpp = '''#include "Building.h"
#include <sstream>

using namespace std;

Building::Building()
    : number(1), name("Main"), address(), floorsCount(1),
      constructionYear(2020), description("Main building") {}

Building::Building(int number, const string& name, const Address& address, int floorsCount)
    : number(number), name(name), address(address), floorsCount(floorsCount),
      constructionYear(2020), description("Building") {}

Building::Building(const Building& other)
    : number(other.number), name(other.name), address(other.address),
      floorsCount(other.floorsCount), constructionYear(other.constructionYear),
      description(other.description) {}

Building& Building::operator=(const Building& other) {
    if (this == &other) return *this;
    number = other.number;
    name = other.name;
    address = other.address;
    floorsCount = other.floorsCount;
    constructionYear = other.constructionYear;
    description = other.description;
    return *this;
}

Building::~Building() {}

int Building::getNumber() const { return number; }
string Building::getName() const { return name; }
Address Building::getAddress() const { return address; }
int Building::getFloorsCount() const { return floorsCount; }
int Building::getConstructionYear() const { return constructionYear; }
string Building::getDescription() const { return description; }

void Building::setNumber(int number) { this->number = number; }
void Building::setName(const string& name) { this->name = name; }
void Building::setAddress(const Address& address) { this->address = address; }
void Building::setFloorsCount(int floorsCount) { this->floorsCount = floorsCount; }
void Building::setConstructionYear(int year) { this->constructionYear = year; }
void Building::setDescription(const string& desc) { this->description = desc; }

string Building::toString() const {
    stringstream ss;
    ss << "Building{" << number << ", " << name << ", floors=" << floorsCount << ", " << address.toString() << "}";
    return ss.str();
}

bool Building::operator==(const Building& other) const {
    return number == other.number && name == other.name && address == other.address && floorsCount == other.floorsCount;
}

bool Building::operator!=(const Building& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Building& b) { os << b.toString(); return os; }
istream& operator>>(istream& is, Building& b) {
    is >> b.number >> b.name >> b.address >> b.floorsCount;
    return is;
}
'''

with open(r"d:\study\ppois\ppo-labs\lab2\include\rooms\Building.h", "w", encoding="utf-8") as f:
    f.write(building_h)
with open(r"d:\study\ppois\ppo-labs\lab2\src\rooms\Building.cpp", "w", encoding="utf-8") as f:
    f.write(building_cpp)

# 3. Room.h and Room.cpp
room_h = '''#pragma once

#include "Id.h"
#include "Money.h"
#include "RoomCategory.h"
#include "RoomStatus.h"
#include <string>
#include <iostream>

/**
 * @brief Abstract base class for all hotel rooms.
 *
 * Cannot be instantiated because calculatePrice() is pure virtual.
 */
class Room {
protected:
    Id id;
    int roomNumber;
    int capacity;
    RoomCategory category;
    RoomStatus status;
    Money basePrice;
    double areaSquareMeters;
    int floorNumber;

public:
    Room();
    Room(int roomNumber, int capacity, RoomCategory category, RoomStatus status, const Money& basePrice);
    Room(const Room& other);
    Room& operator=(const Room& other);
    virtual ~Room();

    int getRoomNumber() const;
    int getCapacity() const;
    RoomCategory getCategory() const;
    RoomStatus getStatus() const;
    Money getBasePrice() const;
    Id getId() const;
    double getAreaSquareMeters() const;
    int getFloorNumber() const;

    void setRoomNumber(int roomNumber);
    void setCapacity(int capacity);
    void setCategory(RoomCategory category);
    void setStatus(RoomStatus status);
    void setBasePrice(const Money& basePrice);
    void setAreaSquareMeters(double area);
    void setFloorNumber(int floor);

    virtual Money calculatePrice() const = 0;
    virtual std::string toString() const;

    bool operator==(const Room& other) const;
    bool operator!=(const Room& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Room& r);
    friend std::istream& operator>>(std::istream& is, Room& r);
};
'''

room_cpp = '''#include "Room.h"
#include <sstream>

using namespace std;

Room::Room()
    : roomNumber(0), capacity(0), category(RoomCategory::Standard),
      status(RoomStatus::Available), basePrice(), areaSquareMeters(25.0), floorNumber(1) {
}

Room::Room(int roomNumber, int capacity, RoomCategory category, RoomStatus status, const Money& basePrice)
    : roomNumber(roomNumber), capacity(capacity), category(category),
      status(status), basePrice(basePrice), areaSquareMeters(25.0), floorNumber(1) {
}

Room::Room(const Room& other)
    : id(other.id), roomNumber(other.roomNumber), capacity(other.capacity),
      category(other.category), status(other.status), basePrice(other.basePrice),
      areaSquareMeters(other.areaSquareMeters), floorNumber(other.floorNumber) {
}

Room& Room::operator=(const Room& other) {
    if (this == &other) {
        return *this;
    }
    id = other.id;
    roomNumber = other.roomNumber;
    capacity = other.capacity;
    category = other.category;
    status = other.status;
    basePrice = other.basePrice;
    areaSquareMeters = other.areaSquareMeters;
    floorNumber = other.floorNumber;
    return *this;
}

Room::~Room() {
}

int Room::getRoomNumber() const { return roomNumber; }
int Room::getCapacity() const { return capacity; }
RoomCategory Room::getCategory() const { return category; }
RoomStatus Room::getStatus() const { return status; }
Money Room::getBasePrice() const { return basePrice; }
Id Room::getId() const { return id; }
double Room::getAreaSquareMeters() const { return areaSquareMeters; }
int Room::getFloorNumber() const { return floorNumber; }

void Room::setRoomNumber(int roomNumber) { this->roomNumber = roomNumber; }
void Room::setCapacity(int capacity) { this->capacity = capacity; }
void Room::setCategory(RoomCategory category) { this->category = category; }
void Room::setStatus(RoomStatus status) { this->status = status; }
void Room::setBasePrice(const Money& basePrice) { this->basePrice = basePrice; }
void Room::setAreaSquareMeters(double area) { this->areaSquareMeters = area; }
void Room::setFloorNumber(int floor) { this->floorNumber = floor; }

string Room::toString() const {
    stringstream ss;
    ss << "Room{id=" << id.toString()
       << ", number=" << roomNumber
       << ", capacity=" << capacity
       << ", basePrice=" << basePrice.toString() << "}";
    return ss.str();
}

bool Room::operator==(const Room& other) const { return id == other.id; }
bool Room::operator!=(const Room& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Room& r) {
    os << r.toString();
    return os;
}

istream& operator>>(istream& is, Room& r) {
    int num, cap;
    is >> num >> cap;
    r.setRoomNumber(num);
    r.setCapacity(cap);
    return is;
}
'''

with open(r"d:\study\ppois\ppo-labs\lab2\include\rooms\Room.h", "w", encoding="utf-8") as f:
    f.write(room_h)
with open(r"d:\study\ppois\ppo-labs\lab2\src\rooms\Room.cpp", "w", encoding="utf-8") as f:
    f.write(room_cpp)

# 4. Guest.h and Guest.cpp
guest_h = '''#pragma once

#include "Person.h"
#include <string>
#include <iostream>

/**
 * @brief Guest of the hotel.
 *
 * Inherits from Person and adds passport data and loyalty points.
 */
class Guest : virtual public Person {
protected:
    std::string passportNumber;
    int loyaltyPoints;
    std::string preferredLanguage;
    std::string notes;

public:
    Guest();
    Guest(const std::string& firstName,
          const std::string& lastName,
          const Date& birthDate,
          const ContactInfo& contacts,
          Gender gender,
          const std::string& passportNumber);
    Guest(const Guest& other);
    Guest& operator=(const Guest& other);
    virtual ~Guest();

    std::string getPassportNumber() const;
    int getLoyaltyPoints() const;
    std::string getPreferredLanguage() const;
    std::string getNotes() const;

    void setPassportNumber(const std::string& passportNumber);
    void setLoyaltyPoints(int loyaltyPoints);
    void setPreferredLanguage(const std::string& lang);
    void setNotes(const std::string& n);

    void addLoyaltyPoints(int points);

    std::string toString() const override;

    bool operator==(const Guest& other) const;
    bool operator!=(const Guest& other) const;
    bool operator<(const Guest& other) const;
    bool operator>(const Guest& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Guest& g);
    friend std::istream& operator>>(std::istream& is, Guest& g);
};
'''

guest_cpp = '''#include "Guest.h"
#include <sstream>

using namespace std;

Guest::Guest()
    : Person(), passportNumber(""), loyaltyPoints(0),
      preferredLanguage("en"), notes("") {
}

Guest::Guest(const string& firstName,
             const string& lastName,
             const Date& birthDate,
             const ContactInfo& contacts,
             Gender gender,
             const string& passportNumber)
    : Person(firstName, lastName, birthDate, contacts, gender),
      passportNumber(passportNumber),
      loyaltyPoints(0), preferredLanguage("en"), notes("") {
}

Guest::Guest(const Guest& other)
    : Person(other),
      passportNumber(other.passportNumber),
      loyaltyPoints(other.loyaltyPoints),
      preferredLanguage(other.preferredLanguage),
      notes(other.notes) {
}

Guest& Guest::operator=(const Guest& other) {
    if (this == &other) {
        return *this;
    }
    Person::operator=(other);
    passportNumber = other.passportNumber;
    loyaltyPoints = other.loyaltyPoints;
    preferredLanguage = other.preferredLanguage;
    notes = other.notes;
    return *this;
}

Guest::~Guest() {}

string Guest::getPassportNumber() const { return passportNumber; }
int Guest::getLoyaltyPoints() const { return loyaltyPoints; }
string Guest::getPreferredLanguage() const { return preferredLanguage; }
string Guest::getNotes() const { return notes; }

void Guest::setPassportNumber(const string& passportNumber) {
    this->passportNumber = passportNumber;
}

void Guest::setLoyaltyPoints(int loyaltyPoints) {
    this->loyaltyPoints = loyaltyPoints;
}

void Guest::setPreferredLanguage(const string& lang) {
    this->preferredLanguage = lang;
}

void Guest::setNotes(const string& n) {
    this->notes = n;
}

void Guest::addLoyaltyPoints(int points) {
    loyaltyPoints += points;
}

string Guest::toString() const {
    stringstream ss;
    ss << "Guest{" << Person::toString()
       << ", passport=" << passportNumber
       << ", points=" << loyaltyPoints << "}";
    return ss.str();
}

bool Guest::operator==(const Guest& other) const { return id == other.id; }
bool Guest::operator!=(const Guest& other) const { return !(*this == other); }
bool Guest::operator<(const Guest& other) const { return loyaltyPoints < other.loyaltyPoints; }
bool Guest::operator>(const Guest& other) const { return loyaltyPoints > other.loyaltyPoints; }

ostream& operator<<(ostream& os, const Guest& g) {
    os << g.toString();
    return os;
}

istream& operator>>(istream& is, Guest& g) {
    string fn, ln, pass;
    is >> fn >> ln >> pass;
    g.setFirstName(fn);
    g.setLastName(ln);
    g.setPassportNumber(pass);
    return is;
}
'''

with open(r"d:\study\ppois\ppo-labs\lab2\include\people\Guest.h", "w", encoding="utf-8") as f:
    f.write(guest_h)
with open(r"d:\study\ppois\ppo-labs\lab2\src\people\Guest.cpp", "w", encoding="utf-8") as f:
    f.write(guest_cpp)

# 5. Employee.h and Employee.cpp
employee_h = '''#pragma once

#include "Person.h"
#include <string>
#include <iostream>

/**
 * @brief Base class for hotel employees.
 *
 * Inherits from Person using protected inheritance, so the fact that
 * Employee is a Person is hidden from the outside world.
 */
class Employee : virtual protected Person {
protected:
    std::string position;
    double salary;
    std::string department;
    Date hireDate;

public:
    Employee();
    Employee(const std::string& firstName,
             const std::string& lastName,
             const Date& birthDate,
             const ContactInfo& contacts,
             Gender gender,
             const std::string& position,
             double salary);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    virtual ~Employee();

    std::string getPosition() const;
    double getSalary() const;
    std::string getDepartment() const;
    Date getHireDate() const;

    Id getId() const;

    void setPosition(const std::string& position);
    void setSalary(double salary);
    void setDepartment(const std::string& dept);
    void setHireDate(const Date& date);

    std::string toString() const override;

    bool operator==(const Employee& other) const;
    bool operator!=(const Employee& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Employee& e);
    friend std::istream& operator>>(std::istream& is, Employee& e);
};
'''

employee_cpp = '''#include "Employee.h"
#include <sstream>

using namespace std;

Employee::Employee()
    : Person(), position(""), salary(0.0), department("General"), hireDate() {
}

Employee::Employee(const string& firstName,
                   const string& lastName,
                   const Date& birthDate,
                   const ContactInfo& contacts,
                   Gender gender,
                   const string& position,
                   double salary)
    : Person(firstName, lastName, birthDate, contacts, gender),
      position(position), salary(salary), department("General"), hireDate() {
}

Employee::Employee(const Employee& other)
    : Person(other),
      position(other.position), salary(other.salary),
      department(other.department), hireDate(other.hireDate) {
}

Employee& Employee::operator=(const Employee& other) {
    if (this == &other) {
        return *this;
    }
    Person::operator=(other);
    position = other.position;
    salary = other.salary;
    department = other.department;
    hireDate = other.hireDate;
    return *this;
}

Employee::~Employee() {}

string Employee::getPosition() const { return position; }
double Employee::getSalary() const { return salary; }
string Employee::getDepartment() const { return department; }
Date Employee::getHireDate() const { return hireDate; }
Id Employee::getId() const { return id; }

void Employee::setPosition(const string& position) { this->position = position; }
void Employee::setSalary(double salary) { this->salary = salary; }
void Employee::setDepartment(const string& dept) { this->department = dept; }
void Employee::setHireDate(const Date& date) { this->hireDate = date; }

string Employee::toString() const {
    stringstream ss;
    ss << "Employee{" << Person::toString()
       << ", position=" << position
       << ", salary=" << salary << "}";
    return ss.str();
}

bool Employee::operator==(const Employee& other) const { return id == other.id; }
bool Employee::operator!=(const Employee& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Employee& e) {
    os << e.toString();
    return os;
}

istream& operator>>(istream& is, Employee& e) {
    string pos;
    double sal;
    is >> pos >> sal;
    e.setPosition(pos);
    e.setSalary(sal);
    return is;
}
'''

with open(r"d:\study\ppois\ppo-labs\lab2\include\people\Employee.h", "w", encoding="utf-8") as f:
    f.write(employee_h)
with open(r"d:\study\ppois\ppo-labs\lab2\src\people\Employee.cpp", "w", encoding="utf-8") as f:
    f.write(employee_cpp)

# 6. Reservation.h and Reservation.cpp
res_h = '''#pragma once

#include "Payable.h"
#include "Bookable.h"
#include "Id.h"
#include "Date.h"
#include "Money.h"
#include "BookingStatus.h"
#include <string>
#include <iostream>

/**
 * @brief Represents a room reservation.
 *
 * Inherits from Payable and Bookable interfaces.
 */
class Reservation : public Payable, public Bookable {
protected:
    Id id;
    Id guestId;
    Id roomId;
    Date startDate;
    Date endDate;
    Money totalAmount;
    BookingStatus status;
    std::string specialNotes;
    int guestCount;

public:
    Reservation();
    Reservation(const Id& guestId, const Id& roomId, const Date& startDate, const Date& endDate, const Money& totalAmount);
    Reservation(const Reservation& other);
    Reservation& operator=(const Reservation& other);
    virtual ~Reservation();

    Id getId() const;
    Id getGuestId() const;
    Id getRoomId() const;
    BookingStatus getStatus() const;
    std::string getSpecialNotes() const;
    int getGuestCount() const;

    void setStatus(BookingStatus status);
    void setSpecialNotes(const std::string& notes);
    void setGuestCount(int count);

    // Реализация методов интерфейса Bookable
    Date getStartDate() const override;
    Date getEndDate() const override;

    // Реализация методов интерфейса Payable
    Money getTotalAmount() const override;
    void pay(const Money& amount) override;

    virtual std::string toString() const;

    bool operator==(const Reservation& other) const;
    bool operator!=(const Reservation& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Reservation& r);
    friend std::istream& operator>>(std::istream& is, Reservation& r);
};
'''

res_cpp = '''#include "Reservation.h"
#include <sstream>

using namespace std;

Reservation::Reservation()
    : startDate(), endDate(), totalAmount(), status(BookingStatus::Pending),
      specialNotes(""), guestCount(1) {
}

Reservation::Reservation(const Id& guestId, const Id& roomId, const Date& startDate, const Date& endDate, const Money& totalAmount)
    : guestId(guestId), roomId(roomId), startDate(startDate), endDate(endDate), totalAmount(totalAmount),
      status(BookingStatus::Pending), specialNotes(""), guestCount(1) {
}

Reservation::Reservation(const Reservation& other)
    : id(other.id), guestId(other.guestId), roomId(other.roomId),
      startDate(other.startDate), endDate(other.endDate),
      totalAmount(other.totalAmount), status(other.status),
      specialNotes(other.specialNotes), guestCount(other.guestCount) {
}

Reservation& Reservation::operator=(const Reservation& other) {
    if (this == &other) {
        return *this;
    }
    id = other.id;
    guestId = other.guestId;
    roomId = other.roomId;
    startDate = other.startDate;
    endDate = other.endDate;
    totalAmount = other.totalAmount;
    status = other.status;
    specialNotes = other.specialNotes;
    guestCount = other.guestCount;
    return *this;
}

Reservation::~Reservation() {}

Id Reservation::getId() const { return id; }
Id Reservation::getGuestId() const { return guestId; }
Id Reservation::getRoomId() const { return roomId; }
BookingStatus Reservation::getStatus() const { return status; }
string Reservation::getSpecialNotes() const { return specialNotes; }
int Reservation::getGuestCount() const { return guestCount; }

void Reservation::setStatus(BookingStatus status) { this->status = status; }
void Reservation::setSpecialNotes(const string& notes) { this->specialNotes = notes; }
void Reservation::setGuestCount(int count) { this->guestCount = count; }

Date Reservation::getStartDate() const { return startDate; }
Date Reservation::getEndDate() const { return endDate; }
Money Reservation::getTotalAmount() const { return totalAmount; }
void Reservation::pay(const Money& amount) {
    totalAmount = totalAmount.subtract(amount);
}

string Reservation::toString() const {
    stringstream ss;
    ss << "Reservation{id=" << id.toString()
       << ", guest=" << guestId.toString()
       << ", room=" << roomId.toString()
       << ", dates=" << startDate.toString() << "-" << endDate.toString()
       << ", amount=" << totalAmount.toString() << "}";
    return ss.str();
}

bool Reservation::operator==(const Reservation& other) const { return id == other.id; }
bool Reservation::operator!=(const Reservation& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Reservation& r) {
    os << r.toString();
    return os;
}

istream& operator>>(istream& is, Reservation& r) {
    int gId, rId;
    is >> gId >> rId;
    return is;
}
'''

with open(r"d:\study\ppois\ppo-labs\lab2\include\booking\Reservation.h", "w", encoding="utf-8") as f:
    f.write(res_h)
with open(r"d:\study\ppois\ppo-labs\lab2\src\booking\Reservation.cpp", "w", encoding="utf-8") as f:
    f.write(res_cpp)

# 7. Payment.h and Payment.cpp
payment_h = '''#pragma once

#include "Id.h"
#include "Money.h"
#include "PaymentStatus.h"
#include "Date.h"
#include <string>
#include <iostream>

/**
 * @brief Abstract base class for all payment methods.
 */
class Payment {
protected:
    Id id;
    Money amount;
    Date paymentDate;
    PaymentStatus status;
    std::string transactionCode;

public:
    Payment();
    Payment(const Money& amount, const Date& paymentDate);
    Payment(const Payment& other);
    Payment& operator=(const Payment& other);
    virtual ~Payment();

    Id getId() const;
    Money getAmount() const;
    Date getPaymentDate() const;
    PaymentStatus getStatus() const;
    std::string getTransactionCode() const;

    void setStatus(PaymentStatus status);
    void setTransactionCode(const std::string& code);

    virtual bool processPayment() = 0;
    virtual std::string toString() const;

    bool operator==(const Payment& other) const;
    bool operator!=(const Payment& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Payment& p);
};
'''

payment_cpp = '''#include "Payment.h"
#include <sstream>

using namespace std;

Payment::Payment()
    : amount(), paymentDate(), status(PaymentStatus::Pending), transactionCode("TXN-000") {}

Payment::Payment(const Money& amount, const Date& paymentDate)
    : amount(amount), paymentDate(paymentDate), status(PaymentStatus::Pending), transactionCode("TXN-000") {}

Payment::Payment(const Payment& other)
    : id(other.id), amount(other.amount), paymentDate(other.paymentDate),
      status(other.status), transactionCode(other.transactionCode) {}

Payment& Payment::operator=(const Payment& other) {
    if (this == &other) return *this;
    id = other.id;
    amount = other.amount;
    paymentDate = other.paymentDate;
    status = other.status;
    transactionCode = other.transactionCode;
    return *this;
}

Payment::~Payment() {}

Id Payment::getId() const { return id; }
Money Payment::getAmount() const { return amount; }
Date Payment::getPaymentDate() const { return paymentDate; }
PaymentStatus Payment::getStatus() const { return status; }
string Payment::getTransactionCode() const { return transactionCode; }

void Payment::setStatus(PaymentStatus status) { this->status = status; }
void Payment::setTransactionCode(const string& code) { this->transactionCode = code; }

string Payment::toString() const {
    stringstream ss;
    ss << "Payment{id=" << id.toString() << ", amount=" << amount.toString()
       << ", date=" << paymentDate.toString() << "}";
    return ss.str();
}

bool Payment::operator==(const Payment& other) const { return id == other.id; }
bool Payment::operator!=(const Payment& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Payment& p) {
    os << p.toString();
    return os;
}
'''

with open(r"d:\study\ppois\ppo-labs\lab2\include\payments\Payment.h", "w", encoding="utf-8") as f:
    f.write(payment_h)
with open(r"d:\study\ppois\ppo-labs\lab2\src\payments\Payment.cpp", "w", encoding="utf-8") as f:
    f.write(payment_cpp)

# 8. Service.h and Service.cpp
service_h = '''#pragma once

#include "Id.h"
#include "Money.h"
#include "ServiceCategory.h"
#include <string>
#include <iostream>

/**
 * @brief Abstract base class for hotel services.
 */
class Service {
protected:
    Id id;
    std::string name;
    ServiceCategory category;
    Money baseCost;
    std::string description;
    bool isAvailable;

public:
    Service();
    Service(const std::string& name, ServiceCategory category, const Money& baseCost);
    Service(const Service& other);
    Service& operator=(const Service& other);
    virtual ~Service();

    Id getId() const;
    std::string getName() const;
    ServiceCategory getCategory() const;
    Money getBaseCost() const;
    std::string getDescription() const;
    bool getIsAvailable() const;

    void setName(const std::string& name);
    void setCategory(ServiceCategory category);
    void setBaseCost(const Money& baseCost);
    void setDescription(const std::string& desc);
    void setIsAvailable(bool available);

    virtual Money calculateCost() const = 0;
    virtual std::string toString() const;

    bool operator==(const Service& other) const;
    bool operator!=(const Service& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Service& s);
};
'''

service_cpp = '''#include "Service.h"
#include <sstream>

using namespace std;

Service::Service()
    : name(""), category(ServiceCategory::Cleaning), baseCost(),
      description("Hotel service"), isAvailable(true) {}

Service::Service(const string& name, ServiceCategory category, const Money& baseCost)
    : name(name), category(category), baseCost(baseCost),
      description("Hotel service"), isAvailable(true) {}

Service::Service(const Service& other)
    : id(other.id), name(other.name), category(other.category),
      baseCost(other.baseCost), description(other.description),
      isAvailable(other.isAvailable) {}

Service& Service::operator=(const Service& other) {
    if (this == &other) return *this;
    id = other.id;
    name = other.name;
    category = other.category;
    baseCost = other.baseCost;
    description = other.description;
    isAvailable = other.isAvailable;
    return *this;
}

Service::~Service() {}

Id Service::getId() const { return id; }
string Service::getName() const { return name; }
ServiceCategory Service::getCategory() const { return category; }
Money Service::getBaseCost() const { return baseCost; }
string Service::getDescription() const { return description; }
bool Service::getIsAvailable() const { return isAvailable; }

void Service::setName(const string& name) { this->name = name; }
void Service::setCategory(ServiceCategory category) { this->category = category; }
void Service::setBaseCost(const Money& baseCost) { this->baseCost = baseCost; }
void Service::setDescription(const string& desc) { this->description = desc; }
void Service::setIsAvailable(bool available) { this->isAvailable = available; }

string Service::toString() const {
    stringstream ss;
    ss << "Service{id=" << id.toString() << ", name=" << name << ", cost=" << baseCost.toString() << "}";
    return ss.str();
}

bool Service::operator==(const Service& other) const { return id == other.id; }
bool Service::operator!=(const Service& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Service& s) {
    os << s.toString();
    return os;
}
'''

with open(r"d:\study\ppois\ppo-labs\lab2\include\services\Service.h", "w", encoding="utf-8") as f:
    f.write(service_h)
with open(r"d:\study\ppois\ppo-labs\lab2\src\services\Service.cpp", "w", encoding="utf-8") as f:
    f.write(service_cpp)

print("Added fields and methods successfully!")
