#pragma once

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

    void setStatus(BookingStatus status);

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