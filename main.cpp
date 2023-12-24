#include <iostream>
#include <string>
#include <ctime>
#include <iomainip>
#include <vector>
#include "airports.h"
#include "plane.h"
#include "ticket.h"
#include "passenger.h"
#include "meteorology.h
using namespace std;

int main(int argc, char** argv) {
	int choice;
	vector <Plane> planesIst;
	vector <Plane> planesNy;
	vector <Plane> planesPar;
	Airport istanbul;
	Airport paris;
	Airport newyork;
	Meteorology todaysWeather;
	istanbul.setAirportName(istanbul);
	newyork.setAirportName(newyork);
	paris.setAirportName(paris);
	cout<<"choose one:"<<endl<<"1. Staff"<<endl<<"2. Passenger"<<endl;
	cin>>choice;
	
	if(choice){	
		Staff staff;
		Plane* plane = new Plane ;
		plane = staff.takeFlightInfo();	
		if (plane.departureCity == "istanbul"||plane.landingCity== "istanbul"){
			planesIst.push_back(plane);
			if(plane.landingCity == "istanbul")
				istanbul.addArrivingPlaneToAirport(plane);
			else 
				istanbul.addLeavingPlaneToAirport(plane);
		}
		if (plane.departureCity =="paris"||plane.landingCity== "paris"){
			planesPar.push_back(plane);
			if(plane.landingCity == "paris")
				paris.addArrivingPlaneToAirport(plane);
			else 
				paris.addLeavingPlaneToAirport(plane);
		}
		else if (plane.departureCity == "newyork"||plane.landingCity== "newyork"){
			planesNy.push_back(plane);
			if(plane.landingCity == "newyork")
				newyork.addArrivingPlaneToAirport(plane);
			else 
				newyork.addLeavingPlaneToAirport(plane);
		}
	}
	
	else{
		Passenger passenger;
		passenger.enterPassengerInfo();
		int rowNum = 0;
		if (passenger.currentLocation == "istanbul"){
			printWelcomeAirport(todaysWeather);
			while (rowNum == 0) {
    			printAirportInfo();
    			int rowNum;
				cout<<"enter the plane number to buy a ticket:"
				cin>>rowNum;
				if(rowNum >=istanbul.arrivingPlanes.size()){
					rowNum = rowNum - istanbul.arrivingPlanes.size();
					istanbul.leavingPlanes[rowNum];
				}
			 	else istanbul.arrivingPlanes[rowNum];
    			cout << "waiting for update..." <<endl;
    			cin>>opNum;
    			time_t start_time = time(NULL);
    			while (time(NULL) - start_time < 60) {}
    		}
		}
		else if (passenger.currentLocation =="paris"){
			printWelcomeAirport(todaysWeather);
			while (rowNum == 0) {
    			printAirportInfo();
    			int rowNum;
				cout<<"enter the plane number to buy a ticket:"
				cin>>rowNum;
				if(rowNum >=paris.arrivingPlanes.size()){
					rowNum = rowNum - paris.arrivingPlanes.size();
					paris.leavingPlanes[rowNum];
				}
			 	else paris.arrivingPlanes[rowNum];
    			cout << "waiting for update..." <<endl;
    			cin>>opNum;
    			time_t start_time = time(NULL);
    			while (time(NULL) - start_time < 60) {}
    		}
			
		}
		else if (passenger.currentLocation == "newyork"){
			printWelcomeAirport(todaysWeather);
			while (rowNum == 0) {
    			printAirportInfo();
    			int rowNum;
				cout<<"enter the plane number to buy a ticket:"
				cin>>rowNum;
				if(rowNum >=newyork.arrivingPlanes.size()){
					rowNum = rowNum - newyork.arrivingPlanes.size();
					newyork.leavingPlanes[rowNum];
				}
			 	else newyork.arrivingPlanes[rowNum];
    			cout << "waiting for update..." <<endl;
    			cin>>opNum;
    			time_t start_time = time(NULL);
    			while (time(NULL) - start_time < 60) {}
    		}
			
		}
		else 
		cout << "location not found.."<< endl;
	}
	return 0;
}
