#include <gtest/gtest.h>
#include "Reservation.h"

TEST(ReservationTest, PaymentAndDates) {
    Reservation r(Id(1), Id(2), Date(1,1,2023), Date(5,1,2023), Money(1000, Currency::RUB));
    EXPECT_EQ(r.getStartDate(), Date(1,1,2023));
    EXPECT_EQ(r.getEndDate(), Date(5,1,2023));

    // Начальный статус после создания — Pending
    EXPECT_EQ(r.getStatus(), BookingStatus::Pending);

    // Оплата и явная смена статуса
    r.pay(Money(1000, Currency::RUB));
    r.setStatus(BookingStatus::Confirmed);
    EXPECT_EQ(r.getStatus(), BookingStatus::Confirmed);
}