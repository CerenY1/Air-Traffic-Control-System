#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <string>
#include "plane.h"
#include "passenger.h"

using namespace std;

class Ticket{
private:
	string departureCity;
	string arrivalCity;
	int seatNum;
    double price;
    string dateAndTime;
    int travelDuration;
    string passengerIdentity;
    
    Ticket(string departure, string arrival, int seat, double cost, string dateTime, int duration) : departureCity(departure), arrivalCity(arrival),
	seatNum(seat), price(cost),dateAndTime(dateTime), travelDuration(duration), passengerIdentity(identity) {}
public:
	virtual void sellTicket() = 0;
	virtual void showBill() = 0; // abstraction ya da polimorfizm için tekrar bak.
	Passenger passenger;
		bool checkPlaneSt(Plane& plane)
	{
		if(plane.planeSt == "Available")
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	virtual ~Ticket(){}
	
};

class CommercialTicket : public Ticket{
	friend class Plane;
	friend class Passenger;
	int *ticketNumbers;
	int price = 0;

	void sellTicket(Plane& plane)override
	{ 
	passenger.enterPassengerInfo();
	cout << "Enter your gender (M/F) :";
	cin >> gender;
	cout << "Enter your age: ";
	cin >> age; // 18 yaşından büyük küçük olma durumuna sonra bak.	
		if(checkPlaneSt())
		{
			cout << "How many tickets do you want to buy?" << endl;
			cin >> *ticketNumbers;
			if(plane.numOfTicket - *ticketNumbers >=0)
			{
			plane.numOfTicket -= *ticketNumbers;
			price = ticketNumbers * plane.ticketPrice;
			cout << ticketNumbers << " ticket(s) is/are sold." << endl;
			Passenger :: addTicket(Ticket& ticket) //devam edicez.
			}
			else
			{
				cout << "There is no enough ticket." << endl;
			}
		}
		else
		{
			cout <<  "Plane is not available."<< endl;
		}
	}
	void showBill(Plane& plane)override{
		cout << "Bill Information:" << endl;
		passenger.disPlayInfoCommercial();
		cout << "Ticket price:" << price << endl;
		cout << "-------------------------" << endl;
		cout <<"Plane Information:"<< endl;
		friend void enterFlight(Plane& plane);
	}
	
};

class CargoTicket : public Ticket{
	friend class Passenger;
	passenger.enterPassengerInfo();
	int price=0;
	void sellTicket(Plane& plane)override
	{
		if(checkPlaneSt())
		{
		int cargoWeight;
		cout << "How many kilograms are your cargo?" << endl;
		cin >> cargoWeight;
		CargoPlane.addCargo(cargoWeight);
		price = CargoPlane.ticketPrice*cargoWeight; 
		}
		else
		{
			cout << "Plane is not available." << endl;
		}
	}
	void showBill(Plane& plane)override{
		cout << "Bill Information:" << endl;
		passenger.disPlayInfoCargo();
		cout << "Price : " <<price<<endl;
		
	}
};

class PrivateTicket : public Ticket{
	friend class Passenger;
	const int ticketPrice=5000;
	void sellTicket(PrivatePlane& privatePlane)override
	{
		privatePlane.pilotList();
		passenger.disPlayInfoPrivate();
	}
	
	void showBill
};


#endif
