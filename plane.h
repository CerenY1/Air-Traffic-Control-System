#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>

using namespace std;
class Plane{
	protected:
		double departureTime;//hareket saati
		double estimatedArrivalTime;
		int travelDuration;//seyehat süresi
		int passengerCapacity;
		double price;
		int speed;
		string model;
		string departureCity;
		string landingCity;
		string planeSt;//uçaðýn durumu(havada mý,kalkacak mý, indi mi)
		
    Plane(const double depTime, int duration, const string mdl, int capacity,double price,string depCity,string landCity)
	: departureTime(depTime), travelDuration(duration), model(mdl), passengerCapacity(capacity), price(price),departureCity(depCity),landingCity(landCity) {}
	
	double calculateArrivalTime(){
		int minute,hours;
		hours = travelDuration/60;
		minute = travelDuration%60;
		estimatedArrivalTime = departureTime+hours+(minute*0.1);
		return estimatedArrivalTime;	
	}
	
	void displayInfo() {
        cout << "Departure Time: " <<fixed<<setprecision(2)<< departureTime << endl;
        cout << "Estimated Arrival Time: " <<fixed<< setprecision(2)<<calculateArrivalTime() << endl;
        cout << "Travel Duration: " << this->travelDuration << endl;
        cout << "Model: " << model << endl;
        cout << "Passenger Capacity: " << passengerCapacity << " passengers" << endl;
        cout << "Price: " << price << "$" << endl;
    }	
    virtual void calculateFlightTime(int distance){
		this->travelDuration= distance / (this->speed);
		cout<<"Estimated travel duration : "<<this->travelDuration<<endl;
	}
}; 

class Pegasus1: public Plane{
	
	public:
	    Pegasus1(const double depTime, int duration, const string mdl, int capacity=2,double price=27.0,const speed= 100)
	    :Plane(depTime, duration, mdl, capacity, price) {}
	
	void disPlayInfo(){
		
	    Plane::displayInfo();
	    
	}
	void calculateFlightTime(int distance)const override{
		this->travelDuration= distance / (this->speed);
		cout<<"Estimated travel duration : "<<this->travelDuration<<endl;
	}
	
}; 

class Pegasus2: public Plane{
	
	public:
	    Pegasus2(const double depTime, int duration, const string mdl, int capacity=5,double price=65.0,speed= 200)
	    :Plane(depTime, duration, mdl, capacity, price) {}
	
	void disPlayInfo(){
		
	    Plane::displayInfo();
	    
	}
	void calculateFlightTime(int distance)const override{
		this->travelDuration= distance / (this->speed);
		cout<<"Estimated travel duration : "<<this->travelDuration<<endl;
	}
	
}; 


class THY1: public Plane{
	
	public:
	    THY1(const double depTime, int duration, const string mdl, int capacity=6,double price=30.0,speed=150)
	    :Plane(depTime, duration, mdl, capacity, price) {}
	
	void disPlayInfo(){
		
	    Plane::displayInfo();
	    
	}
	void calculateFlightTime(int distance)const override{
		this->travelDuration= distance / (this->speed);
		cout<<"Estimated travel duration : "<<this->travelDuration<<endl;
	}
	
}; 

class THY2: public Plane{
	
	public:
	    THY2(const double depTime, int duration, const string mdl, int capacity=4,double price=50.0,speed=250)
	    :Plane(depTime, duration, mdl, capacity, price) {}
	
	void disPlayInfo(){
		
	    Plane::displayInfo();
	    
	}
	void calculateFlightTime(int distance)const override{
		this->travelDuration= distance / (this->speed);
		cout<<"Estimated travel duration : "<<this->travelDuration<<endl;		
	}
	
}; 
#endif

