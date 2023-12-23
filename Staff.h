#ifndef STAFF_H
#define STAFF_H
#include "Plane.h"
//#include "Airports.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Staff{
	protected:
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
				case(2):
					static CargoPlane cargoPlane;	
				case(3):
					static MilitaryPlane militaryPlane;			
			}	
		}
};



















#endif
