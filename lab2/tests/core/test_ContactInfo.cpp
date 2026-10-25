#include <gtest/gtest.h>
#include "ContactInfo.h"

TEST(ContactInfoTest, Validation) {
    ContactInfo valid("+79991112233", "test@mail.com");
    EXPECT_TRUE(valid.isValid());

    ContactInfo invalidPhone("", "test@mail.com");
    EXPECT_FALSE(invalidPhone.isValid());

    ContactInfo invalidEmail("+7999", "invalid_email");
    EXPECT_FALSE(invalidEmail.isValid());
}