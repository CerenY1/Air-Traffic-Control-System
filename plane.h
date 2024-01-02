#ifndef UNTITLED2_PLANE_H
#define UNTITLED2_PLANE_H
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

class Plane {
    friend class Staff;
    friend class Airport;
    friend class Ticket;

public:
    Plane(string depTime = " ", string estArrivalTime = " ", double duration = 0, const string mdl = "",
          int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "",const int sp = 0)
            : departureTime(formatTime2(depTime)), estimatedArrivalTime(formatTime2(estArrivalTime)),
              travelDuration(duration), passengerCapacity(capacity), price(price),
              departureCity(depCity), landingCity(landCity) ,speed(sp) {}

    string getArrivalCity() {
        return landingCity;
    }
    string getDepartureCity() {
        return departureCity;
    }
    int calculateArrivalTime(string c1, string c2) {
        int distance;
        if ((c1 == "newyork" && c2 == "paris") || (c1 == "paris" && c2 == "newyork")) {
            distance = 6000.0;
            travelDuration = distance / this->speed;
        } else if ((c1 == "newyork" && c2 == "istanbul") || (c1 == "istanbul" && c2 == "newyork")) {
            distance = 8000.0;
            travelDuration = distance / this->speed;
        } else if ((c1 == "paris" && c2 == "istanbul") || (c1 == "istanbul" && c2 == "paris")) {
            distance = 2000.0;
            travelDuration = distance / this->speed;
        }
        return travelDuration;
    }
    virtual void displayInfo()=0;
    tm formatTime2(const string& timeStr) {
        tm parsedTime = {};
        return parsedTime;
    }
    void setArrivalTime(const tm& time) {
        estimatedArrivalTime = time;
    }
    void setDepartureTime(const tm& time) {
        departureTime = time;
    }
    tm getDepartureTime() const {
        return departureTime;
    }
    void setPlaneSt(string planeSt) {
        PlaneSt = planeSt;
    }
    tm getEstimatedArrivalTime() const {
        return estimatedArrivalTime;
    }
    string getPlaneSt() {
        return PlaneSt;
    }
protected:
    tm departureTime;
    tm estimatedArrivalTime;
    int travelDuration;
    int passengerCapacity;
    double price;
    string departureCity;
    string landingCity;
    string PlaneSt;
    const int istToPar = 300;
    const int istToNy = 200;
    const int parToNy = 250;
    const int speed;
};
void Plane::displayInfo() {
    cout << "Departure Time: " << departureTime.tm_hour <<" "<<departureTime.tm_min<< endl;
    cout <<"Estimated arrival time: " << estimatedArrivalTime.tm_hour << " " << estimatedArrivalTime.tm_min<<endl;
    cout << "Travel Duration: "  << this->travelDuration << " minutes"<< endl;
    cout<< "-------------------------------------------" <<endl;
}

class CommercialPlane : public Plane {
private:
    int ticketNum;
    int ticketPrice;

public:
    CommercialPlane(string depTime = " ", string estArrivalTime = " ", double duration = 0, const string mdl = "",
                    int capacity = 0, double price = 250.0, const string depCity = "", const string landCity = "",const int sp = 100)
            : Plane(depTime, estArrivalTime, duration, mdl, capacity, price, depCity, landCity,sp) {
        ticketNum = 5;
        ticketPrice = 100;
    }
    void displayInfo(){
        cout <<"plane information:"<<endl;
        cout << "Model: Commertial Plane "<< endl;
        Plane::displayInfo();
    }
    void setTicketNum(int tickets) {
        ticketNum -= tickets;
    }
    int getTicketNum() {
        if (ticketNum < 0) {
            return 0;
        } else {
            return ticketNum;
        }
    }
    int getTicketPrice() {
        return ticketPrice;
    }
};

class PrivatePlane : public Plane {
public:
    friend class Staff;
    string pilotName;

    PrivatePlane(string depTime = " ", string estArrivalTime = " ", double duration = 0, const string mdl = "",
                 int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "",const int sp = 250)
            : Plane(depTime, estArrivalTime, duration, mdl, capacity, price, depCity, landCity,sp) {}

    string pilotList() {
        cout << "Choose pilot name: " << endl;
        cout << "Captain Alex Turner" << endl;
        cout << "Captain Emily Mitchell" << endl;
        cout << "Captain Javier Rodriguez" << endl;
        cin.ignore();
        cout << "Captain ";
        getline(cin, this->pilotName);
        return pilotName;
    }
    void displayInfo() {
        cout << "Pilot: " << "Captain "<<pilotName<< endl;
        Plane::displayInfo();
    }
};

class CargoPlane : public Plane {
private:
    int cargoCapacity = 1000;
    int currentCargoWeight = 0;
    int ticketPrice = 100;

public:
    CargoPlane(string depTime = " ", string estArrivalTime = " ", double duration = 0, const string mdl = "",
               int capacity = 0, double price = 100.0, const string depCity = "", const string landCity = "",const int sp = 150)
            : Plane(depTime, estArrivalTime, duration, mdl, capacity, price, depCity, landCity,sp) {
        ticketPrice = 100;
    }
    int getTicketPrice() {
        return ticketPrice;
    }
    int getCargoCapacity(){
        return cargoCapacity;
    }
    void addCargo(int weight) {
        if (currentCargoWeight + weight <= cargoCapacity) {
            currentCargoWeight += weight;
            cargoCapacity -=weight;
            cout << "Cargo added. Current Cargo Weight: " << currentCargoWeight << " kilograms" << endl;
        } else
            cout << "Cargo not added. Exceeds cargo capacity." << endl;
    }
    void displayInfo() {
        cout << "Cargo Capacity Left : " << cargoCapacity << " tons" <<endl;
        cout << "Model : Cargo Plane"<<endl;
        Plane::displayInfo();
    }
};
#endif
