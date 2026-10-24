#include <gtest/gtest.h>
#include <sstream>
#include "Date.h"
#include "Money.h"
#include "Id.h"
#include "Address.h"
#include "ContactInfo.h"
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
#include "StandardRoom.h"
#include "LuxRoom.h"
#include "Apartment.h"
#include "SuiteRoom.h"
#include "Building.h"
#include "Floor.h"
#include "Reservation.h"
#include "Company.h"
#include "GuestGroup.h"
#include "Stay.h"
#include "CheckIn.h"
#include "CheckOut.h"
#include "CleaningService.h"
#include "FoodService.h"
#include "TransferService.h"
#include "ExcursionService.h"
#include "SpaService.h"
#include "LaundryService.h"
#include "ServiceOrder.h"
#include "CashPayment.h"
#include "CardPayment.h"
#include "OnlinePayment.h"
#include "Invoice.h"
#include "Tariff.h"
#include "Discount.h"
#include "Passport.h"
#include "Visa.h"
#include "Contract.h"
#include "Receipt.h"
#include "Rating.h"
#include "Comment.h"
#include "Review.h"
#include "Feedback.h"
#include "Complaint.h"

TEST(HardcoreCoverage, CoreAndPeople) {
    std::stringstream ss;
    Date d1(1,1,2023), d2(2,1,2023);
    Date d3 = d1; d1 = d2; bool b = (d1 == d2) || (d1 != d2) || (d1 < d2) || (d1 > d2) || (d1 <= d2) || (d1 >= d2); ss >> d1;

    Money m1(100, Currency::RUB), m2(200, Currency::RUB);
    Money m3 = m1; m1 = m2; b = (m1 == m2) || (m1 != m2) || (m1 < m2) || (m1 > m2) || (m1 <= m2) || (m1 >= m2); ss >> m1;

    Id id1(1), id2(2); Id id3 = id1; id1 = id2; b = (id1 == id2) || (id1 != id2) || (id1 < id2) || (id1 > id2); ss >> id1;

    Address a1("R","C","S","H"), a2; Address a3 = a1; a1 = a2; b = (a1 == a2) || (a1 != a2) || (a1 < a2) || (a1 > a2); ss >> a1;

    ContactInfo ci1("123","e@m.c"), ci2; ContactInfo ci3 = ci1; ci1 = ci2; b = (ci1 == ci2) || (ci1 != ci2) || (ci1 < ci2) || (ci1 > ci2); ss >> ci1;

    Person p1("A","B",d1,ci1,Gender::Male), p2; Person p3 = p1; p1 = p2; b = (p1 == p2) || (p1 != p2) || (p1 < p2) || (p1 > p2); ss >> p1;
    Guest g1("A","B",d1,ci1,Gender::Male,"P"), g2; Guest g3 = g1; g1 = g2; b = (g1 == g2) || (g1 != g2); ss >> g1;
    VipGuest vg1("A","B",d1,ci1,Gender::Male,"P",10), vg2; VipGuest vg3 = vg1; vg1 = vg2; b = (vg1 == vg2) || (vg1 != vg2); ss >> vg1;
    RegularGuest rg1("A","B",d1,ci1,Gender::Male,"P"), rg2; RegularGuest rg3 = rg1; rg1 = rg2; b = (rg1 == rg2) || (rg1 != rg2); ss >> rg1;
    CorporateGuest cg1("A","B",d1,ci1,Gender::Male,"P","C"), cg2; CorporateGuest cg3 = cg1; cg1 = cg2; b = (cg1 == cg2) || (cg1 != cg2); ss >> cg1;

    Employee e1("A","B",d1,ci1,Gender::Male,"P",100), e2; Employee e3 = e1; e1 = e2; b = (e1 == e2) || (e1 != e2); ss >> e1;
    Manager mg1("A","B",d1,ci1,Gender::Male,"P",100,"Pas","D"), mg2; Manager mg3 = mg1; mg1 = mg2; ss >> mg1;
    Administrator ad1("A","B",d1,ci1,Gender::Male,"P",100,1), ad2; Administrator ad3 = ad1; ad1 = ad2; ss >> ad1;
    Maid md1("A","B",d1,ci1,Gender::Male,"P",100,0), md2; Maid md3 = md1; md1 = md2; ss >> md1;
    Chef ch1("A","B",d1,ci1,Gender::Male,"P",100,"S"), ch2; Chef ch3 = ch1; ch1 = ch2; ss >> ch1;
    SecurityGuard sg1("A","B",d1,ci1,Gender::Male,"P",100,"S"), sg2; SecurityGuard sg3 = sg1; sg1 = sg2; ss >> sg1;
    ContactPerson cp1(p1, "C"), cp2; ContactPerson cp3 = cp1; cp1 = cp2; b = (cp1 == cp2) || (cp1 != cp2); ss >> cp1;
}

TEST(HardcoreCoverage, RoomsAndBooking) {
    std::stringstream ss;
    Date d1(1,1,2023);
    Money m1(100, Currency::RUB);

    StandardRoom r1(1,2,RoomStatus::Available,m1,true), r2; StandardRoom r3 = r1; r1 = r2; ss >> r1;
    LuxRoom lr1(1,2,RoomStatus::Available,m1,true), lr2; LuxRoom lr3 = lr1; lr1 = lr2; ss >> lr1;
    Apartment ap1(1,2,RoomStatus::Available,m1,2), ap2; Apartment ap3 = ap1; ap1 = ap2; ss >> ap1;
    SuiteRoom sr1(1,2,RoomStatus::Available,m1,true), sr2; SuiteRoom sr3 = sr1; sr1 = sr2; ss >> sr1;
    Building b1(1,"N",Address(),5), b2; Building b3 = b1; b1 = b2; bool b = (b1 == b2) || (b1 != b2); ss >> b1;
    Floor f1(1,10,"D"), f2; Floor f3 = f1; f1 = f2; b = (f1 == f2) || (f1 != f2); ss >> f1;

    Reservation res1(Id(1),Id(2),d1,d1,m1), res2; Reservation res3 = res1; res1 = res2; b = (res1 == res2) || (res1 != res2); ss >> res1;
    Company comp1("N","T",Address()), comp2; Company comp3 = comp1; comp1 = comp2; b = (comp1 == comp2) || (comp1 != comp2); ss >> comp1;
    GuestGroup gg1("G"), gg2; GuestGroup gg3 = gg1; gg1 = gg2; b = (gg1 == gg2) || (gg1 != gg2);
    Stay st1(Id(1),Id(2),d1,d1), st2; Stay st3 = st1; st1 = st2; b = (st1 == st2) || (st1 != st2);
    CheckIn ci1(Id(1),d1,"E"), ci2; CheckIn ci3 = ci1; ci1 = ci2;
    CheckOut co1(Id(1),d1,true), co2; CheckOut co3 = co1; co1 = co2;
}

TEST(HardcoreCoverage, ServicesPaymentsReviews)
{
    std::stringstream ss;
    Date d1(1,1,2023);
    Money m1(100, Currency::RUB);
    Comment comment1("T","A"), comment2; Comment comment3 = comment1; comment1 = comment2; bool b = (comment1 == comment2) || (comment1 != comment2);

    CleaningService cs1("N",m1,1), cs2; CleaningService cs3 = cs1; cs1 = cs2;
    FoodService fs1("N",m1,true), fs2; FoodService fs3 = fs1; fs1 = fs2;
    TransferService ts1("N",m1,1), ts2; TransferService ts3 = ts1; ts1 = ts2;
    ExcursionService es1("N",m1,1), es2; ExcursionService es3 = es1; es1 = es2;
    SpaService sp1("N",m1,1), sp2; SpaService sp3 = sp1; sp1 = sp2;
    LaundryService ls1("N",m1,1), ls2; LaundryService ls3 = ls1; ls1 = ls2;
    ServiceOrder so1(Id(1),Id(2),1,m1), so2; ServiceOrder so3 = so1; so1 = so2; b = (so1 == so2) || (so1 != so2);

    CashPayment cp1(m1,d1,m1), cp2; CashPayment cp3 = cp1; cp1 = cp2;
    CardPayment cdp1(m1,d1,"1"), cdp2; CardPayment cdp3 = cdp1; cdp1 = cdp2;
    OnlinePayment op1(m1,d1,"e"), op2; OnlinePayment op3 = op1; op1 = op2;
    Invoice inv1(Id(1),m1,d1), inv2; Invoice inv3 = inv1; inv1 = inv2;

    Passport p1("1",d1,d1,"R"), p2; Passport p3 = p1; p1 = p2; b = (p1 == p2) || (p1 != p2);
    Visa v1("1",d1,d1,"T"), v2; Visa v3 = v1; v1 = v2; b = (v1 == v2) || (v1 != v2);
    Contract con1("1",d1,d1,Id(1)), con2; Contract con3 = con1; con1 = con2; b = (con1 == con2) || (con1 != con2);
    Receipt rc1("1",d1,d1,m1), rc2; Receipt rc3 = rc1; rc1 = rc2; b = (rc1 == rc2) || (rc1 != rc2);

    Rating ra1(5), ra2; Rating ra3 = ra1; ra1 = ra2; b = (ra1 == ra2) || (ra1 != ra2);
    Review rev1(Id(1),ra1,comment1,d1), rev2; Review rev3 = rev1; rev1 = rev2;
    Feedback fb1(comment1,d1,"C"), fb2; Feedback fb3 = fb1; fb1 = fb2;
    Complaint com1(Id(1),comment1,1), com2; Complaint com3 = com1; com1 = com2;

    // --- ДОБАВЛЕНО ДЛЯ ПОКРЫТИЯ TARIFF, DISCOUNT, SERVICE, PAYMENT ---
    Tariff tariff1("T", Season::Summer, 1.5), tariff2;
    tariff2 = tariff1;
    tariff1.getName();
    tariff1.getSeason();
    tariff1.getMultiplier();
    tariff1.apply(m1);

    Discount discount1("D", 10), discount2;
    discount2 = discount1;
    discount1.getDescription();
    discount1.getPercent();
    discount1.apply(m1);

    ss << cp1; // Оператор вывода для CashPayment (наследник Payment)
    ss << cs1;
}// Оператор вывода для CleaningService (наследник Service)