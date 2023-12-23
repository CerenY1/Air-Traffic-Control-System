#ifndef STAFF_H
#define STAFF_H
#include "Plane.h"
#include "Airports.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

class Staff{
	protected:
		void enterFlight(Plane& plane){	
			void compareTimes(const tm& staffTime, const tm& currentTime,const int duration) {
    				time_t staffTimeSeconds = userTime.tm_hour * 3600 + staffTime.tm_min * 60;
    				time_t currentTimeSeconds = currentTime.tm_hour * 3600 + currentTime.tm_min * 60;
				if (userTimeSeconds > currentTimeSeconds) 
        				plane.PlaneSt = "Available";
    				else if (userTimeSeconds > currentTimeSeconds + duration * 60) 
        				plane.PlaneSt = "On Air";
    				else 
        				plane.PlaneSt = "Landed";   
			}	
			string formatTime(const tm& time, const string& format) {
    				char array1[10];
    				strftime(array1, sizeof(array1), format.c_str(), &time);
    				return string(array1);
			}
			tm addDurationMinutes(const tm& time, int duration) {
    				tm arrivalTime = time;
    				arrivalTime.tm_min  += duration;
    				mktime(&arrivalTime);  
    				return arrivalTime;
			}	
			int hour, minute,duration;
    			cout<<"Enter the city of departure:"<<endl;
			cin>>plane.departureCity;
			cout<<"Enter the city where the plane will land:"<<endl;
			cin>>plane.landingCity;
			duration = Airport::findDistance(plane.departureCity,plane.landingCity);
    
    			tm staffTime = {};
    			userTime.tm_hour = hour;
   			userTime.tm_min = minute;
    
    			tm result1 = addDurationMinutes(staffTime,duration);
    			time_t t = time(0);
    			tm* currentTime = localtime(&t);
    
    			cout << "Departure Time is set to: " << formatTime(staffTime, "%H:%M") <<endl;
    			cout << "Arrival Time is set to: " << formatTime(result1, "%H:%M") <<endl;
   			compareTimes(staffTime, *currentTime,duration);
    			cout << "The plane is now: " << plane.PlaneSt <<endl;
}
		void takeFlightInfo(){
			int planeNum,hours, flightTime;
			cout<< "Choose a plane:" <<endl;
			cout<< "1-> Commertial Plane"<<endl;
			cout<< "2-> Cargo Plane"<<endl;
			cout<< "3-> Military Plane"<<endl;
			cin>> planeNum;
				switch(planeNum){
				case(1):
					static CommertialPlane commertialPlane;
					enterFlight(commertialPlane);
				case(2):
					static CargoPlane cargoPlane;
					enterFlight(cargoPlane);
				case(3):
					static MilitaryPlane militaryPlane;
					enterFlight(militaryPlane);
			}	
		}
};



















#endif
