#include "Date.h"
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
