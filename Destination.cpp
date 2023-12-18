//
// Created by Erik Gabrielsen on 4/4/23.
//

#include "Destination.h"

Destination::Destination(string code, string name) {
    this->code = new string(code); // initializes code
    this->name = new string(name); // initializes name
}

Destination::~Destination() {
    delete name; // deletes name
    delete code; // deletes code
}

Destination::Destination(const Destination &copyClass) {
    delete name; // deletes name
    name = new string(*copyClass.name); // creates a copy

    delete code; // deletes code
    code = new string(*copyClass.code); // creates a copy
}

Destination &Destination::operator=(const Destination &copy) {
    if (this != &copy) {
        delete name; // deletes name
        name = new string;
        *name = *(copy.name);

        delete code; // deletes code
        code = new string;
        *code = *(copy.code);
    }
    return *this;
}

void Destination::addFlight(Flight *newFlight) {
    flights.push_back(newFlight); // adds the newFlight object pointer to the vector of flights
}

void Destination::updateFlight(int number, string name) {
    for (int i = 0; i < flights.size(); i++) { // linear search through vector of flights for the one matching the number passed in
        if (flights.at(i)->getFlightNumber() == number) {
            flights.at(i)->setStatus(name); // once found, it calls the flight object's setStatus(string) function
        }
    }
}

void Destination::display() {
    for (Flight* flight: flights) { // calls display method
        flight->display();
    }
}

string Destination::getCode() { return *code; } // gets the airport code

string Destination::getName() { return *name; } // gets the airport name