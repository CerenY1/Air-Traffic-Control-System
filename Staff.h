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
    void enterFlight(Plane &plane) {
        int duration;
        cout << "Enter the city of departure:" << endl;
        cin >> plane.departureCity;
        cout << "Enter the city where the plane will land:" << endl;
        cin >> plane.landingCity;
        duration = plane.calculateArrivalTime(plane.getArrivalCity(), plane.getDepartureCity());

        tm durationTime = {};
        durationTime.tm_hour = duration / 60;
        durationTime.tm_min = duration % 60;

        tm staffTime;
        cout << "Enter flight time: " << endl;
        cin >> staffTime.tm_hour >> staffTime.tm_min;

        // Move this line after reading input for staffTime
        plane.setDepartureTime(staffTime);

        int totalMinutes = durationTime.tm_hour * 60 + durationTime.tm_min +
                           staffTime.tm_hour * 60 + staffTime.tm_min;

        tm totalTime = {};
        totalTime.tm_hour = totalMinutes / 60;
        totalTime.tm_min = totalMinutes % 60;
        plane.setArrivalTime(totalTime);


        tm currentTime = getCurrentTime();  // Store the result in a local variable
        tm departureTime = plane.getDepartureTime();
        tm estimatedArrivalTime = plane.getEstimatedArrivalTime();

        if (mktime(&currentTime) >= mktime(&departureTime) &&
            mktime(&currentTime) <= mktime(&estimatedArrivalTime)) {
            plane.PlaneSt = "Landed";
        } else if (mktime(&currentTime) < mktime(&departureTime)) {
            plane.PlaneSt = ("Available");
        } else {
            plane.PlaneSt = ("Unknown");
        }

        cout << "Estimated arrival time: " << plane.getEstimatedArrivalTime().tm_hour
             << ":" << plane.getEstimatedArrivalTime().tm_min << endl;
        cout << plane.getPlaneSt()<<endl;
    }

    static tm getCurrentTime() {
        time_t now = time(nullptr);
        return *localtime(&now);
    }


    string takeFlightInfo() {
        int planeNum;
        string str;
        cout << "Choose a plane:" << endl;
        cout << "1-> Commercial Plane" << endl;
        cout << "2-> Cargo Plane" << endl;
        cout << "3-> Private Plane" << endl;
        cin >> planeNum;
        switch(planeNum) {
            case 1:
                str =  "commercialPlane";
                break;
            case 2:
                str = "cargoPlane";
                break;
            case 3:
                str = "privatePlane";
                break;
        }
        return str;
    }
};
#endif //UNTITLED2_STAFF_H
