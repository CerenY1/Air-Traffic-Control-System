#ifndef UNTITLED2_PLANE_H
#define UNTITLED2_PLANE_H
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

class Plane {
    friend class Staff;
    friend class Airport;
    friend class Ticket;
public:
    Plane(string depTime = " ", string  estimatedArrivalTime = " ", int duration = 0, const string mdl = "",
             int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "")
            : departureTime(depTime), travelDuration(duration), model(mdl),
              passengerCapacity(capacity), price(price), departureCity(depCity), landingCity(landCity) {}
    bool checkPlaneSt(Plane& plane){
        if (plane.PlaneSt == "Available")
            return 1;
        else
            return 0;
    }
protected:
    tm departureTime;
    tm estimatedArrivalTime;
    int travelDuration;
    int passengerCapacity;
    double price;
    string model;
    string departureCity;
    string landingCity;
    string PlaneSt;

    //calculate arrival time !!!!!

    void displayInfo() {
        char timeStr[10];
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &departureTime);
        cout << "Departure Time: " << timeStr << endl;
        cout << "Travel Duration: " << travelDuration/60 <<"."<< travelDuration%60<<" hours " << endl;
        cout << "Model: " << model << endl;
        cout << "Passenger Capacity: " << passengerCapacity << " passengers" << endl;
        cout << "Price: " << price << "$" << endl;
        cout<< "-------------------------------------------" <<endl;
    }
};
class CommercialPlane : public Plane{
    int ticketNum;
    int ticketPrice;
public:
    CommercialPlane(tm depTime = {}, tm estimatedArrivalTime = {}, int duration = 0, const string mdl = "",
                    int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "")
            : Plane(depTime, estimatedArrivalTime, duration, mdl, capacity, price, depCity, landCity) {
        ticketNum = 5;
        ticketPrice = 50;
    }
void disPlayInfo(){
    Plane::displayInfo();
}
void setTicketNum(int tickets){
        ticketNum -=tickets;}
int getTicketNum(){
        return ticketNum;
}
int getTicketPrice(){
        return ticketPrice;
    }

};

class PrivatePlane : public Plane {
public:
    friend class Staff;
    string pilotName;

   //constructor yaz!!!

    void pilotList(){
        cout<<"Choose pilot name: "<<endl;

    }
    void displayInfo() {
        Plane::displayInfo();
        cout << "Pilot: " << pilotName << std::endl;
    }
    void setPilotName(const string pilot) {
        pilotName = pilot;
    }
};

class CargoPlane : public Plane {
public:
    double cargoCapacity=0;
    double currentCargoWeight=0;

    CargoPlane(tm depTime = {}, tm estimatedArrivalTime = {}, int duration = 0, const string mdl = "",
               int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "")
            : Plane(depTime, estimatedArrivalTime, duration, mdl, capacity, price, depCity, landCity) {}
   void addCargo(double weight) {
       if (currentCargoWeight + weight <= cargoCapacity) {
           currentCargoWeight += weight;
           cout << "Cargo added. Current Cargo Weight: " << currentCargoWeight << " tons" <<endl;
       }
       else
           cout << "Cargo not added. Exceeds cargo capacity." <<endl;
   }
    void displayInfo() {
        Plane::displayInfo();
        cout << "Cargo Capacity: " << cargoCapacity << " tons" <<endl;
        //add cargoyu burada çalıştır!
    }
};

class MilitaryPlane : public Plane {
public:
    int weaponCapacity;
    string missionType;

    MilitaryPlane(tm depTime = {}, tm estimatedArrivalTime = {}, int duration = 0, const string mdl = "",
                  int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "")
            : Plane(depTime, estimatedArrivalTime, duration, mdl, capacity, price, depCity, landCity) {}

    void displayInfo() {
        Plane::displayInfo();
        std::cout << "Weapon Capacity: " << weaponCapacity << " units" << std::endl;
    }

    void setMissionType(const string mission) {
        missionType = mission;
    }
};


#endif //UNTITLED2_PLANE_H
