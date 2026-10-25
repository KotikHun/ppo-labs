with open(r"d:\study\ppois\ppo-labs\lab2\tests\test_complete_coverage.cpp", "r", encoding="utf-8") as f:
    text = f.read()

old_mgr = '''    // Manager
    Manager mgrDef;
    Manager mgr1("Boss", "Big", bDate, cInfo, Gender::Male, "Director", 5000.0, 10);
    EXPECT_EQ(mgr1.getSubordinatesCount(), 10);
    mgr1 = mgr1; // self assign
    Manager mgrCopy = mgr1;
    mgrCopy.setSubordinatesCount(15);
    EXPECT_EQ(mgrCopy.getSubordinatesCount(), 15);
    std::stringstream ssMgr;
    ssMgr << mgr1;
    Manager mgrIn;
    ssMgr >> mgrIn;'''

new_mgr = '''    // Manager
    Manager mgrDef;
    Manager mgr1("Boss", "Big", bDate, cInfo, Gender::Male, "Director", 5000.0, "PASS-MGR", "Management");
    EXPECT_EQ(mgr1.getDepartment(), "Management");
    mgr1 = mgr1; // self assign
    Manager mgrCopy = mgr1;
    mgrCopy.setDepartment("Operations");
    EXPECT_EQ(mgrCopy.getDepartment(), "Operations");
    std::stringstream ssMgr;
    ssMgr << mgr1;
    Manager mgrIn;
    ssMgr >> mgrIn;'''

old_cp = '''    // ContactPerson
    ContactPerson cp1("Agent", "Smith", cInfo, "Sales Rep");
    EXPECT_EQ(cp1.getName(), "Agent Smith");
    EXPECT_EQ(cp1.getRole(), "Sales Rep");
    cp1 = cp1; // self assign
    ContactPerson cpCopy = cp1;
    cpCopy.setRole("Account Manager");
    EXPECT_EQ(cpCopy.getRole(), "Account Manager");
    std::stringstream ssCp;
    ssCp << cp1;
    ContactPerson cpIn;
    ssCp >> cpIn;'''

new_cp = '''    // ContactPerson
    ContactPerson cp1(p1, "Sales Rep");
    EXPECT_EQ(cp1.getCompanyName(), "Sales Rep");
    EXPECT_EQ(cp1.getPerson().getFirstName(), "John");
    cp1 = cp1; // self assign
    ContactPerson cpCopy = cp1;
    cpCopy.setCompanyName("Account Manager");
    EXPECT_EQ(cpCopy.getCompanyName(), "Account Manager");
    EXPECT_TRUE(cp1 == cp1);
    EXPECT_TRUE(cp1 != cpCopy);
    std::stringstream ssCp;
    ssCp << cp1;
    ContactPerson cpIn;
    ssCp >> cpIn;'''

text = text.replace(old_mgr, new_mgr)
text = text.replace(old_cp, new_cp)

with open(r"d:\study\ppois\ppo-labs\lab2\tests\test_complete_coverage.cpp", "w", encoding="utf-8") as f:
    f.write(text)

print("Updated Manager and ContactPerson in test_complete_coverage.cpp")
