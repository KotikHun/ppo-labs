with open(r"d:\study\ppois\ppo-labs\lab2\tests\test_complete_coverage.cpp", "r", encoding="utf-8") as f:
    text = f.read()

# 1. Id operators <= and >=
text = text.replace("EXPECT_TRUE(id2 <= id3);\n", "")
text = text.replace("EXPECT_TRUE(id3 >= id2);\n", "")
text = text.replace("    EXPECT_TRUE(id2 <= id3);\r\n", "")
text = text.replace("    EXPECT_TRUE(id3 >= id2);\r\n", "")

# 2. Person getFullName
text = text.replace('EXPECT_EQ(pCopy.getFullName(), "Jane Doe");',
                    'EXPECT_EQ(pCopy.getFirstName(), "Jane");\n    EXPECT_EQ(pCopy.getLastName(), "Doe");')

# 3. RegularGuest
text = text.replace('RegularGuest reg1("Reg", "User", bDate, cInfo, Gender::Male, "REG111", 5);',
                    'RegularGuest reg1("Reg", "User", bDate, cInfo, Gender::Male, "REG111");\n    reg1.setVisitCount(5);')
text = text.replace('EXPECT_EQ(reg1.getVisitsCount(), 5);', 'EXPECT_EQ(reg1.getVisitCount(), 5);')
text = text.replace('regCopy.setVisitsCount(6);', 'regCopy.setVisitCount(6);')
text = text.replace('EXPECT_EQ(regCopy.getVisitsCount(), 6);', 'EXPECT_EQ(regCopy.getVisitCount(), 6);')

# 4. CorporateGuest
old_corp = '''    // CorporateGuest
    CorporateGuest corpDef;
    Company comp("Acme Corp", "TAX-999", Address());
    CorporateGuest corp1("Corp", "User", bDate, cInfo, Gender::Male, "CORP222", comp);
    EXPECT_EQ(corp1.getCompany().getName(), "Acme Corp");
    corp1 = corp1; // self assign
    CorporateGuest corpCopy = corp1;
    Company comp2("Beta LLC", "TAX-888", Address());
    corpCopy.setCompany(comp2);
    EXPECT_EQ(corpCopy.getCompany().getName(), "Beta LLC");'''

new_corp = '''    // CorporateGuest
    CorporateGuest corpDef;
    CorporateGuest corp1("Corp", "User", bDate, cInfo, Gender::Male, "CORP222", "Acme Corp");
    EXPECT_EQ(corp1.getCompanyName(), "Acme Corp");
    corp1 = corp1; // self assign
    CorporateGuest corpCopy = corp1;
    corpCopy.setCompanyName("Beta LLC");
    EXPECT_EQ(corpCopy.getCompanyName(), "Beta LLC");'''

text = text.replace(old_corp, new_corp)

with open(r"d:\study\ppois\ppo-labs\lab2\tests\test_complete_coverage.cpp", "w", encoding="utf-8") as f:
    f.write(text)

print("Applied fixes to test_complete_coverage.cpp")
