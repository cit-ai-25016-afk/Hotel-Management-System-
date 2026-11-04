#include "Hotel.h"

// Find Room
Room* Hotel::findRoom(int number) {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i]->getRoomNumber() == number) {
            return rooms[i];
        }
    }

    return nullptr;
}

// Constructor
Hotel::Hotel(Room* roomList[], int count) {
    roomCount = count;
    reservationCount = 0;
    nextReservationId = 1;

    for (int i = 0; i < count; i++) {
        rooms[i] = roomList[i];
    }
}

// Destructor
Hotel::~Hotel() {}

// Display All Rooms
void Hotel::displayAllRooms() {
    cout << "\n--- All Hotel Rooms ---\n";

    for (int i = 0; i < roomCount; i++) {
        rooms[i]->displayInfo();
        cout << "------------------\n";
    }
}

// Book a Room
void Hotel::bookRoom(int number, string name, int days) {
    if (reservationCount >= 100) {
        cout << "Reservation list is full!\n";
        return;
    }

    Room* room = findRoom(number);

    if (room == nullptr) {
        cout << "Room not found.\n";
        return;
    }

    if (!room->isAvailable()) {
        cout << "Room is already booked.\n";
        return;
    }

    if (name.empty() || days <= 0) {
        cout << "Invalid booking information.\n";
        return;
    }

    double cost = room->calculatePrice(days);

    reservations[reservationCount] =
        Reservation(nextReservationId, number,
                    name, days, cost);

    room->setAvailable(false);

    cout << "\nReservation Successful!\n";
    cout << "Reservation ID: "
         << nextReservationId << endl;
    cout << "Total Cost: " << cost << " IQD\n";

    reservationCount++;
    nextReservationId++;
}

// Display All Reservations
void Hotel::displayReservations() {
    cout << "\n--- All Reservations ---\n";

    bool found = false;

    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].isActive()) {
            reservations[i].displayInfo();
            found = true;
        }
    }

    if (!found) {
        cout << "No reservations found.\n";
    }
}

// Search by Reservation ID
void Hotel::searchReservation(int id) {
    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].getId() == id &&
            reservations[i].isActive()) {
            reservations[i].displayInfo();
            return;
        }
    }

    cout << "Reservation not found.\n";
}

// Search by Customer Name
void Hotel::searchReservation(string name) {
    bool found = false;

    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].getCustomerName() == name &&
            reservations[i].isActive()) {
            reservations[i].displayInfo();
            found = true;
        }
    }

    if (!found) {
        cout << "Reservation not found.\n";
    }
}

// Cancel Reservation
void Hotel::cancelReservation(int id) {
    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].getId() == id &&
            reservations[i].isActive()) {

            int roomNumber = reservations[i].getRoomNumber();

            Room* room = findRoom(roomNumber);

            if (room != nullptr) {
                room->setAvailable(true);
            }

            reservations[i].cancel();

            cout << "Reservation cancelled successfully.\n";
            return;
        }
    }

    cout << "Reservation not found.\n";
}
