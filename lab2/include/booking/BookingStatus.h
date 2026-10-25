#pragma once

/**
 * @brief Status of a booking or reservation.
 */
enum class BookingStatus {
    Pending,    // Ожидает подтверждения
    Confirmed,  // Подтверждено
    Cancelled,  // Отменено
    Completed   // Завершено (гость уже выехал)
};