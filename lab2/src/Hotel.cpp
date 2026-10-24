#include "Hotel.h"

using namespace std;

Hotel::Hotel() {
    log("Hotel system initialized.");
}

Hotel::~Hotel() {
    log("Hotel system shut down.");
}

GuestManager& Hotel::getGuestManager() { return guestMgr; }
RoomManager& Hotel::getRoomManager() { return roomMgr; }
BookingManager& Hotel::getBookingManager() { return bookingMgr; }
ServiceManager& Hotel::getServiceManager() { return serviceMgr; }
PaymentManager& Hotel::getPaymentManager() { return paymentMgr; }
StaffManager& Hotel::getStaffManager() { return staffMgr; }
ReportManager& Hotel::getReportManager() { return reportMgr; }