#include <gtest/gtest.h>
#include "GuestManager.h"
#include "GuestNotFoundException.h"

TEST(GuestManagerTest, AddAndFindGuest) {
    GuestManager mgr;
    Guest g("Ivan", "Ivanov", Date(), ContactInfo(), Gender::Male, "1234");
    mgr.addGuest(g);
    
    EXPECT_EQ(mgr.getGuestCount(), 1);
    
    // Ищем по ID (он уникален, сгенерировался автоматически)
    Id gId = g.getId();
    Guest* found = mgr.findGuestById(gId);
    EXPECT_EQ(found->getFirstName(), "Ivan");
}

TEST(GuestManagerTest, FindNonExistentGuestThrows) {
    GuestManager mgr;
    Id fakeId(999);
    
    // Проверяем, что бросается исключение GuestNotFoundException
    EXPECT_THROW(mgr.findGuestById(fakeId), GuestNotFoundException);
}