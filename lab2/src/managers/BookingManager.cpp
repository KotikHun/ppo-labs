#include "BookingManager.h"

using namespace std;

BookingManager::BookingManager() {
}

BookingManager::~BookingManager() {
}

void BookingManager::makeReservation(const Id& guestId, const Id& roomId, const Date& startDate, const Date& endDate, const Money& totalAmount) {
    // 1. Проверяем, не занят ли номер на эти даты
    for (size_t i = 0; i < reservations.size(); ++i) {
        // Если это тот же номер и статус не отменен
        if (reservations[i].getRoomId() == roomId && reservations[i].getStatus() != BookingStatus::Cancelled) {
            Date existingStart = reservations[i].getStartDate();
            Date existingEnd = reservations[i].getEndDate();

            // Проверка на пересечение интервалов
            bool isOverlap = (startDate <= existingEnd) && (endDate >= existingStart);
            
            if (isOverlap) {
                throw RoomAlreadyBookedException("Room is already booked for these dates.");
            }
        }
    }

    // 2. Если всё свободно, создаем бронь и добавляем в список
    Reservation newRes(guestId, roomId, startDate, endDate, totalAmount);
    reservations.push_back(newRes);
}

Reservation* BookingManager::findReservationById(const Id& id) {
    for (size_t i = 0; i < reservations.size(); ++i) {
        if (reservations[i].getId() == id) {
            return &reservations[i];
        }
    }
    throw ReservationNotFoundException("Reservation not found.");
}

void BookingManager::cancelReservation(const Id& id) {
    Reservation* res = findReservationById(id);
    res->setStatus(BookingStatus::Cancelled);
}

void BookingManager::printAllReservations() const {
    cout << "--- All Reservations ---" << endl;
    for (size_t i = 0; i < reservations.size(); ++i) {
        cout << reservations[i].toString() << endl;
    }
    cout << "------------------------" << endl;
}

size_t BookingManager::getReservationCount() const {
    return reservations.size();
}