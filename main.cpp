#include <iostream>
#include <string>
#include <limits>
#include "Room.h"
#include "Reservation.h"
#include "Hotel.h"

using namespace std;

int main() {
    SingleRoom room1(101, 50000);
    SingleRoom room2(102, 50000);

    DoubleRoom room3(201, 80000);
    DoubleRoom room4(202, 80000);

    Room* roomList[] = {
        &room1, &room2, &room3, &room4
    };

    Hotel hotel(roomList, 4);

    int choice = 0;

    do {
        cout << "\n===== HOTEL MANAGEMENT SYSTEM =====\n";
        cout << "1. Display All Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Display All Reservations\n";
        cout << "4. Search Reservation\n";
        cout << "5. Cancel Reservation\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        if (choice == 1) {
            hotel.displayAllRooms();
        }

        else if (choice == 2) {
            int number, days;
            string name;

            cout << "Enter Room Number: ";
            cin >> number;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Customer Name: ";
            getline(cin, name);

            cout << "Enter Number of Days: ";
            cin >> days;

            hotel.bookRoom(number, name, days);
        }

        else if (choice == 3) {
            hotel.displayReservations();
        }

        else if (choice == 4) {
            int option;

            cout << "1. Search by Reservation ID\n";
            cout << "2. Search by Customer Name\n";
            cout << "Enter your choice: ";
            cin >> option;

            if (option == 1) {
                int id;

                cout << "Enter Reservation ID: ";
                cin >> id;

                hotel.searchReservation(id);
            }

            else if (option == 2) {
                string name;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter Customer Name: ";
                getline(cin, name);

                hotel.searchReservation(name);
            }

            else {
                cout << "Invalid choice.\n";
            }
        }

        else if (choice == 5) {
            int id;

            cout << "Enter Reservation ID: ";
            cin >> id;

            hotel.cancelReservation(id);
        }

        else if (choice == 6) {
            cout << "Thank you for using Hotel Management System!\n";
        }

        else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
