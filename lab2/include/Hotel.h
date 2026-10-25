#pragma once

#include "Logger.h"
#include "GuestManager.h"
#include "RoomManager.h"
#include "BookingManager.h"
#include "ServiceManager.h"
#include "PaymentManager.h"
#include "StaffManager.h"
#include "ReportManager.h"
#include <string>

/**
 * @brief Facade class representing the whole hotel.
 *
 * Inherits privately from Logger (implementation detail).
 */
class Hotel : private Logger {
private:
    GuestManager guestMgr;
    RoomManager roomMgr;
    BookingManager bookingMgr;
    ServiceManager serviceMgr;
    PaymentManager paymentMgr;
    StaffManager staffMgr;
    ReportManager reportMgr;
    std::string hotelName;
    int starRating;
    std::string contactPhone;
    std::string contactEmail;

public:
    Hotel();
    ~Hotel();

    // Делаем метод log публичным с помощью using-директивы (по заданию)
    using Logger::log;

    // Геттеры для доступа к менеджерам (чтобы CLI мог с ними работать)
    GuestManager& getGuestManager();
    RoomManager& getRoomManager();
    BookingManager& getBookingManager();
    ServiceManager& getServiceManager();
    PaymentManager& getPaymentManager();
    StaffManager& getStaffManager();
    ReportManager& getReportManager();

    std::string getHotelName() const;
    void setHotelName(const std::string& name);
    int getStarRating() const;
    void setStarRating(int rating);
    std::string getContactPhone() const;
    void setContactPhone(const std::string& phone);
    std::string getContactEmail() const;
    void setContactEmail(const std::string& email);
};
