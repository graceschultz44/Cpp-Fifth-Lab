//
// Created by Erik Gabrielsen on 4/4/23.
//

#ifndef PROGRAM5_DESTINATION_H
#define PROGRAM5_DESTINATION_H
#include <string>
#include <vector>
#include "Flight.h"
using namespace std;

class Destination {

public:
    Destination(string code, string name);

    ~Destination();

    Destination(const Destination &copyClass);

    Destination& operator=(const Destination&);

    void addFlight(Flight *newFlight);

    void updateFlight(int number, string name);

    void display();

    string getCode();

    string getName();

private:
    string* code;

    string* name;

    vector<Flight*> flights;
};

#endif //PROGRAM5_DESTINATION_H
