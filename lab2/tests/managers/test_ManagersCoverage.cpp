#include <gtest/gtest.h>
#include "GuestManager.h"
#include "RoomManager.h"
#include "BookingManager.h"
#include "ServiceManager.h"
#include "PaymentManager.h"
#include "StaffManager.h"
#include "ReportManager.h"
#include "Hotel.h"
#include "StandardRoom.h"
#include "Guest.h"
#include "Administrator.h"
#include "CashPayment.h"

TEST(ManagersCoverage, AllMethods) {
    Hotel hotel;
    hotel.log("Init");

    // GuestManager
    Guest g("A", "B", Date(), ContactInfo(), Gender::Male, "123");
    hotel.getGuestManager().addGuest(g);
    hotel.getGuestManager().findGuestById(g.getId());
    hotel.getGuestManager().printAllGuests();
    hotel.getGuestManager().getGuestCount();

    // RoomManager
    StandardRoom* sr = new StandardRoom(101, 2, RoomStatus::Available, Money(100, Currency::RUB), true);
    hotel.getRoomManager().addRoom(sr);
    hotel.getRoomManager().findRoomById(sr->getId());
    hotel.getRoomManager().findRoomByNumber(101);
    hotel.getRoomManager().changeRoomStatus(sr->getId(), RoomStatus::Occupied);
    hotel.getRoomManager().printAllRooms();
    hotel.getRoomManager().getRoomCount();

    // BookingManager
    hotel.getBookingManager().makeReservation(g.getId(), sr->getId(), Date(1,1,2023), Date(5,1,2023), Money(100, Currency::RUB));

    // Проверяем, что поиск несуществующей брони бросает исключение
    EXPECT_THROW(hotel.getBookingManager().findReservationById(Id(999)), ReservationNotFoundException);

    hotel.getBookingManager().printAllReservations();

    // StaffManager
    Administrator* admin = new Administrator("A", "B", Date(), ContactInfo(), Gender::Male, "Admin", 100, 1);
    hotel.getStaffManager().addEmployee(admin);
    hotel.getStaffManager().findEmployeeById(admin->getId());
    hotel.getStaffManager().printAllEmployees();
    hotel.getStaffManager().removeEmployee(admin->getId());

    // ReportManager
    hotel.getReportManager().printSummaryReport(hotel.getGuestManager(), hotel.getRoomManager(), hotel.getBookingManager(), hotel.getPaymentManager());
    hotel.getReportManager().printFreeRoomsReport(hotel.getRoomManager());

    // Тестируем Сервисы и Платежи
    ServiceOrder so(Id(1), Id(2), 1, Money(100, Currency::RUB));
    hotel.getServiceManager().addOrder(so);
    hotel.getServiceManager().findOrderById(so.getId());
    hotel.getServiceManager().completeOrder(so.getId());
    hotel.getServiceManager().printAllOrders();
    hotel.getServiceManager().getOrderCount();

    CashPayment* cp = new CashPayment(Money(100, Currency::RUB), Date(), Money(0, Currency::RUB));
    hotel.getPaymentManager().addPayment(cp);
    hotel.getPaymentManager().findPaymentById(cp->getId());
    hotel.getPaymentManager().processPayment(cp->getId());
    hotel.getPaymentManager().printAllPayments();
    hotel.getPaymentManager().getPaymentCount();
}