//
// Created by Erik Gabrielsen on 4/4/23.
//

#include "Flight.h"

Flight::Flight(int number, string connection, string direction) {
    this->number = new int(number); // initializes number
    this->connection = new string(connection); // initializes connection
    this->direction = new string(direction); // initializes direction
    this->status = new string("ON TIME");

}

Flight::~Flight() {
    delete number; // deletes number
    delete connection; // deletes connection
    delete direction; // deletes direction
    delete status; // deletes status
}

Flight::Flight(const Flight &copyClass) {
    delete number; // deletes number
    number = new int(*copyClass.number); // creates a copy

    delete connection; // deletes connection
    connection = new string(*copyClass.connection); // creates a copy

    delete direction; // deletes direction
    direction = new string(*copyClass.direction); // creates a copy

    delete status; // deletes status
    status = new string(*copyClass.status); // creates a copy
}

Flight &Flight::operator=(const Flight &copy) {
    if(this != &copy) {
        delete number; // deletes number
        number = new int;
        *number = *(copy.number);

        delete connection; // deletes connection
        connection = new string;
        *connection = *(copy.connection);

        delete direction; // deletes direction
        direction = new string;
        *direction = *(copy.direction);

        delete status; // deletes status
        status = new string;
        *status = *(copy.status);
    }
    return *this;
}

void Flight::setStatus(string status) { *this->status = status; } // updates the status of the flight with the value passed in

int Flight::getFlightNumber() { return *number; } // returns the number for the flight as an integer

void Flight::display() {
    cout << '\t' << '\t' << *direction << " Flight # " << *number << " traveling from " << *connection << " is " << *status<< endl;
}
