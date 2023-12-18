//
// Created by Erik Gabrielsen on 4/4/23.
//

#ifndef PROGRAM5_FLIGHTPLANNER_H
#define PROGRAM5_FLIGHTPLANNER_H
#include "Destination.h"

class FlightPlanner {

public:
    FlightPlanner();

    ~FlightPlanner();

    void createDestination(string code, string name);

    void createFlight(int flightNumber, string to, string from);

    void updateFlight(int flightNumber, string status);

    void display(string airportCode);

private:
    vector<Destination*> destinations;
};

#endif //PROGRAM5_FLIGHTPLANNER_H
