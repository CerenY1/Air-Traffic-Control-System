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

public:
    friend class passenger;
    Ticket(string dep = "",string arr = "", int seat = 0, double cost = 0,string dateTime = "", int duration = 0, int identity = 0)
            : departureCity(dep), arrivalCity(arr), seatNum(seat), price(cost), dateAndTime(dateTime), travelDuration(duration), passengerIdentity(identity){}
    virtual void showBill(int ticketPrice){
        cout << "Bill Information:" << endl;
    } // abstraction ya da polimorfizm için tekrar bak.
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
    int ticketNumbers = 0;
    int price = 0;

public:
    int sellTicket(CommercialPlane& commertialPlane){
        int totalPrice = 0;
        if(commertialPlane.checkPlaneSt()){
            cout << "How many tickets do you want to buy?" << endl;
            cin >> ticketNumbers;
            if(commertialPlane.getTicketNum() >= ticketNumbers) {
                if (commertialPlane.getTicketNum() - ticketNumbers >= 0) {
                    commertialPlane.setTicketNum(ticketNumbers);
                    totalPrice = ticketNumbers * (commertialPlane.getTicketPrice());
                    totalPrice = ticketNumbers * 100;
                    cout << ticketNumbers << " ticket(s) is/are sold." << endl;
                    cout << commertialPlane.getTicketNum() - (ticketNumbers) << endl;
                    price = commertialPlane.getTicketPrice();
                    ticketNumbers = 0;
                    commertialPlane.setTicketNum(ticketNumbers);
                }
            }
            else{
                cout << "There is no enough ticket." << endl;
            }
        }
        else{
            cout <<  "Plane is not available."<< endl;
        }
        return totalPrice;
    }
    virtual void showBill(int totalPrice)override{
        cout << "-------------------------" << endl;
        cout << "Ticket price:" << 100 << "$" << endl;
        cout << "Total Price:" << totalPrice << "$" << endl;
        cout << "-------------------------" << endl;
        // cout <<"Plane Information:"<< endl;
    }

};

class CargoTicket : public Ticket{
    int *price;
    int cargoWeight = 0;

public:
    int sellTicket(CargoPlane& plane){
        int totalPrice = 0;
        if(plane.checkPlaneSt())
        {   totalPrice= 0;
            cout << "How many kilograms are your cargo?" << endl;
            cin >> cargoWeight;
            plane.addCargo(cargoWeight);
            totalPrice = plane.getTicketPrice()*cargoWeight;
            *price = plane.getTicketPrice();
        }
        else{
            cout << "Plane is not available." << endl;
        }
        return totalPrice;
    }
    virtual void showBill(int totalPrice)override{
        cout << "-------------------------" << endl;
        cout << "Ticket price:" << 100 << "$" << endl;
        cout << "Total Price: "<< totalPrice << "$" << endl ;
        cout << "-------------------------" << endl;
        cout <<"Plane Information:"<< endl;
    }
};

class PrivateTicket : public Ticket{
    friend class Passenger;
    string name;
    const int ticketPrice=5000;
public:

    void sellTicket(PrivatePlane& privatePlane){
        name = privatePlane.pilotList();
    }
    virtual void showBill(int totalPrice)override{
        cout << "-------------------------" << endl;

        cout << "Pilot Name: "<< name << endl;
        cout<< "Price : " << ticketPrice << "$"<< endl;
    }
};
#endif
//UNTITLED2_TICKET_H

