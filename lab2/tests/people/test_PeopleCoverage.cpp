#include <gtest/gtest.h>
#include "Person.h"
#include "Guest.h"
#include "VipGuest.h"
#include "RegularGuest.h"
#include "CorporateGuest.h"
#include "Employee.h"
#include "Manager.h"
#include "Administrator.h"
#include "Maid.h"
#include "Chef.h"
#include "SecurityGuard.h"
#include "ContactPerson.h"

TEST(PeopleCoverage, AllMethods) {
    Person p("A", "B", Date(), ContactInfo(), Gender::Male);
    p.getFirstName(); p.getLastName(); p.getBirthDate(); p.getContacts(); p.getGender(); p.getId();
    p.setFirstName("C"); p.setLastName("D"); p.setBirthDate(Date()); p.setContacts(ContactInfo()); p.setGender(Gender::Female);
    p.toString();
    EXPECT_NO_THROW(std::cout << p);

    Guest g("A", "B", Date(), ContactInfo(), Gender::Male, "123");
    g.getPassportNumber(); g.getLoyaltyPoints(); g.setPassportNumber("456"); g.setLoyaltyPoints(10); g.addLoyaltyPoints(5); g.toString();

    VipGuest v("A", "B", Date(), ContactInfo(), Gender::Male, "123", 10);
    v.getDiscountPercent(); v.setDiscountPercent(20); v.toString();

    RegularGuest r("A", "B", Date(), ContactInfo(), Gender::Male, "123");
    r.getVisitCount(); r.setVisitCount(2); r.incrementVisitCount(); r.toString();

    CorporateGuest c("A", "B", Date(), ContactInfo(), Gender::Male, "123", "Comp");
    c.getCompanyName(); c.setCompanyName("New"); c.toString();

    Employee e("A", "B", Date(), ContactInfo(), Gender::Male, "Pos", 100);
    e.getPosition(); e.getSalary(); e.setPosition("New"); e.setSalary(200); e.toString();

    Manager m("A", "B", Date(), ContactInfo(), Gender::Male, "Dir", 100, "123", "HR");
    m.getDepartment(); m.setDepartment("IT"); m.toString();

    Administrator a("A", "B", Date(), ContactInfo(), Gender::Male, "Admin", 100, 1);
    a.getDeskNumber(); a.setDeskNumber(2); a.toString();

    Maid md("A", "B", Date(), ContactInfo(), Gender::Female, "Maid", 100, 0);
    md.getCleanedRoomsCount(); md.setCleanedRoomsCount(5); md.cleanRoom(); md.toString();

    Chef ch("A", "B", Date(), ContactInfo(), Gender::Male, "Chef", 100, "Pastry");
    ch.getSpecialty(); ch.setSpecialty("Meat"); ch.toString();

    SecurityGuard sg("A", "B", Date(), ContactInfo(), Gender::Male, "Guard", 100, "Night");
    sg.getShift(); sg.setShift("Day"); sg.toString();

    ContactPerson cp(p, "Comp");
    cp.getPerson(); cp.getCompanyName(); cp.setPerson(p); cp.setCompanyName("New"); cp.toString();
    EXPECT_NO_THROW(std::cout << cp);
}