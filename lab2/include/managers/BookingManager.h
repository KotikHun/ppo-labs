#pragma once

#include "Reservation.h"
#include "RoomAlreadyBookedException.h"
#include "ReservationNotFoundException.h"
#include <vector>
#include <iostream>

/**
 * @brief Manages room reservations.
 */
class BookingManager {
private:
    std::vector<Reservation> reservations;

public:
    BookingManager();
    ~BookingManager();

    // Создать новую бронь с проверкой на пересечение дат
    void makeReservation(const Id& guestId, const Id& roomId, const Date& startDate, const Date& endDate, const Money& totalAmount);
    
    Reservation* findReservationById(const Id& id);
    void cancelReservation(const Id& id);
    
    void printAllReservations() const;
    size_t getReservationCount() const;
};