#include <gtest/gtest.h>
#include "Tariff.h"

TEST(TariffTest, Apply) {
    Tariff t("Summer", Season::Summer, 1.5);
    EXPECT_DOUBLE_EQ(t.apply(Money(100, Currency::RUB)).getAmount(), 150.0);
}