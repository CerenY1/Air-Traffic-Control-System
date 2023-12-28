#ifndef UNTITLED2_AIRPORT_H
#define UNTITLED2_AIRPORT_H
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "plane.h"
#include "meteorology.h"
using namespace std;

class Airport{
private:
    string airportName;

public:
    vector <CommercialPlane> CommercialPlanes;
    vector <CargoPlane>CargoPlanes;
    vector <MilitaryPlane> MilitaryPlanes;

    Airport(const string name):airportName(name){}

    void printWelcomeAirport(Meteorology& todaysWeather){
        cout<<"-------------welcome to "<< this->airportName <<" airport--------------"<<endl;
        todaysWeather.printWeatherInfo();
        time_t timeNow = time(NULL);
        cout << "TIME : " << ctime(&timeNow);
    }
    void setAirportName(string name){
        airportName = name;
    }
    string formatTime(const tm &time) {
        ostringstream oss;
        oss << setfill('0') << setw(2) << time.tm_hour << ":" << setw(2) << time.tm_min;
        return oss.str();
    }
    void printAirportInfo(){
        time_t timeNow1 = time(NULL);
        int rowNum = 1;
        cout << left << setw(10) << "Flight"
             << left << setw(20) << "Model"
             << left << setw(15) << "Departure City"
             << left << setw(15) << "Landing City"
             << left << setw(15) << "Departure Time"
             << left << setw(15) << "Arrival Time"
             << left << setw(15) << "Status" << endl;

        for (const auto& plane : CommercialPlanes) {
            cout << left << setw(10) << rowNum++
                 << left << setw(20) << plane.model
                 << left << setw(15) << plane.departureCity
                 << left << setw(15) << plane.landingCity
                 << left << setw(15) << formatTime(plane.departureTime)
                 << left << setw(15) << formatTime(plane.estimatedArrivalTime)
                 << left << setw(15) << plane.PlaneSt << endl;
        }

        for (const auto& plane : CargoPlanes) {
            cout << left << setw(10) << rowNum++
                 << left << setw(20) << plane.model
                 << left << setw(15) << plane.departureCity
                 << left << setw(15) << plane.landingCity
                 << left << setw(15) << formatTime(plane.departureTime)
                 << left << setw(15) << formatTime(plane.estimatedArrivalTime)
                 << left << setw(15) << plane.PlaneSt << endl;
        }

    }
    void addPlaneToAirport(CargoPlane& p1) {
        CargoPlanes.push_back(p1);

    }
    void addPlaneToAirport(CommercialPlane& p1){
        CommercialPlanes.push_back(p1);
    }

    void addPlaneToAirport(MilitaryPlane& p1){
        MilitaryPlanes.push_back(p1);
    }
};
#endif //UNTITLED2_AIRPORT_H
