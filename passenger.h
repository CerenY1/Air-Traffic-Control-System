#ifndef UNTITLED2_PASSENGER_H
#define UNTITLED2_PASSENGER_H

#include <vector>
#include "Ticket.h"
#include <iostream>
using namespace std;

class Passenger{
private:
    string name;
    string gender;
    int age;
    string currentLocation;
    string arrivalLocation;
    vector<Ticket> purchasedTickets;
public:
    Passenger(string n, string g, int a) : name{n}, gender{g}, age{a} {}
    string getName() { return name;}
    string getGender() { return gender;}
    int getAge() { return age;}
    void setName(string name1){name1 = this->name;}
    void setGender(string gender1){gender1 = this->gender;}
    void setAge(int age1){age1 = this->age;}
    void disPlayInfoCommercial(){
        cout << "Passenger's name:" << name << endl;
    }
    void disPlayInfoCargo(){
        cout << "Send by:" << name << endl;
    }
    void disPlayInfoPrivate(){
        cout << "Plane owner:" << name << endl;
    }
    void addTicket(Ticket& ticket) {purchasedTickets.push_back(ticket);}

    void enterPassengerInfo(){
        cout << "Enter your current location: ";
        cin >> currentLocation;
        cout << "Enter where you want to go: ";
        cin >> arrivalLocation;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin,name);
        cout << "Enter your gender (M/F) :";
        cin >> gender;
        cout << "Enter your age: ";
        cin >> age; // 18 yaşından büyük küçük olma durumuna sonra bak.
    }
};

#endif //UNTITLED2_PASSENGER_H
