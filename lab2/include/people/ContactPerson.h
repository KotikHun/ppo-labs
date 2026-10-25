#pragma once

#include "Person.h"
#include <string>
#include <iostream>

/**
 * @brief Contact person from a partner company.
 *
 * Contains a Person as a field (composition) and adds company name.
 */
class ContactPerson {
private:
    Person person;
    std::string companyName;

public:
    ContactPerson();
    ContactPerson(const Person& person, const std::string& companyName);
    ContactPerson(const ContactPerson& other);
    ContactPerson& operator=(const ContactPerson& other);
    ~ContactPerson(); // Не виртуальный, так как нет наследников!

    Person getPerson() const;
    std::string getCompanyName() const;

    void setPerson(const Person& person);
    void setCompanyName(const std::string& companyName);

    std::string toString() const;

    bool operator==(const ContactPerson& other) const;
    bool operator!=(const ContactPerson& other) const;

    friend std::ostream& operator<<(std::ostream& os, const ContactPerson& cp);
    friend std::istream& operator>>(std::istream& is, ContactPerson& cp);
};