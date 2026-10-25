# Fix magic numbers in C++ files

# 1. Discount.cpp
discount_cpp = '''#include "Discount.h"
#include <sstream>
using namespace std;

namespace {
constexpr double PERCENT_MAX = 100.0;
}

Discount::Discount() : description(""), percent(0) {}
Discount::Discount(const string& description, int percent)
    : description(description), percent(percent) {}
Discount::Discount(const Discount& other)
    : description(other.description), percent(other.percent) {}

Discount& Discount::operator=(const Discount& other) {
    if (this == &other) return *this;
    description = other.description;
    percent = other.percent;
    return *this;
}
Discount::~Discount() {}

string Discount::getDescription() const { return description; }
int Discount::getPercent() const { return percent; }

Money Discount::apply(const Money& amount) const {
    double factor = 1.0 - (percent / PERCENT_MAX);
    return amount.multiply(factor);
}

string Discount::toString() const {
    stringstream ss;
    ss << "Discount{" << description << ", " << percent << "%}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Discount& d) { os << d.toString(); return os; }
'''
with open(r"d:\study\ppois\ppo-labs\lab2\src\payments\Discount.cpp", "w", encoding="utf-8") as f:
    f.write(discount_cpp)

# 2. Rating.cpp
rating_cpp = '''#include "Rating.h"
#include <sstream>

using namespace std;

namespace {
constexpr int DEFAULT_RATING = 5;
constexpr int MIN_RATING = 1;
constexpr int MAX_RATING = 5;
}

Rating::Rating() : score(DEFAULT_RATING) {}
Rating::Rating(int score) : score(score) {}
Rating::Rating(const Rating& other) : score(other.score) {}

Rating& Rating::operator=(const Rating& other) {
    if (this == &other) return *this;
    score = other.score;
    return *this;
}
Rating::~Rating() {}

int Rating::getScore() const { return score; }

void Rating::setScore(int score) {
    if (score >= MIN_RATING && score <= MAX_RATING) {
        this->score = score;
    }
}

string Rating::toString() const {
    stringstream ss;
    ss << score << "/" << MAX_RATING;
    return ss.str();
}

bool Rating::operator==(const Rating& other) const { return score == other.score; }
bool Rating::operator!=(const Rating& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Rating& r) { os << r.toString(); return os; }
'''
with open(r"d:\study\ppois\ppo-labs\lab2\src\reviews\Rating.cpp", "w", encoding="utf-8") as f:
    f.write(rating_cpp)

# 3. Apartment.cpp
apt_cpp = '''#include "Apartment.h"
#include <sstream>
using namespace std;

namespace {
constexpr double APARTMENT_MULTIPLIER = 2.0;
}

Apartment::Apartment() : Room(), roomCount(1) {}
Apartment::Apartment(int roomNumber, int capacity, RoomStatus status, const Money& basePrice, int roomCount)
    : Room(roomNumber, capacity, RoomCategory::Apartment, status, basePrice), roomCount(roomCount) {}
Apartment::Apartment(const Apartment& other) : Room(other), roomCount(other.roomCount) {}
Apartment& Apartment::operator=(const Apartment& other) {
    if (this == &other) return *this;
    Room::operator=(other);
    roomCount = other.roomCount;
    return *this;
}
Apartment::~Apartment() {}
int Apartment::getRoomCount() const { return roomCount; }
void Apartment::setRoomCount(int roomCount) { this->roomCount = roomCount; }
Money Apartment::calculatePrice() const { return basePrice.multiply(APARTMENT_MULTIPLIER); }
string Apartment::toString() const {
    stringstream ss;
    ss << "Apartment{" << Room::toString() << ", rooms=" << roomCount << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Apartment& a) { os << a.toString(); return os; }
istream& operator>>(istream& is, Apartment& a) { is >> static_cast<Room&>(a) >> a.roomCount; return is; }
'''
with open(r"d:\study\ppois\ppo-labs\lab2\src\rooms\Apartment.cpp", "w", encoding="utf-8") as f:
    f.write(apt_cpp)

# 4. LuxRoom.cpp
lux_cpp = '''#include "LuxRoom.h"
#include <sstream>
using namespace std;

namespace {
constexpr double LUX_MULTIPLIER = 1.5;
}

LuxRoom::LuxRoom() : Room(), hasJacuzzi(false) {}
LuxRoom::LuxRoom(int roomNumber, int capacity, RoomStatus status, const Money& basePrice, bool hasJacuzzi)
    : Room(roomNumber, capacity, RoomCategory::Lux, status, basePrice), hasJacuzzi(hasJacuzzi) {}
LuxRoom::LuxRoom(const LuxRoom& other) : Room(other), hasJacuzzi(other.hasJacuzzi) {}
LuxRoom& LuxRoom::operator=(const LuxRoom& other) {
    if (this == &other) return *this;
    Room::operator=(other);
    hasJacuzzi = other.hasJacuzzi;
    return *this;
}
LuxRoom::~LuxRoom() {}
bool LuxRoom::getHasJacuzzi() const { return hasJacuzzi; }
void LuxRoom::setHasJacuzzi(bool hasJacuzzi) { this->hasJacuzzi = hasJacuzzi; }
Money LuxRoom::calculatePrice() const { return basePrice.multiply(LUX_MULTIPLIER); }
string LuxRoom::toString() const {
    stringstream ss;
    ss << "LuxRoom{" << Room::toString() << ", jacuzzi=" << (hasJacuzzi ? "yes" : "no") << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const LuxRoom& r) { os << r.toString(); return os; }
istream& operator>>(istream& is, LuxRoom& r) { is >> static_cast<Room&>(r) >> r.hasJacuzzi; return is; }
'''
with open(r"d:\study\ppois\ppo-labs\lab2\src\rooms\LuxRoom.cpp", "w", encoding="utf-8") as f:
    f.write(lux_cpp)

# 5. SuiteRoom.cpp
suite_cpp = '''#include "SuiteRoom.h"
#include <sstream>
using namespace std;

namespace {
constexpr double SUITE_MULTIPLIER = 3.0;
}

SuiteRoom::SuiteRoom() : Room(), hasBalcony(false) {}
SuiteRoom::SuiteRoom(int roomNumber, int capacity, RoomStatus status, const Money& basePrice, bool hasBalcony)
    : Room(roomNumber, capacity, RoomCategory::Suite, status, basePrice), hasBalcony(hasBalcony) {}
SuiteRoom::SuiteRoom(const SuiteRoom& other) : Room(other), hasBalcony(other.hasBalcony) {}
SuiteRoom& SuiteRoom::operator=(const SuiteRoom& other) {
    if (this == &other) return *this;
    Room::operator=(other);
    hasBalcony = other.hasBalcony;
    return *this;
}
SuiteRoom::~SuiteRoom() {}
bool SuiteRoom::getHasBalcony() const { return hasBalcony; }
void SuiteRoom::setHasBalcony(bool hasBalcony) { this->hasBalcony = hasBalcony; }
Money SuiteRoom::calculatePrice() const { return basePrice.multiply(SUITE_MULTIPLIER); }
string SuiteRoom::toString() const {
    stringstream ss;
    ss << "SuiteRoom{" << Room::toString() << ", balcony=" << (hasBalcony ? "yes" : "no") << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const SuiteRoom& r) { os << r.toString(); return os; }
istream& operator>>(istream& is, SuiteRoom& r) { is >> static_cast<Room&>(r) >> r.hasBalcony; return is; }
'''
with open(r"d:\study\ppois\ppo-labs\lab2\src\rooms\SuiteRoom.cpp", "w", encoding="utf-8") as f:
    f.write(suite_cpp)

# 6. FoodService.cpp
food_cpp = '''#include "FoodService.h"
#include <sstream>
using namespace std;

namespace {
constexpr double ROOM_SERVICE_MULTIPLIER = 1.2;
constexpr double REGULAR_SERVICE_MULTIPLIER = 1.0;
}

FoodService::FoodService() : Service(), isRoomService(false) {}
FoodService::FoodService(const string& name, const Money& baseCost, bool isRoomService)
    : Service(name, ServiceCategory::Food, baseCost), isRoomService(isRoomService) {}
FoodService::FoodService(const FoodService& other) : Service(other), isRoomService(other.isRoomService) {}
FoodService& FoodService::operator=(const FoodService& other) {
    if (this == &other) return *this;
    Service::operator=(other);
    isRoomService = other.isRoomService;
    return *this;
}
FoodService::~FoodService() {}
bool FoodService::getIsRoomService() const { return isRoomService; }
void FoodService::setIsRoomService(bool isRoomService) { this->isRoomService = isRoomService; }

Money FoodService::calculateCost() const {
    if (isRoomService) return baseCost.multiply(ROOM_SERVICE_MULTIPLIER);
    return baseCost.multiply(REGULAR_SERVICE_MULTIPLIER);
}

string FoodService::toString() const {
    stringstream ss;
    ss << "FoodService{" << Service::toString() << ", roomService=" << (isRoomService ? "yes" : "no") << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const FoodService& fs) { os << fs.toString(); return os; }
'''
with open(r"d:\study\ppois\ppo-labs\lab2\src\services\FoodService.cpp", "w", encoding="utf-8") as f:
    f.write(food_cpp)

# 7. LaundryService.cpp
laundry_cpp = '''#include "LaundryService.h"
#include <sstream>
using namespace std;

namespace {
constexpr int BULK_ITEMS_THRESHOLD = 10;
constexpr double BULK_DISCOUNT_FACTOR = 0.9;
}

LaundryService::LaundryService() : Service(), itemsCount(1) {}
LaundryService::LaundryService(const string& name, const Money& baseCost, int itemsCount)
    : Service(name, ServiceCategory::Laundry, baseCost), itemsCount(itemsCount) {}
LaundryService::LaundryService(const LaundryService& other) : Service(other), itemsCount(other.itemsCount) {}
LaundryService& LaundryService::operator=(const LaundryService& other) {
    if (this == &other) return *this;
    Service::operator=(other);
    itemsCount = other.itemsCount;
    return *this;
}
LaundryService::~LaundryService() {}
int LaundryService::getItemsCount() const { return itemsCount; }
void LaundryService::setItemsCount(int itemsCount) { this->itemsCount = itemsCount; }

Money LaundryService::calculateCost() const {
    Money cost = baseCost.multiply(itemsCount);
    if (itemsCount > BULK_ITEMS_THRESHOLD) return cost.multiply(BULK_DISCOUNT_FACTOR);
    return cost;
}

string LaundryService::toString() const {
    stringstream ss;
    ss << "LaundryService{" << Service::toString() << ", items=" << itemsCount << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const LaundryService& ls) { os << ls.toString(); return os; }
'''
with open(r"d:\study\ppois\ppo-labs\lab2\src\services\LaundryService.cpp", "w", encoding="utf-8") as f:
    f.write(laundry_cpp)

# 8. SpaService.cpp
spa_cpp = '''#include "SpaService.h"
#include <sstream>
using namespace std;

namespace {
constexpr double SPA_SURCHARGE_FACTOR = 1.5;
}

SpaService::SpaService() : Service(), hours(1) {}
SpaService::SpaService(const string& name, const Money& baseCost, int hours)
    : Service(name, ServiceCategory::Spa, baseCost), hours(hours) {}
SpaService::SpaService(const SpaService& other) : Service(other), hours(other.hours) {}
SpaService& SpaService::operator=(const SpaService& other) {
    if (this == &other) return *this;
    Service::operator=(other);
    hours = other.hours;
    return *this;
}
SpaService::~SpaService() {}
int SpaService::getHours() const { return hours; }
void SpaService::setHours(int hours) { this->hours = hours; }

Money SpaService::calculateCost() const { return baseCost.multiply(hours).multiply(SPA_SURCHARGE_FACTOR); }

string SpaService::toString() const {
    stringstream ss;
    ss << "SpaService{" << Service::toString() << ", hours=" << hours << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const SpaService& ss) { os << ss.toString(); return os; }
'''
with open(r"d:\study\ppois\ppo-labs\lab2\src\services\SpaService.cpp", "w", encoding="utf-8") as f:
    f.write(spa_cpp)

# 9. Date.cpp
date_cpp = '''#include "Date.h"
#include <sstream>
#include <iomanip>

using namespace std;

namespace {
constexpr int DEFAULT_DAY = 1;
constexpr int DEFAULT_MONTH = 1;
constexpr int DEFAULT_YEAR = 2000;
constexpr int LEAP_DIVISOR_400 = 400;
constexpr int LEAP_DIVISOR_100 = 100;
constexpr int LEAP_DIVISOR_4 = 4;
constexpr int MIN_MONTH = 1;
constexpr int MAX_MONTH = 12;
constexpr int MIN_YEAR = 1;
constexpr int MIN_DAY = 1;
constexpr int FEB_MONTH = 2;
constexpr int LEAP_FEB_DAYS = 29;
constexpr int DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
}

Date::Date() : day(DEFAULT_DAY), month(DEFAULT_MONTH), year(DEFAULT_YEAR) {
}

Date::Date(int day, int month, int year)
    : day(day), month(month), year(year) {
}

Date::Date(const Date& other)
    : day(other.day), month(other.month), year(other.year) {
}

Date& Date::operator=(const Date& other) {
    if (this == &other) {
        return *this;
    }
    day = other.day;
    month = other.month;
    year = other.year;
    return *this;
}

Date::~Date() {
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(int d) {
    day = d;
}

void Date::setMonth(int m) {
    month = m;
}

void Date::setYear(int y) {
    year = y;
}

bool Date::isLeapYear() const {
    if (year % LEAP_DIVISOR_400 == 0) {
        return true;
    }
    if (year % LEAP_DIVISOR_100 == 0) {
        return false;
    }
    return year % LEAP_DIVISOR_4 == 0;
}

bool Date::isValid() const {
    if (month < MIN_MONTH || month > MAX_MONTH) {
        return false;
    }
    if (year < MIN_YEAR) {
        return false;
    }
    int maxDay = DAYS_IN_MONTH[month - 1];
    if (month == FEB_MONTH && isLeapYear()) {
        maxDay = LEAP_FEB_DAYS;
    }
    return day >= MIN_DAY && day <= maxDay;
}

int Date::compare(const Date& other) const {
    if (year < other.year) {
        return -1;
    }
    if (year > other.year) {
        return 1;
    }
    if (month < other.month) {
        return -1;
    }
    if (month > other.month) {
        return 1;
    }
    if (day < other.day) {
        return -1;
    }
    if (day > other.day) {
        return 1;
    }
    return 0;
}

string Date::toString() const {
    stringstream ss;
    ss << setw(2) << setfill('0') << day << "."
       << setw(2) << setfill('0') << month << "."
       << year;
    return ss.str();
}

void Date::addOneDay() {
    int maxDay = DAYS_IN_MONTH[month - 1];
    if (month == FEB_MONTH && isLeapYear()) {
        maxDay = LEAP_FEB_DAYS;
    }
    day++;
    if (day > maxDay) {
        day = MIN_DAY;
        month++;
        if (month > MAX_MONTH) {
            month = MIN_MONTH;
            year++;
        }
    }
}

void Date::subOneDay() {
    day--;
    if (day < MIN_DAY) {
        month--;
        if (month < MIN_MONTH) {
            month = MAX_MONTH;
            year--;
        }
        int maxDay = DAYS_IN_MONTH[month - 1];
        if (month == FEB_MONTH && isLeapYear()) {
            maxDay = LEAP_FEB_DAYS;
        }
        day = maxDay;
    }
}

Date Date::addDays(int days) const {
    Date result = *this;
    if (days >= 0) {
        for (int i = 0; i < days; ++i) {
            result.addOneDay();
        }
    } else {
        for (int i = 0; i < -days; ++i) {
            result.subOneDay();
        }
    }
    return result;
}

bool Date::operator==(const Date& other) const {
    return day == other.day
        && month == other.month
        && year == other.year;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    return compare(other) < 0;
}

bool Date::operator>(const Date& other) const {
    return compare(other) > 0;
}

bool Date::operator<=(const Date& other) const {
    return !(*this > other);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}

int Date::daysBetween(const Date& other) const {
    Date from = *this;
    Date to = other;
    bool negative = false;

    if (compare(other) > 0) {
        from = other;
        to = *this;
        negative = true;
    }

    int count = 0;
    while (from != to) {
        from.addOneDay();
        count++;
    }

    return negative ? -count : count;
}

ostream& operator<<(ostream& os, const Date& d) {
    os << d.toString();
    return os;
}

istream& operator>>(istream& is, Date& d) {
    int day, month, year;
    is >> day >> month >> year;
    d = Date(day, month, year);
    return is;
}
'''
with open(r"d:\study\ppois\ppo-labs\lab2\src\core\Date.cpp", "w", encoding="utf-8") as f:
    f.write(date_cpp)

print("Magic numbers replaced successfully!")
