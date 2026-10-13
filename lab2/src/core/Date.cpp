#include "Date.h"
#include <sstream>
#include <iomanip>

using namespace std;

Date::Date() : day(1), month(1), year(2000) {
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

bool Date::isLeapYear() const {
    if (year % 400 == 0) {
        return true;
    }
    if (year % 100 == 0) {
        return false;
    }
    return year % 4 == 0;
}

bool Date::isValid() const {
    if (month < 1 || month > 12) {
        return false;
    }
    if (year < 1) {
        return false;
    }
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[month - 1];
    if (month == 2 && isLeapYear()) {
        maxDay = 29;
    }
    return day >= 1 && day <= maxDay;
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
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[month - 1];
    if (month == 2 && isLeapYear()) {
        maxDay = 29;
    }
    day++;
    if (day > maxDay) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void Date::subOneDay() {
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int maxDay = daysInMonth[month - 1];
        if (month == 2 && isLeapYear()) {
            maxDay = 29;
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










