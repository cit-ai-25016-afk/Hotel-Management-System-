#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
using namespace std;

class Reservation {
private:
    int reservationId;
    int roomNumber;
    string customerName;
    int days;
    double totalCost;
    bool active;

public:
    // Default Constructor
    Reservation() {
        reservationId = 0;
        roomNumber = 0;
        customerName = "";
        days = 0;
        totalCost = 0;
        active = false;
    }

    // Parameterized Constructor
    Reservation(int id, int room, string name,
                int d, double cost) {
        reservationId = id;
        roomNumber = room;
        customerName = name;
        days = d;
        totalCost = cost;
        active = true;
    }

    ~Reservation() {}

    int getId() const {
        return reservationId;
    }

    int getRoomNumber() const {
        return roomNumber;
    }

    string getCustomerName() const {
        return customerName;
    }

    bool isActive() const {
        return active;
    }

    void cancel() {
        active = false;
    }

    void displayInfo() const {
        cout << "\nReservation ID: " << reservationId << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Room Number: " << roomNumber << endl;
        cout << "Number of Days: " << days << endl;
        cout << "Total Cost: " << totalCost << " IQD" << endl;
    }
};

#endif
