#include <iostream>
#include <string>
#include <plane.h>
#include <passenger.h>

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
	Passenger passenger;
	passenger.
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
		cout << "Passenger's name:" << passenger.name << endl;
		cout << "Ticket price:" << price << endl;
		cout << "-------------------------" << endl;
		cout <<"Plane Information:"<< endl;
		friend void enterFlight(Plane& plane);
	}
	
};

class CargoTicket : public Ticket{
	friend class Passenger;
	void sellTicket(Plane& plane)override
	{
		if(checkPlaneSt())
		{
		int cargoWeight;
		cout << "How many kilograms are your cargo?" << endl;
		cin >> cargoWeight;
		CargoPlane.addCargo(cargoWeight);
		}
		else
		{
			cout << "Plane is not available." << endl;
		}
	}
	void showBill(Plane& plane)override{
		//plane bilgileri ve bill information, kg başına fiyat
	}
};

class PrivateTicket : public Ticket{
	friend class Passenger;
	void sellTicket(Plane& plane)override
	{
		
	}
};
	{
		
	}
};
