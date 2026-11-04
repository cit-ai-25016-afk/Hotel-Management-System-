#ifndef HOTEL_H
#define HOTEL_H

#include "Room.h"
#include "Reservation.h"
#include <string>
using namespace std;

class Hotel {
private:
    Room* rooms[10];
    int roomCount;

    Reservation reservations[100];
    int reservationCount;

    int nextReservationId;

    Room* findRoom(int number);

public:
    Hotel(Room* roomList[], int count);

    ~Hotel();

    void displayAllRooms();

    void bookRoom(int number, string name, int days);

    void displayReservations();

    void searchReservation(int id);

    void searchReservation(string name);

    void cancelReservation(int id);
};

#endif
