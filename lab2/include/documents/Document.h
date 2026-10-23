#pragma once

#include "Id.h"
#include "Date.h"
#include <string>
#include <iostream>

/**
 * @brief Abstract base class for all documents.
 */
class Document {
protected:
    Id id;
    std::string documentNumber;
    Date issueDate;
    Date expiryDate;

public:
    Document();
    Document(const std::string& documentNumber, const Date& issueDate, const Date& expiryDate);
    Document(const Document& other);
    Document& operator=(const Document& other);
    virtual ~Document();

    Id getId() const;
    std::string getDocumentNumber() const;
    Date getIssueDate() const;
    Date getExpiryDate() const;

    void setDocumentNumber(const std::string& documentNumber);
    void setIssueDate(const Date& issueDate);
    void setExpiryDate(const Date& expiryDate);

    // Чисто виртуальный метод: проверка, действителен ли документ на текущую дату
    virtual bool isValid(const Date& currentDate) const = 0;

    virtual std::string toString() const;

    bool operator==(const Document& other) const;
    bool operator!=(const Document& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Document& d);
};