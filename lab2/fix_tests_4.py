with open(r"d:\study\ppois\ppo-labs\lab2\tests\test_complete_coverage.cpp", "r", encoding="utf-8") as f:
    text = f.read()

# 1. CheckIn setEmployeeName
text = text.replace('    ciCopy.setEmployeeName("SeniorAgent");\n    EXPECT_EQ(ciCopy.getEmployeeName(), "SeniorAgent");\n', '')
text = text.replace('    ciCopy.setEmployeeName("SeniorAgent");\r\n    EXPECT_EQ(ciCopy.getEmployeeName(), "SeniorAgent");\r\n', '')

# 2. CheckOut setRoomCleaned
text = text.replace('    coCopy.setRoomCleaned(false);\n    EXPECT_FALSE(coCopy.getRoomCleaned());\n', '')
text = text.replace('    coCopy.setRoomCleaned(false);\r\n    EXPECT_FALSE(coCopy.getRoomCleaned());\r\n', '')

# 3. CashPayment getChange -> getChangeGiven, PaymentStatus::Success
text = text.replace('EXPECT_DOUBLE_EQ(cash.getChange().getAmount(), 500.0);',
                    'EXPECT_DOUBLE_EQ(cash.getChangeGiven().getAmount(), 500.0);')
text = text.replace('EXPECT_EQ(cash.getStatus(), PaymentStatus::Completed);',
                    'EXPECT_EQ(cash.getStatus(), PaymentStatus::Success);')

# 4. CardPayment
text = text.replace('CardPayment card(Money(300, Currency::RUB), Date(1, 1, 2024), "1234567890123456", "John Doe");',
                    'CardPayment card(Money(300, Currency::RUB), Date(1, 1, 2024), "1234567890123456");')

# 5. OnlinePayment
text = text.replace('OnlinePayment online(Money(200, Currency::RUB), Date(1, 1, 2024), "PayPal", "PAY-98765");',
                    'OnlinePayment online(Money(200, Currency::RUB), Date(1, 1, 2024), "pay@online.com");')

with open(r"d:\study\ppois\ppo-labs\lab2\tests\test_complete_coverage.cpp", "w", encoding="utf-8") as f:
    f.write(text)

print("Fixed payments and checkin/checkout in test_complete_coverage.cpp")
