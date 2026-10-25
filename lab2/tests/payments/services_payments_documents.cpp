#include <gtest/gtest.h>
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
#include "Comment.h"
#include "Review.h"
#include "Feedback.h"
#include "Complaint.h"

TEST(ServicesPaymentsDocsCoverage, AllMethods) {
    // Услуги
    CleaningService cs("C", Money(100, Currency::RUB), 2); cs.getRoomsCount(); cs.setRoomsCount(3); cs.calculateCost(); cs.toString();
    FoodService fs("F", Money(100, Currency::RUB), true); fs.getIsRoomService(); fs.setIsRoomService(false); fs.calculateCost(); fs.toString();
    TransferService ts("T", Money(100, Currency::RUB), 1.0); ts.getDistanceKm(); ts.setDistanceKm(2.0); ts.calculateCost(); ts.toString();
    ExcursionService es("E", Money(100, Currency::RUB), 2); es.getPeopleCount(); es.setPeopleCount(3); es.calculateCost(); es.toString();
    SpaService ss("S", Money(100, Currency::RUB), 1); ss.getHours(); ss.setHours(2); ss.calculateCost(); ss.toString();
    LaundryService ls("L", Money(100, Currency::RUB), 5); ls.getItemsCount(); ls.setItemsCount(12); ls.calculateCost(); ls.toString();

    ServiceOrder so(Id(1), Id(2), 1, Money(100, Currency::RUB));
    so.getId(); so.getGuestId(); so.getServiceId(); so.getQuantity(); so.getStatus(); so.getTotalCost();
    so.setStatus(ServiceStatus::Completed); so.toString();

    // Платежи
    CashPayment cash(Money(100, Currency::RUB), Date(), Money(0, Currency::RUB));
    cash.getChangeGiven(); cash.setChangeGiven(Money(10, Currency::RUB)); cash.processPayment(); cash.toString();

    CardPayment card(Money(100, Currency::RUB), Date(), "1234");
    card.getCardNumber(); card.setCardNumber("5678"); card.processPayment(); card.toString();

    OnlinePayment op(Money(100, Currency::RUB), Date(), "test@mail.com");
    op.getEmail(); op.setEmail("new@mail.com"); op.processPayment(); op.toString();

    Invoice inv(Id(1), Money(100, Currency::RUB), Date());
    inv.getId(); inv.getReservationId(); inv.getAmount(); inv.getIssueDate(); inv.getIsPaid(); inv.markAsPaid(); inv.toString();

    Tariff t("T", Season::Summer, 1.2); t.getName(); t.getSeason(); t.getMultiplier(); t.apply(Money(100, Currency::RUB)); t.toString();
    Discount d("D", 10); d.getDescription(); d.getPercent(); d.apply(Money(100, Currency::RUB)); d.toString();

    // Документы
    Passport p("123", Date(), Date(1,1,2030), "R"); p.getCountry(); p.setCountry("R2"); p.isValid(Date()); p.toString();
    Visa v("V", Date(), Date(1,1,2030), "T"); v.getVisaType(); v.setVisaType("T2"); v.isValid(Date()); v.toString();
    Contract c("C", Date(), Date(1,1,2030), Id(1)); c.getGuestId(); c.setGuestId(Id(2)); c.isValid(Date()); c.toString();
    Receipt r("R", Date(), Date(1,1,2030), Money(100, Currency::RUB)); r.getTotalAmount(); r.setTotalAmount(Money(200, Currency::RUB)); r.isValid(Date()); r.toString();

    // Отзывы
    Comment cm("T", "A"); cm.getText(); cm.getAuthor(); cm.setText("T2"); cm.setAuthor("A2"); cm.toString();
    Review rev(Id(1), Rating(5), cm, Date()); rev.getId(); rev.getGuestId(); rev.getRating(); rev.getComment(); rev.getReviewDate(); rev.toString();
    Feedback fb(cm, Date(), "Email"); fb.getComment(); fb.getFeedbackDate(); fb.getChannel(); fb.toString();
    Complaint comp(Id(1), cm, 2); comp.getId(); comp.getGuestId(); comp.getDescription(); comp.getPriority(); comp.getIsResolved(); comp.resolve(); comp.toString();
}