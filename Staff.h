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
    string compareTimes(const tm &staffTime, const tm &currentTime, const int duration, Plane &plane) {
        time_t staffTimeSeconds = staffTime.tm_hour * 3600 + staffTime.tm_min * 60;
        time_t currentTimeSeconds = currentTime.tm_hour * 3600 + currentTime.tm_min * 60;

        try {
            if (staffTimeSeconds > currentTimeSeconds) {
                plane.PlaneSt = "Available";
                cout << "Departure Time is set to: " << formatTime(staffTime, "%H:%M") << endl;
                cout << "Arrival Time is set to: " << formatTime(plane.estimatedArrivalTime, "%H:%M") << endl;
                return "Available";
            }
            else
                throw runtime_error("ERROR");
        } catch (const exception &e) {
            return " NOT available. Wrong time adjusment!";
        }
    }
    string formatTime(const tm &time, const string &format) {
        char array1[10];
        strftime(array1, sizeof(array1), format.c_str(), &time);
        return string(array1);
    }
    tm addDurationMinutes(const tm &time, int duration) {
        tm arrivalTime = time;
        arrivalTime.tm_min += duration;
        mktime(&arrivalTime);
        return arrivalTime;
    }
    void enterFlight(Plane &plane) {
        int hour, minute, duration;
        cout << "Enter the city of departure:" << endl;
        cin >> plane.departureCity;
        cout << "Enter the city where the plane will land:" << endl;
        cin >> plane.landingCity;
        duration = plane.calculateArrivalTime(plane.landingCity,plane.departureCity);

        tm staffTime = {};
        cout << "Enter the departure hour: ";
        cin >> hour >> minute;
        staffTime.tm_hour = hour;
        staffTime.tm_min = minute;

        tm result1 = addDurationMinutes(staffTime, duration);
        time_t t = time(0);
        tm *currentTime = localtime(&t);

        string st1;
        st1 = compareTimes(staffTime, *currentTime, duration, plane);
        cout << "The plane is now: " << st1 << endl;
    }
    string takeFlightInfo() {
        int planeNum;
        string str;
        cout << "Choose a plane:" << endl;
        cout << "1-> Commercial Plane" << endl;
        cout << "2-> Cargo Plane" << endl;
        cout << "3-> Military Plane" << endl;
        cin >> planeNum;
        switch(planeNum) {
            case 1:
                str =  "commercialPlane";
                break;
            case 2:
                str = "cargoPlane";
                break;
            case 3:
                str = "militaryPlane";
                break;
        }
        return str;
    }
};
#endif //UNTITLED2_STAFF_H
