#ifndef UNTITLED2_PASSENGER_H
#define UNTITLED2_PASSENGER_H

#include <vector>
#include <iostream>
#include "ticket.h"
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
    void addCargoTicket(CargoTicket& cargoTicket) {
        CargoTickets.push_back(cargoTicket);
    }
    void addCommercialTicket(CommercialTicket& commercialTicket) {
        CommercialTickets.push_back(commercialTicket);
    }
    void enterPassengerInfo(){
        cout <<"Fly from (istanbul,paris,newyork) :"<<endl;
        cin >> currentLocation;
        cout <<"Fly to (istanbul,paris,newyork):"<<endl;
        cin >> arrivalLocation;
        cout <<"Enter your name :"<<endl;
        cin.ignore();
        getline(cin,name);
        cout <<"Enter your gender (M/F) :"<<endl;
        cin >> gender;
        cout <<"Enter your age :"<<endl;
        cin >> age;
    }
    void displayInfo(){
        cout<< "Passenger Information:"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Gender: "<<gender<<endl;
        cout <<"Age: "<<age<<endl;
        cout <<"--------------------------"<<endl;
    }
    string getCurrentLocation(){
        return currentLocation;
    }
    string getArrivalLocation(){
        return arrivalLocation;
    }
};

#endif //UNTITLED2_PASSENGER_H
