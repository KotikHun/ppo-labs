#pragma once

#include "Id.h"
#include "Date.h"
#include "ContactInfo.h"
#include "Gender.h"
#include <string>
#include <iostream>

/**
 * @brief Base class for all people in the hotel system.
 *
 * Stores common personal data: id, name, birth date, contacts, gender.
 * Serves as a base for Guest and Employee.
 */
class Person {
protected:
    std::string firstName;
    std::string lastName;
    Date birthDate;
    ContactInfo contacts;
    Gender gender;

private:
    Id id;

public:
    Person();
    Person(const std::string& firstName,
           const std::string& lastName,
           const Date& birthDate,
           const ContactInfo& contacts,
           Gender gender);
    Person(const Person& other);
    Person& operator=(const Person& other);
    virtual ~Person();

    std::string getFirstName() const;
    std::string getLastName() const;
    Date getBirthDate() const;
    ContactInfo getContacts() const;
    Gender getGender() const;
    Id getId() const;

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setBirthDate(const Date& birthDate);
    void setContacts(const ContactInfo& contacts);
    void setGender(Gender gender);

    virtual std::string toString() const;

    bool operator==(const Person& other) const;
    bool operator!=(const Person& other) const;
    bool operator<(const Person& other) const;
    bool operator>(const Person& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    friend std::istream& operator>>(std::istream& is, Person& p);






};







