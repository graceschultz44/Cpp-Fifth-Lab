#include <iostream>
#include <fstream>
#include <sstream>
#include "FlightPlanner.h"

int main() {
    ifstream file1;
    file1.open("../flights.txt"); // open file
    FlightPlanner flightObject; // create FlightPlanner object
    string line; // create a string to store the lines

    if (!file1) { // check to see if file opened
       cout << "Error occurred while reading flights.txt" << endl;
    }
    while (!file1.eof()) { // while not the end of file
        getline(file1, line); // get a line from the file
        istringstream ss(line); // put the string into an istringstream
        string data;
        getline(ss, data , ' ');
        if (data == "CREATE") {
            getline(ss, data , ' ');
            if (data == "DESTINATION") { // checks for create destination command
                getline(ss, data, ' ');
                string code = data;
                getline(ss, data);
                string name = data;
                flightObject.createDestination(code,name); // calls create destination function
            }
            else if (data == "FLIGHT") {  // checks for create flight command
                getline(ss, data, ' ');
                string to = data;
                getline(ss, data, ' ');
                string from = data;
                getline(ss, data);
                int flightNumber = stoi(data);
                flightObject.createFlight(flightNumber, to, from); // calls create flight function
            }
        }
        else if (data == "UPDATE") { // checks for update flight command
            getline(ss, data, ' ');
            if (data == "FLIGHT") {
                getline(ss, data, ' ');
                int flightNumber = stoi(data);
                getline(ss, data);
                string status = data;
                flightObject.updateFlight(flightNumber, status); // calls update flight function
            }
        }
        else if (data == "DISPLAY") { // checks for display status command
            getline(ss, data, ' ');
            if (data == "STATUS") {
                getline(ss, data);
                string airportCode = data;
                flightObject.display(airportCode); // calls display function
            }
        }
    }
    return 0;
}
