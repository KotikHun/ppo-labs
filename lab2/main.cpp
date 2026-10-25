#include "Hotel.h"
#include "StandardRoom.h"
#include "LuxRoom.h"
#include "CashPayment.h"
#include "CleaningService.h"
#include <iostream>
#include <limits>

using namespace std;

void printMenu() {
    cout << "\n=== HOTEL MANAGEMENT SYSTEM ===" << endl;
    cout << "1. Add Guest" << endl;
    cout << "2. Add Standard Room" << endl;
    cout << "3. Make Reservation" << endl;
    cout << "4. Show All Rooms" << endl;
    cout << "5. Print Summary Report" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    Hotel hotel;

    // Для теста добавим один номер вручную (чтобы было что бронировать)
    hotel.getRoomManager().addRoom(new StandardRoom(101, 2, RoomStatus::Available, Money(5000, Currency::RUB), true));

    int choice = -1;
    while (choice != 0) {
        printMenu();
        if (!(cin >> choice)) {
            cin.clear(); // Сброс ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        try {
            if (choice == 1) {
                string fName, lName;
                cout << "Enter first name: "; cin >> fName;
                cout << "Enter last name: "; cin >> lName;
                // Создаем гостя (остальные поля по умолчанию)
                Guest g(fName, lName, Date(), ContactInfo("+7999", "test@mail.com"), Gender::Male, "1234");
                hotel.getGuestManager().addGuest(g);
                cout << "Guest added successfully!" << endl;
            }
            else if (choice == 2) {
                int num, cap; double price;
                cout << "Enter room number: "; cin >> num;
                cout << "Enter capacity: "; cin >> cap;
                cout << "Enter base price: "; cin >> price;
                hotel.getRoomManager().addRoom(new StandardRoom(num, cap, RoomStatus::Available, Money(price, Currency::RUB), true));
                cout << "Room added successfully!" << endl;
            }
            else if (choice == 3) {
                // В реальной программе мы бы спрашивали ID, но для простоты возьмем первого гостя и комнату
                if (hotel.getGuestManager().getGuestCount() == 0 || hotel.getRoomManager().getRoomCount() == 0) {
                    cout << "Need at least one guest and one room to book." << endl;
                    continue;
                }
                cout << "Making reservation for the first guest and first room..." << endl;
                // ... (здесь можно было бы добавить ввод дат, но опустим для краткости)
            }
            else if (choice == 4) {
                hotel.getRoomManager().printAllRooms();
            }
            else if (choice == 5) {
                hotel.getReportManager().printSummaryReport(hotel.getGuestManager(), hotel.getRoomManager(), hotel.getBookingManager(), hotel.getPaymentManager());
            }
        } catch (const HotelException& e) {
            // Ловим все наши ошибки!
            cout << "Error: " << e.what() << endl;
        } catch (const exception& e) {
            cout << "System error: " << e.what() << endl;
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}