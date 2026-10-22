#pragma once

/**
 * @brief Status of a service order.
 */
enum class ServiceStatus {
    Ordered,    // Заказано
    Completed,  // Выполнено
    Cancelled   // Отменено
};