#pragma once

#include <string>
#include <iostream>

/**
 * @brief Date (day, month, year).
 *
 * Stores day (1..31), month (1..12), year. Can validate itself,
 * compare with other dates, and add days.
 */
class Date {
private:
    int day;
    int month;
    int year;

    void addOneDay();
    void subOneDay();

public:
    Date();
    Date(int day, int month, int year);
    Date(const Date& other);
    Date& operator=(const Date& other);
    ~Date();

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    bool isLeapYear() const;
    bool isValid() const;

    int compare(const Date& other) const;
    std::string toString() const;
    Date addDays(int days) const;
    int daysBetween(const Date& other) const;

    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>=(const Date& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Date& d);
    friend std::istream& operator>>(std::istream& is, Date& d);
};