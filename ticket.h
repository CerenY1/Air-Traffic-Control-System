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
    string dateAndTime;
public:
    friend class passenger;
    Ticket(string dep = "",string arr = "", int seat = 0, double cost = 0,string dateTime = "", int duration = 0, int identity = 0)
            : departureCity(dep), arrivalCity(arr), dateAndTime(dateTime){}
    virtual void showBill(int ticketPrice){
        cout << "Bill Information:" << endl;
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
        if(commertialPlane.getPlaneSt()  == "Available"){
            cout << "How many tickets do you want to buy?" << endl;
            cin >> ticketNumbers;
            if(commertialPlane.getTicketNum() >= ticketNumbers) {
                commertialPlane.setTicketNum(ticketNumbers);
                totalPrice = ticketNumbers * 250;
                cout << ticketNumbers << " ticket(s) is/are sold." << endl;
                price = commertialPlane.getTicketPrice();
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
    void showBill(int totalPrice)override{
        cout << "-------------------------" << endl;
        cout << "Ticket price:" << 250 << "$" << endl;
        cout << "Total Price:" << totalPrice << "$" << endl;
        cout << "-------------------------" << endl;
    }
};

class CargoTicket : public Ticket{
    int cargoWeight = 0;
public:
    int sellTicket(CargoPlane& plane) {
        int totalPrice = 0;
        if (plane.getPlaneSt() == "Available") {
            cout << "How many kilograms are your cargo?" << endl;
            cin >> cargoWeight;
            if (plane.getCargoCapacity() >= cargoWeight) {
                totalPrice = 0;
                plane.addCargo(cargoWeight);
                totalPrice = 100 * cargoWeight;
            }
        }
        else
            cout << "Plane is not available." << endl;
        return totalPrice;
    }
    void showBill(int totalPrice)override{
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
   int sellTicket(PrivatePlane& plane){
        name = plane.pilotList();
        cout<<"ticket price for private plane: 500 $."<<endl;
        cout<<"1 ticket for private plane is sold..."<<endl;
        plane.displayInfo();
        return 1;
    }
    void showBill(int totalPrice)override{
        cout << "-------------------------" << endl;
        cout<< "Price : " << ticketPrice << "$"<< endl;

    }
};
#endif
//UNTITLED2_TICKET_H
