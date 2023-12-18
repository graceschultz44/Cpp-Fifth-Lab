//
// Created by Erik Gabrielsen on 4/4/23.
//

#include "FlightPlanner.h"

FlightPlanner::FlightPlanner() {
    // blank
}

FlightPlanner::~FlightPlanner() {
    for(int x = 0; x < destinations.size(); x++) { // loops through destination pointer
            delete destinations.at(x); // deletes each one
    }
}

void FlightPlanner::createDestination(string code, string name) {

    Destination *destination = new Destination(code, name); // create destination object
    destinations.push_back(destination); // add the pointer to the vector
}

void FlightPlanner::createFlight(int flightNumber, string to, string from) {

    Flight *inboundFlight = new Flight(flightNumber, to, "INBOUND"); // creates an inbound flight object
    Flight *outboundFlight = new Flight(flightNumber, from, "OUTBOUND"); // creates an outbound flight object

    for (int i = 0; i < destinations.size(); i++) { // linear search through list of destinations and finds the one that matches the to code
        if (destinations.at(i)->getCode() == from) {
            destinations.at(i)->addFlight(inboundFlight); // adds the inbound flight to that destination
        }
    }
    for (int k = 0; k < destinations.size(); k++) { // linear search through list of destinations and finds the one that matches the from code
        if (destinations.at(k)->getCode() == to) {
            destinations.at(k)->addFlight(outboundFlight); // adds the outbound flight to that destination
        }
    }
}

void FlightPlanner::updateFlight(int flightNumber, string status) {
    for (int i = 0; i < destinations.size(); i++) { // iterates over the destinations
        destinations.at(i)->updateFlight(flightNumber, status); // calls the updateFlight() function on the destination
    }
}

void FlightPlanner::display(string airportCode) {
    for (int i = 0; i < destinations.size(); i++) { // linear searches through the destinations
        if (destinations.at(i)->getCode() == airportCode) {
            cout << destinations.at(i)->getCode() << ": " << destinations.at(i)->getName() << endl;
            destinations.at(i)->display(); // calls the display() function on the destination that matches the airportCode
            cout << endl;
        }
    }
}