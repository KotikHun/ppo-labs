#pragma once

/**
 * @brief Status of a payment transaction.
 */
enum class PaymentStatus {
    Pending,   // Ожидает обработки
    Success,   // Успешно
    Failed,    // Ошибка
    Refunded   // Возврат
};