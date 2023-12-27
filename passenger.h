#ifndef UNTITLED2_PASSENGER_H
#define UNTITLED2_PASSENGER_H

#include <vector>
#include "ticket.h"
#include <iostream>
using namespace std;

class Passenger{
private:
    string name;
    string gender;
    int age;
    string currentLocation;
    string arrivalLocation;

public:
    friend class Ticket;
    vector<CargoTicket> CargoTickets;
    vector<CommercialTicket> CommercialTickets;
    Passenger() : name(""), gender(""), age(0) {}
    string getName() { return name;}
    string getGender() { return gender;}
    int getAge() { return age;}
    void setName(string name1) { this->name = name1; }
    void setGender(string gender1) { this->gender = gender1; }
    void setAge(int age1) { this->age = age1; }
    void disPlayInfoCommercial(){
        cout << "Passenger's name:" << name << endl;
    }
    void disPlayInfoCargo(){
        cout << "Send by:" << name << endl;
    }
    void disPlayInfoPrivate(){
        cout << "Plane owner:" << name << endl;
    }
    void addCargoTicket(CargoTicket& cargoTicket) {
        CargoTickets.push_back(cargoTicket);
    }

    void addCommercialTicket(CommercialTicket& commercialTicket) {
        CommercialTickets.push_back(commercialTicket);
    }
    void enterPassengerInfo(){
        cout << "Enter fly from: ";
        cin >> currentLocation;
        cout << "Enter fly to: ";
        cin >> arrivalLocation;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin,name);
        cout << "Enter your gender (M/F) :";
        cin >> gender;
        cout << "Enter your age: ";
        cin >> age; // 18 yaşından büyük küçük olma durumuna sonra bak.
    }

    string getCurrentLocation(){
        return currentLocation;
    }
    string getArrivalLocation(){
        return arrivalLocation;
    }
};

#endif //UNTITLED2_PASSENGER_H
