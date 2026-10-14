#pragma once

#include <string>
#include <iostream>

/**
 * @brief Contact information (phone and email).
 *
 * Stores phone number and email address.
 * Provides basic validation of both fields.
 */
class ContactInfo {
private:
    std::string phone;
    std::string email;

public:
    ContactInfo();
    ContactInfo(const std::string& phone, const std::string& email);
    ContactInfo(const ContactInfo& other);
    ContactInfo& operator=(const ContactInfo& other);
    ~ContactInfo();

    std::string getPhone() const;
    std::string getEmail() const;

    void setPhone(const std::string& phone);
    void setEmail(const std::string& email);

    bool isValid() const;
    std::string toString() const;

    bool operator==(const ContactInfo& other) const;
    bool operator!=(const ContactInfo& other) const;
    bool operator<(const ContactInfo& other) const;
    bool operator>(const ContactInfo& other) const;

    friend std::ostream& operator<<(std::ostream& os, const ContactInfo& c);
    friend std::istream& operator>>(std::istream& is, ContactInfo& c);
};