with open(r"d:\study\ppois\ppo-labs\lab2\tests\test_complete_coverage.cpp", "r", encoding="utf-8") as f:
    text = f.read()

# 1. Season::Summer
text = text.replace("Season::High", "Season::Summer")

# 2. inv.getIsPaid()
text = text.replace("inv.isPaid()", "inv.getIsPaid()")

# 3. Documents constructors
old_docs = '''    // Passport
    Passport pass("123456", "RU", expDate);
    EXPECT_EQ(pass.getNumber(), "123456");
    EXPECT_EQ(pass.getCountry(), "RU");
    EXPECT_EQ(pass.getType(), DocumentType::Passport);
    EXPECT_TRUE(pass.isValid(curDate));
    EXPECT_FALSE(pass.isValid(Date(1, 1, 2031)));
    pass = pass;
    std::stringstream ssPass;
    ssPass << pass;

    // Visa
    Visa visa("VISA-001", "RU", expDate, "Tourist");
    EXPECT_EQ(visa.getVisaType(), "Tourist");
    EXPECT_EQ(visa.getType(), DocumentType::Visa);
    EXPECT_TRUE(visa.isValid(curDate));
    visa = visa;
    std::stringstream ssVisa;
    ssVisa << visa;

    // Contract
    Contract contract("CONT-777", expDate, "Acme Corp");
    EXPECT_EQ(contract.getParty(), "Acme Corp");
    EXPECT_EQ(contract.getType(), DocumentType::Contract);
    EXPECT_TRUE(contract.isValid(curDate));
    contract = contract;
    std::stringstream ssCont;
    ssCont << contract;

    // Receipt
    Receipt receipt("REC-888", curDate, Money(150, Currency::RUB));
    EXPECT_DOUBLE_EQ(receipt.getAmount().getAmount(), 150.0);
    EXPECT_EQ(receipt.getType(), DocumentType::Receipt);
    EXPECT_TRUE(receipt.isValid(curDate));
    receipt = receipt;
    std::stringstream ssRec;
    ssRec << receipt;'''

new_docs = '''    // Passport
    Passport pass("123456", curDate, expDate, "RU");
    EXPECT_EQ(pass.getDocumentNumber(), "123456");
    EXPECT_EQ(pass.getCountry(), "RU");
    EXPECT_TRUE(pass.isValid(curDate));
    pass = pass;
    std::stringstream ssPass;
    ssPass << pass;

    // Visa
    Visa visa("VISA-001", curDate, expDate, "Tourist");
    EXPECT_EQ(visa.getVisaType(), "Tourist");
    EXPECT_TRUE(visa.isValid(curDate));
    visa = visa;
    std::stringstream ssVisa;
    ssVisa << visa;

    // Contract
    Contract contract("CONT-777", curDate, expDate, Id(10));
    EXPECT_EQ(contract.getGuestId().getValue(), 10);
    EXPECT_TRUE(contract.isValid(curDate));
    contract = contract;
    std::stringstream ssCont;
    ssCont << contract;

    // Receipt
    Receipt receipt("REC-888", curDate, expDate, Money(150, Currency::RUB));
    EXPECT_DOUBLE_EQ(receipt.getTotalAmount().getAmount(), 150.0);
    EXPECT_TRUE(receipt.isValid(curDate));
    receipt = receipt;
    std::stringstream ssRec;
    ssRec << receipt;'''

text = text.replace(old_docs, new_docs)

with open(r"d:\study\ppois\ppo-labs\lab2\tests\test_complete_coverage.cpp", "w", encoding="utf-8") as f:
    f.write(text)

print("Fixed Season, Invoice, and Documents in test_complete_coverage.cpp")
