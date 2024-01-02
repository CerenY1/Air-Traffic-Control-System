#ifndef UNTITLED2_STAFF_H
#define UNTITLED2_STAFF_H
#include "plane.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

class Staff {
public:
    void enterFlight(Plane& plane) {
        int duration;
        cout << "Enter the city of departure (istanbul,paris,newyork): " << endl;
        cin >> plane.departureCity;
        cout << "Enter the city where the plane will land (istanbul,paris,newyork):" << endl;
        cin >> plane.landingCity;

        duration = plane.calculateArrivalTime(plane.landingCity, plane.departureCity);

        tm durationTime = {};
        durationTime.tm_hour = duration / 60;
        durationTime.tm_min = duration % 60;

        tm staffTime;
        cout << "Enter flight time (HH MM): " << endl;
        cin >> staffTime.tm_hour >> staffTime.tm_min;

        plane.setDepartureTime(staffTime);

        time_t currentTime = time(nullptr);
        tm* timeStruct = localtime(&currentTime);

        int totalMinutes = durationTime.tm_hour * 60 + durationTime.tm_min +
                           staffTime.tm_hour * 60 + staffTime.tm_min;
        tm totalTime = {};
        totalTime.tm_hour = totalMinutes / 60;
        totalTime.tm_min = totalMinutes % 60;

        plane.setArrivalTime(totalTime);
        tm departureTime = plane.getDepartureTime();
        tm estimatedArrivalTime;
        estimatedArrivalTime.tm_hour = departureTime.tm_hour + durationTime.tm_hour;
        estimatedArrivalTime.tm_min = departureTime.tm_min + durationTime.tm_min;

        int departureMinutes = departureTime.tm_hour * 60 + departureTime.tm_min;
        int arrivalMinutes = estimatedArrivalTime.tm_hour * 60 + estimatedArrivalTime.tm_min;
        int currentMinutes = timeStruct->tm_hour*60+ timeStruct->tm_min;

        if (currentMinutes >= departureMinutes && currentMinutes < arrivalMinutes) {
            plane.setPlaneSt("On the air");
        } else if (currentMinutes >= arrivalMinutes) {
            plane.setPlaneSt("Landed");
        } else {
            plane.setPlaneSt("Available");
        }
        cout << "Departure time: "<<plane.getDepartureTime().tm_hour <<":"<<plane.getDepartureTime().tm_min<<endl;
        cout << "Estimated arrival time: " << plane.getEstimatedArrivalTime().tm_hour
                  << ":" << plane.getEstimatedArrivalTime().tm_min << endl;
        cout << "Plane is now: " << plane.getPlaneSt() <<endl;
    }
    string takeFlightInfo() {
        int planeNum;
        string str;
        cout << "Choose a plane:" << endl;
        cout << "1-> Commercial Plane" << endl;
        cout << "2-> Cargo Plane" << endl;
        cin >> planeNum;
        switch(planeNum) {
            case 1:
                str =  "commercialPlane";
                break;
            case 2:
                str = "cargoPlane";
                break;
        }
        return str;
    }
};
#endif //UNTITLED2_STAFF_H
