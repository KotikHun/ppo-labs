#pragma once
#include "Id.h"
#include "Money.h"
#include "Date.h"
#include <string>
#include <iostream>

/** @brief Invoice for payment. */
class Invoice {
private:
    Id id;
    Id reservationId;
    Money amount;
    Date issueDate;
    bool isPaid;

public:
    Invoice();
    Invoice(const Id& reservationId, const Money& amount, const Date& issueDate);
    Invoice(const Invoice& other);
    Invoice& operator=(const Invoice& other);
    ~Invoice();

    Id getId() const;
    Id getReservationId() const;
    Money getAmount() const;
    Date getIssueDate() const;
    bool getIsPaid() const;

    void markAsPaid();

    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Invoice& i);
};