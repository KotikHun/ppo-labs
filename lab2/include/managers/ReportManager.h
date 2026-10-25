#pragma once

#include "GuestManager.h"
#include "RoomManager.h"
#include "BookingManager.h"
#include "PaymentManager.h"
#include <iostream>

/**
 * @brief Generates reports based on the hotel's current state.
 */
class ReportManager {
public:
    ReportManager();
    ~ReportManager();

    // Принимает ссылки на другие менеджеры, чтобы прочитать их данные
    void printSummaryReport(GuestManager& gm, RoomManager& rm, BookingManager& bm, PaymentManager& pm) const;
    
    void printFreeRoomsReport(RoomManager& rm) const;
};