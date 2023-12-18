//
// Created by Erik Gabrielsen on 4/4/23.
//

#ifndef PROGRAM5_FLIGHT_H
#define PROGRAM5_FLIGHT_H
#include <iostream>

using namespace std;

class Flight {

public:
    Flight(int number, string connection, string direction);

    ~Flight();

    Flight(const Flight &copyClass);

    Flight& operator=(const Flight &copy);

    void setStatus(string status);

    int getFlightNumber();

    void display();

private:
    int* number;

    string* connection;

    string* direction;

    string* status;
};

#endif //PROGRAM5_FLIGHT_H
