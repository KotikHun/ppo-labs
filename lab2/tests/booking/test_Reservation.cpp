#include <gtest/gtest.h>
#include "Reservation.h"

TEST(ReservationTest, PaymentAndDates) {
    Reservation r(Id(1), Id(2), Date(1,1,2023), Date(5,1,2023), Money(1000, Currency::RUB));
    EXPECT_EQ(r.getStartDate(), Date(1,1,2023));
    EXPECT_EQ(r.getEndDate(), Date(5,1,2023));

    r.pay(Money(1000, Currency::RUB));
    EXPECT_EQ(r.getStatus(), BookingStatus::Confirmed);
}