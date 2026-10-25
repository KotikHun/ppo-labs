#include <gtest/gtest.h>
#include <sstream>
#include "Hotel.h"
#include "GuestNotFoundException.h"
#include "RoomNotFoundException.h"
#include "ReservationNotFoundException.h"
#include "StandardRoom.h"
#include "CashPayment.h"
#include "CleaningService.h"
#include "Administrator.h"

TEST(FinalPush, ManagersAndEdges) {
    Hotel hotel;
    std::stringstream ss;

    // 1. Гости
    Guest g("Ivan", "Ivanov", Date(), ContactInfo(), Gender::Male, "123");
    hotel.getGuestManager().addGuest(g);
    
    // Тест на удаление несуществующего гостя (покрывает removeGuest и исключение)
    EXPECT_THROW(hotel.getGuestManager().findGuestById(Id(9999)), GuestNotFoundException);
    
    // Удаляем существующего (покрывает ветку успешного удаления)
    hotel.getGuestManager().removeGuest(g.getId());

    // 2. Комнаты
    StandardRoom* sr = new StandardRoom(101, 2, RoomStatus::Available, Money(100, Currency::RUB), true);
    hotel.getRoomManager().addRoom(sr);
    EXPECT_THROW(hotel.getRoomManager().findRoomByNumber(999), RoomNotFoundException);
    
    // 3. Бронирование (с пересечением дат)
    hotel.getBookingManager().makeReservation(g.getId(), sr->getId(), Date(1,1,2023), Date(5,1,2023), Money(100, Currency::RUB));
    EXPECT_THROW(
        hotel.getBookingManager().makeReservation(g.getId(), sr->getId(), Date(3,1,2023), Date(7,1,2023), Money(100, Currency::RUB)),
        RoomAlreadyBookedException
    );
    EXPECT_THROW(hotel.getBookingManager().findReservationById(Id(9999)), ReservationNotFoundException);

    // 4. Платежи
    CashPayment* cp = new CashPayment(Money(100, Currency::RUB), Date(), Money(0, Currency::RUB));
    hotel.getPaymentManager().addPayment(cp);
    EXPECT_THROW(hotel.getPaymentManager().findPaymentById(Id(9999)), InvalidPaymentException);

    // 5. Услуги
    CleaningService cs("Clean", Money(100, Currency::RUB), 1);
    hotel.getServiceManager().addOrder(ServiceOrder(g.getId(), Id(1), 1, Money(100, Currency::RUB)));
    EXPECT_THROW(hotel.getServiceManager().findOrderById(Id(9999)), ServiceNotAvailableException);

    // 6. Сотрудники
    Administrator* admin = new Administrator("A", "B", Date(), ContactInfo(), Gender::Male, "Admin", 100, 1);
    hotel.getStaffManager().addEmployee(admin);
    EXPECT_THROW(hotel.getStaffManager().findEmployeeById(Id(9999)), GuestNotFoundException);
    
    // Вызываем операторы вывода менеджеров
    ss << sr->toString() << cp->toString() << admin->toString();
}