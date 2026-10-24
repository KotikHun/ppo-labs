#pragma once

#include "Logger.h"
#include "GuestManager.h"
#include "RoomManager.h"
#include "BookingManager.h"
#include "ServiceManager.h"
#include "PaymentManager.h"
#include "StaffManager.h"
#include "ReportManager.h"

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
};