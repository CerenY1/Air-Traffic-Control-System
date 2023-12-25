#ifndef UNTITLED2_TICKET_H
#define UNTITLED2_TICKET_H
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
    int passengerIdentity;

    Ticket(string dep = "", string arr = "", int seat = 0, double cost =0 , string dateTime = "", int duration = 0 ,int identity = 0) : departureCity(dep),
    arrivalCity(arr), seatNum(seat), price(cost),dateAndTime(dateTime), travelDuration(duration), passengerIdentity(identity) {}
public:
    friend class passenger;
    virtual void showBill(Plane& plane) = 0; // abstraction ya da polimorfizm için tekrar bak.
    Passenger passenger;
    bool checkPlaneSt(Plane& plane)
    {
        if(plane.PlaneSt == "Available")
            return 1;
        else
            return 0;
    }
    virtual ~Ticket(){}

};

class CommercialTicket : public Ticket{
    friend class Plane;
    friend class Passenger;
    int *ticketNumbers;
    int price = 0;
public:
     void sellTicket(Passenger& passenger, CommercialPlane& commertialPlane)
    {   string name,gender;
        int age;
        passenger.enterPassengerInfo();
        cout << "Enter your gender (M/F) :";
        cin>>name;
        passenger.setName(name);
        cout << "Enter your age: ";
        cin >> age;
        passenger.setAge(age);// 18 yaşından büyük küçük olma durumuna sonra bak.
        if(commertialPlane.checkPlaneSt(commertialPlane))
        {
            cout << "How many tickets do you want to buy?" << endl;
            cin >> *ticketNumbers;
            if(commertialPlane.getTicketNum()- *ticketNumbers >=0)
            {
                commertialPlane.setTicketNum(*ticketNumbers);
                price = ticketNumbers * commertialPlane.getTicketPrice();
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
    virtual void showBill(Plane& plane)override{
        cout << "-------------------------" << endl;
        cout << "Bill Information:" << endl;
        passenger.disPlayInfoCommercial();
        cout << "Ticket price:" << price << "$" << endl;
        cout << "-------------------------" << endl;
        cout <<"Plane Information:"<< endl;
    }
};

class CargoTicket : public Ticket{

    friend class Passenger;
    int price=0;
public:
    Passenger.enterPassengerInfo();
    void sellTicket(Passenger& passenger, CargoPlane& plane)
    {
        if(plane.checkPlaneSt(plane))
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
    virtual void showBill(Plane& plane)override
    {
        cout << "-------------------------" << endl;
        cout << "Bill Information:" << endl;
        passenger.disPlayInfoCargo();
        cout << "Price : " << price << "$" << endl;

    }
};

class PrivateTicket : public Ticket{
    friend class Passenger;
    const int ticketPrice=5000;
public:

    void sellTicket(PrivatePlane& privatePlane)   {
        privatePlane.pilotList();
        passenger.disPlayInfoPrivate();
    }

    virtual void showBill(Plane& plane)override
    {
        cout << "-------------------------" << endl;
        cout << "Bill Information:" << endl;
        passenger.disPlayInfoPrivate();
        cout<< "Price : " << ticketPrice << "$"<< endl;

    }
};


#endif

#endif //UNTITLED2_TICKET_H
