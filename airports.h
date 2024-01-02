#ifndef UNTITLED2_AIRPORT_H
#define UNTITLED2_AIRPORT_H
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "plane.h"
#include "meteorology.h"
using namespace std;

class Airport {
private:
    string airportName;
public:
    vector<CommercialPlane> CommercialPlanes;
    vector<CargoPlane> CargoPlanes;
    vector<PrivatePlane> PrivatePlanes;

    Airport(const string name) : airportName(name) {}

    void printWelcomeAirport(Meteorology& todaysWeather) {
        cout << "---WELCOME TO " << airportName << " AIRPORT---" << endl<<endl<<endl;
        todaysWeather.printWeatherInfo();
        time_t currentTime = time(NULL);
        cout << setfill(' ') << "TIME : " << ctime(&currentTime);
    }
    string formatTime(const tm &time) {
        ostringstream oss;
        oss << setfill('0') << setw(2) << time.tm_hour << ":" << setw(2) << time.tm_min;
        return oss.str();
    }
    void printAirportInfo() {
        int rowNum = 1;
        cout << left << setw(10) << "Flight"
             << left << setw(20) << "Model"
             << left << setw(15) << "Departure City"
             << left << setw(15) << "Landing City"
             << left << setw(15) << "Departure Time"
             << left << setw(15) << "Arrival Time"
             << left << setw(15) << "Status"
             << left << setw(15) << "Price" << endl;
        for (const auto &plane : CommercialPlanes) {

            cout << left << setw(10) << rowNum++
                 << left << setw(20) << "Commercial Plane"
                 << left << setw(15) << plane.departureCity
                 << left << setw(15) << plane.landingCity
                 << left << setw(15) << formatTime(plane.departureTime)
                 << left << setw(15) << formatTime(plane.estimatedArrivalTime)
                 << left << setw(15) << plane.PlaneSt
                 << left << setw(15) << "100$" << endl;
        }
        for (const auto &plane : CargoPlanes) {
            cout << left << setw(10) << rowNum++
                 << left << setw(20) << "Cargo Plane"
                 << left << setw(15) << plane.departureCity
                 << left << setw(15) << plane.landingCity
                 << left << setw(15) << formatTime(plane.departureTime)
                 << left << setw(15) << formatTime(plane.estimatedArrivalTime)
                 << left << setw(15) << plane.PlaneSt
                 << left << setw(15) << "150$" << endl;
        }
    }
    void addPlaneToAirport(CargoPlane &p1){
        CargoPlanes.push_back(p1);
    }
    void addPlaneToAirport(CommercialPlane &p1) {
        CommercialPlanes.push_back(p1);
    }
    void addPlaneToAirport(PrivatePlane &p1) {
        PrivatePlanes.push_back(p1);
    }
};
#endif //UNTITLED2_AIRPORT_H
