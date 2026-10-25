#include "Hotel.h"

using namespace std;

Hotel::Hotel()
    : hotelName("Grand Hotel"), starRating(5),
      contactPhone("+1234567890"), contactEmail("info@grandhotel.com") {
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

string Hotel::getHotelName() const { return hotelName; }
void Hotel::setHotelName(const string& name) { hotelName = name; }
int Hotel::getStarRating() const { return starRating; }
void Hotel::setStarRating(int rating) { starRating = rating; }
string Hotel::getContactPhone() const { return contactPhone; }
void Hotel::setContactPhone(const string& phone) { contactPhone = phone; }
string Hotel::getContactEmail() const { return contactEmail; }
void Hotel::setContactEmail(const string& email) { contactEmail = email; }
