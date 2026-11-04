#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
using namespace std;

// Base Class
class Room {
private:
    int roomNumber;
    bool available;

protected:
    double price;
    string roomType;

public:
    Room() {
        roomNumber = 0;
        available = true;
        price = 0;
        roomType = "";
    }

    Room(int number, double p, string type) {
        roomNumber = number;
        price = p;
        roomType = type;
        available = true;
    }

    virtual ~Room() {}

    int getRoomNumber() const {
        return roomNumber;
    }

    bool isAvailable() const {
        return available;
    }

    void setAvailable(bool status) {
        available = status;
    }

    virtual double calculatePrice(int days) const = 0;

    virtual void displayInfo() const {
        cout << "Room Number: " << roomNumber << endl;
        cout << "Room Type: " << roomType << endl;
        cout << "Status: "
             << (available ? "Available" : "Booked") << endl;
    }
};

// Derived Class 1
class SingleRoom : public Room {
public:
    SingleRoom(int number, double p)
        : Room(number, p, "Single") {}

    ~SingleRoom() override {}

    double calculatePrice(int days) const override {
        return price * days;
    }

    void displayInfo() const override {
        Room::displayInfo();
        cout << "Price per Day: " << price << " IQD" << endl;
    }
};

// Derived Class 2
class DoubleRoom : public Room {
public:
    DoubleRoom(int number, double p)
        : Room(number, p, "Double") {}

    ~DoubleRoom() override {}

    double calculatePrice(int days) const override {
        return price * days;
    }

    void displayInfo() const override {
        Room::displayInfo();
        cout << "Price per Day: " << price << " IQD" << endl;
    }
};

#endif
