# Hotel-Management-System-
g++ -std=c++17 main.cpp Hotel.cpp -o hotel

Hotel Management System

1. Project Description

The Hotel Management System is a simple C++ application designed to manage hotel rooms and customer reservations. It allows users to display rooms, book rooms, view reservations, search for reservations, and cancel bookings.

2. Project Objectives

- Manage hotel rooms and reservations.
- Apply Object-Oriented Programming (OOP) concepts.
- Practice using classes, objects, constructors, and functions.
- Understand inheritance and polymorphism in C++.

3. Main Features

1. Display All Rooms.
2. Book a Room.
3. Display All Reservations.
4. Search Reservation by ID or Customer Name.
5. Cancel Reservation.
6. Exit the Program.

4. Object-Oriented Programming Concepts

4.1 Classes and Objects

The project uses classes such as "Room", "SingleRoom", "DoubleRoom", "Reservation", and "Hotel".

Objects are created from these classes to represent hotel rooms, reservations, and the hotel system.

4.2 Encapsulation

Encapsulation is implemented by declaring data members as private or protected and providing public member functions to access or modify the data.

4.3 Constructors

The project uses default constructors and parameterized constructors to initialize objects with default or specific values.

4.4 Destructors

Destructors are used to handle object destruction. A virtual destructor is defined in the base class "Room".

4.5 Inheritance

The classes "SingleRoom" and "DoubleRoom" inherit from the base class "Room".

This avoids code repetition and allows different room types to share common properties and functions.

4.6 Access Modifiers

The project uses:

- "private" to protect data members.
- "protected" to allow derived classes to access selected members.
- "public" to provide access to functions and constructors.

4.7 Polymorphism

Polymorphism is implemented using virtual functions.

The "calculatePrice()" and "displayInfo()" functions are overridden in the derived classes to provide different implementations.

4.8 Function Overloading

The "searchReservation()" function is overloaded to search for reservations using either a reservation ID or a customer name.

5. Classes Used

- Room: The base class that stores common room information.
- SingleRoom: Represents a single room.
- DoubleRoom: Represents a double room.
- Reservation: Stores customer reservation information.
- Hotel: Manages rooms and reservations.

6. Program Requirements

- Programming Language: C++
- Standard: C++17
- Programming Paradigm: Object-Oriented Programming

7. Conclusion

This project demonstrates the main concepts of Object-Oriented Programming in C++. It provides a simple way to manage hotel rooms and reservations while applying encapsulation, inheritance, polymorphism, constructors, destructors, and function overloading.
