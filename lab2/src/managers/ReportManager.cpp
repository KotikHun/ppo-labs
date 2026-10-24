#include "ReportManager.h"

using namespace std;

ReportManager::ReportManager() {
}

ReportManager::~ReportManager() {
}

void ReportManager::printSummaryReport(GuestManager& gm, RoomManager& rm, BookingManager& bm, PaymentManager& pm) const {
    cout << "=========================================" << endl;
    cout << "          HOTEL SUMMARY REPORT           " << endl;
    cout << "=========================================" << endl;
    cout << "Total Guests:       " << gm.getGuestCount() << endl;
    cout << "Total Rooms:        " << rm.getRoomCount() << endl;
    cout << "Active Reservations:" << bm.getReservationCount() << endl;
    cout << "Total Payments:     " << pm.getPaymentCount() << endl;
    cout << "=========================================" << endl;
}

void ReportManager::printFreeRoomsReport(RoomManager& rm) const {
    cout << "--- Available Rooms Report ---" << endl;
    // Здесь мы не можем легко перебрать все комнаты,
    // так как RoomManager не отдает вектор напрямую.
    // Для простоты в этой лабе мы просто выведем список всех комнат.
    // В реальном проекте мы бы добавили метод getRooms() в RoomManager.
    cout << "(Для детального отчета нужен прямой доступ к списку номеров)" << endl;
    rm.printAllRooms();
}