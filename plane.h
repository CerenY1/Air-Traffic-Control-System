#ifndef PLANE_H
#define PLANE_H
#include "Staff.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;
class Plane{
	protected:
		tm departureTime;//hareket saati
		tm estimatedArrivalTime;
		int travelDuration;//seyehat süresi
		int passengerCapacity;
		double price;
		string model;
		string departureCity;
		string landingCity;
		
    Plane(tm depTime,tm estimatedArrivalTime, int duration, const string mdl, int capacity,double price,string depCity,string landCity)
	: departureTime(depTime), travelDuration(duration), model(mdl), passengerCapacity(capacity), price(price),departureCity(depCity),landingCity(landCity) {}
	
	/*double calculateArrivalTime(){
		int minute,hours;
		hours = travelDuration/60;
		minute = travelDuration%60;
		estimatedArrivalTime = departureTime+hours+(minute*0.1);
		return estimatedArrivalTime;
		
	}*/
	
	void displayInfo() {
       // cout << "Departure Time: " <<fixed<<setprecision(2)<< departureTime << endl;
       // cout << "Estimated Arrival Time: " <<fixed<< setprecision(2)<<calculateArrivalTime() << endl;
       // cout << "Travel Duration: " << travelDuration/60 <<"."<< travelDuration%60<<" hours " << endl;
        cout << "Model: " << model << endl;
        cout << "Passenger Capacity: " << passengerCapacity << " passengers" << endl;
        cout << "Price: " << price << "$" << endl;
		cout<< "-------------------------------------------" <<endl;
        
    }	
}; 

class CommercialPlane : public Plane{
	public:
	
    CommercialPlane(tm deptime, tm estArrivalTime, int duration, const string mdl, int capacity, double price, string depCity, string landCity)
    : Plane(deptime, estArrivalTime, duration, mdl, capacity, price, depCity, landCity) {}

    void disPlayInfo(){
		
	    Plane::displayInfo();
	    
	}

};

class PrivatePlane : public Plane {
public:
	friend class Staff;
	
	string pilotName;

    PrivatePlane(/*tm depTime, tm estArrivalTime,*/ int duration, const string mdl, int capacity)
    : Plane(/*deptime, estArrivalTime,*/ duration, mdl, capacity) {}

    void pilotList(){
    	cout<<"Choose pilot name: "<<endl;
    	
    }
    
  

    void displayInfo() {
        Plane::displayInfo();
        cout << "Pilot: " << pilotName << std::endl;
    }
    
    void setPilotName(const string pilot) {
        pilotName = pilot;
    }
};

class CargoPlane : public Plane {
public:
    double cargoCapacity;
    double currentCargoWeight;

    CargoPlane(/*tm depTime, tm estArrivalTime,*/ int duration, const string mdl, int capacity, double cargoCap)
        : Plane(/*depTime, estArrivalTime,*/ duration, mdl, capacity), cargoCapacity(cargoCap) {}

    void displayInfo() {
        Plane::displayInfo();
        std::cout << "Cargo Capacity: " << cargoCapacity << " tons" << std::endl;
    
    
    void addCargo(double weight) {
        if (currentCargoWeight + weight <= cargoCapacity) {
            currentCargoWeight += weight;
            cout << "Cargo added. Current Cargo Weight: " << currentCargoWeight << " tons" << std::endl;
        } 
		else 
            cout << "Cargo not added. Exceeds cargo capacity." << std::endl;
        
	    }
    }
};

class MilitaryPlane : public Plane {
public:
    int weaponCapacity;
    string missionType;

    MilitaryPlane(/*tm depTime, tm estArrivalTime,*/ int duration, const string mdl, int capacity, int weaponCap)
        : Plane(depTime, estArrivalTime, duration, mdl, capacity), weaponCapacity(weaponCap) {}
        
    void displayInfo() {
        Plane::displayInfo();
        std::cout << "Weapon Capacity: " << weaponCapacity << " units" << std::endl;
    }
    
    void setMissionType(const string mission) {
        missionType = mission;
    }
};


#endif
