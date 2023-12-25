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
    const int istToPar = 300;
    const int istToNy = 200;
    const int parToNy = 250;
public:
    Airport(const string name):airportName(name){}

    void printWelcomeAirport(Meteorology& todaysWeather){
        cout<<"-------------welcome to "<<this->airportName <<" airport--------------"<<endl<<endl<<endl;
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
    void printAirportInfo(vector <Plane> arrivingPlanes,vector <Plane> leavingPlanes){
        time_t timeNow1 = time(NULL);
        int rowNum = 1;
        cout<<left<<setw(20) <<"Flight Number"
            <<setw(20)	<< "Flight"
            <<setw(20) << "Departure City"
            <<setw(20)<< "Landing City"
            <<setw(20) << "Departure Time"
            <<setw(20) << "Arrival Time"
            <<setw(20)<<"Status"<< endl;
        for (const auto& plane : arrivingPlanes) {

            cout<< setw(5) << rowNum++
                <<setw(20)<<plane.model
                <<setw(20)<<plane.departureCity
                <<setw(20)<<plane.landingCity
                <<setw(20)<<formatTime(plane.departureTime)
                <<setw(20)<<formatTime(plane.estimatedArrivalTime)
                <<setw(20)<<plane.PlaneSt<<endl;
        }
        for (const auto& plane : leavingPlanes) {

            cout<< setw(5) << rowNum++
                <<setw(20)<<plane.model
                <<setw(20)<<plane.departureCity
                <<setw(20)<<plane.landingCity
                <<setw(20)<<formatTime(plane.departureTime)
                <<setw(20)<<formatTime(plane.estimatedArrivalTime)
                <<setw(20)<<plane.PlaneSt<<endl;
        }
    }
    void addArrivingPlaneToAirport(Plane p1,vector <Plane> arrivingPlanes){
        arrivingPlanes.push_back(p1);
    }
    void addLeavingPlaneToAirport(Plane p1,vector <Plane> leavingPlanes){
        leavingPlanes.push_back(p1);
    }
    int findDistance(string city1, string city2){

        if((city1 == "istanbul" && city2 == "newyork")||(city1 == "newyork" && city2 == "istanbul"))
            return istToNy;
        else if ((city1 == "istanbul" && city2 == "paris")||(city1 == "paris" && city2 == "istanbul"))
            return istToPar;
        else if ((city1 == "paris" && city2 == "newyork")||(city1 == "newyork" && city2 == "paris"))
            return parToNy;
    }
};
#endif //UNTITLED2_AIRPORT_H
