#include <gtest/gtest.h>
#include "Invoice.h"

TEST(InvoiceTest, MarkPaid) {
    Invoice i(Id(1), Money(100, Currency::RUB), Date());
    EXPECT_FALSE(i.getIsPaid());
    i.markAsPaid();
    EXPECT_TRUE(i.getIsPaid());
}