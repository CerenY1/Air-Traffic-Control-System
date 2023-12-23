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
			cout<< "1-> Pegasus 1"<<endl;
			cout<< "2-> Pegasus 2"<<endl;
			cout<< "3-> THY 1"<<endl;
			cout<< "4-> THY 2"<<endl;
			cin>> planeNum;
			/*	switch(planeNum){
				case(1):
					static Pegasus1 pegasus1;
					cout<<"Enter the city of departure:"<<endl;
					cin>>pegasus1.departureCity;
					cout<<"Enter the city where the plane will land:"<<endl;
					cin>>pegasus1.landingCity;
					Airport.findDistance(pegasus1.departureCity,pegasus1.landingCity);
				case(2):
					static Pegasus2 pegasus2;
					cout<<"Enter the city of departure:"<<endl;
					cin>>pegasus2.departureCity;
					cout<<"Enter the city where the plane will land:"<<endl;
					cin>>pegasus2.landingCity;
					Airport.findDistance(pegasus2.departureCity,pegasus2.landingCity);
				case(3):
					static THY1 thy1;
					cout<<"Enter the city of departure:"<<endl;
					cin>>thy1.departureCity;
					cout<<"Enter the city where the plane will land:"<<endl;
					cin>>thy1.landingCity;
					Airport.findDistance(thy1.departureCity,thy1.landingCity);
				case(4):
					static THY2 thy2;
					cout<<"Enter the city of departure:"<<endl;
					cin>>thy2.departureCity;
					cout<<"Enter the city where the plane will land:"<<endl;
					cin>>thy2.landingCity;		
					Airport.findDistance(thy2.departureCity,thy2.landingCity);
			}*/	
		}
};



















#endif
