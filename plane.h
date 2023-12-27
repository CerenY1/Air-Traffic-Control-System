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
    Plane(string depTime = " ", string estArrivalTime = " ", int duration = 0, const string mdl = "",
          int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "")
            : departureTime(formatTime2(depTime)), estimatedArrivalTime(formatTime2(estArrivalTime)),
              travelDuration(duration), model(mdl), passengerCapacity(capacity), price(price),
              departureCity(depCity), landingCity(landCity) {}

    string getArrivalCity(){
        return landingCity;
    }
    string getDepartureCity(){
        return departureCity;
    }

    // Helper function to convert string to tm:
    tm formatTime2(const string& timeStr) {
        tm parsedTime = {}; // Initialize all fields to 0
        // Code to parse the string and set the fields of parsedTime
        return parsedTime;
    }
    bool checkPlaneSt(Plane& plane){
        if (plane.PlaneSt == "Available")
            return 1;
        else
            return 0;
    }
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


};
class CommercialPlane : public Plane{
private:
    int ticketNum;
    int ticketPrice;
public:
    CommercialPlane(string depTime = " ", string estArrivalTime = " ", int duration = 0, const string mdl = "",
                    int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "")
            : Plane(depTime, estArrivalTime, duration, mdl, capacity, price, depCity, landCity) {
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
private:
    double cargoCapacity=0;
    double currentCargoWeight=0;
    int ticketPrice;
public:
    CargoPlane(string depTime = " ", string estArrivalTime = " ", int duration = 0, const string mdl = "",
               int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "")
            : Plane(depTime, estArrivalTime, duration, mdl, capacity, price, depCity, landCity) {
        ticketPrice = 100;
    }
    int getTicketPrice(){
        return ticketPrice;
    }
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

    MilitaryPlane(string depTime = " ", string estArrivalTime = " ", int duration = 0, const string mdl = "",
                  int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "")
            : Plane(depTime, estArrivalTime, duration, mdl, capacity, price, depCity, landCity) {}

    void displayInfo() {
        Plane::displayInfo();
        std::cout << "Weapon Capacity: " << weaponCapacity << " units" << std::endl;
    }

    void setMissionType(const string mission) {
        missionType = mission;
    }
};


#endif //UNTITLED2_PLANE_H
