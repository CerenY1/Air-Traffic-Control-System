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
    Plane(string depTime = " ", string estArrivalTime = " ", double duration = 0, const string mdl = "",
          int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "",const int sp = 0)
            : departureTime(formatTime2(depTime)), estimatedArrivalTime(formatTime2(estArrivalTime)),
              travelDuration(duration), model(mdl), passengerCapacity(capacity), price(price),
              departureCity(depCity), landingCity(landCity) ,speed(sp) {}

    string getArrivalCity(){
        return landingCity;
    }
    string getDepartureCity(){
        return departureCity;
    }
    int calculateArrivalTime(string c1, string c2) {
        int distance;
        int travelDuration;  // travelDuration'ı int olarak tanımla
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
        return travelDuration;  // int olarak döndür
    }

    void displayInfo() {
        char timeStr[10];
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &departureTime);
        cout << "Departure Time: " << timeStr << endl;
        cout << "Travel Duration: "  << travelDuration << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << "$" << endl;
        cout<< "-------------------------------------------" <<endl;
    }
    void setArrivalTime(const tm time){
        estimatedArrivalTime = time;
    }
    void setDepartureTime(const tm time){
        departureTime= time;
    }
    tm getDepartureTime(){
        return departureTime;
    }
    tm formatTime2(const string& timeStr) {
        tm parsedTime = {};
        return parsedTime;
    }
    tm getEstimatedArrivalTime(){
        return estimatedArrivalTime;
    }
    bool checkPlaneSt(){
        if (PlaneSt == "Available")
            return 1;
        else
            return 0;
    }

    string getPlaneSt(){
        return PlaneSt;
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
    const int istToPar = 300;
    const int istToNy = 200;
    const int parToNy = 250;
    const int speed;

};
class CommercialPlane : public Plane{
private:
    int ticketNum;
    int ticketPrice;
public:
    CommercialPlane(string depTime = " ", string estArrivalTime = " ", double duration = 0, const string mdl = "",
                    int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "",const int sp = 100)
            : Plane(depTime, estArrivalTime, duration, mdl, capacity, price, depCity, landCity,sp) {
        ticketNum = 5;
        ticketPrice = 100;
    }
    void disPlayInfo(){
        Plane::displayInfo();
    }
    void setTicketNum(int tickets){
        ticketNum -=tickets;
    }
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
    PrivatePlane(string depTime = " ", string estArrivalTime = " ", double duration = 0, const string mdl = "",
                 int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "",const int sp = 250)
            : Plane(depTime, estArrivalTime, duration, mdl, capacity, price, depCity, landCity,sp) {}

    string pilotList(){
        cout<<"Choose pilot name: "<<endl;
        cout<<"Captain Alex Turner"<<endl;
        cout<<"Captain Emily Mitchell"<<endl;
        cout<<"Captain Javier Rodriguez"<<endl;
        cin.ignore();
        getline(cin, pilotName);
        return pilotName;
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
    int cargoCapacity=0;
    int currentCargoWeight=0;
    int ticketPrice;
public:
    CargoPlane(string depTime = " ", string estArrivalTime = " ", double duration = 0, const string mdl = "",
               int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "",const int sp = 150)
            : Plane(depTime, estArrivalTime, duration, mdl, capacity, price, depCity, landCity,sp) {
        ticketPrice = 100;
    }
    int getTicketPrice(){
        return ticketPrice;
    }
    void addCargo(int weight) {
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
    MilitaryPlane(string depTime = " ", string estArrivalTime = " ", double duration = 0, const string mdl = "",
                  int capacity = 0, double price = 0.0, const string depCity = "", const string landCity = "",const int sp = 500)
            : Plane(depTime, estArrivalTime, duration, mdl, capacity, price, depCity, landCity,sp) {}
    void displayInfo() {
        Plane::displayInfo();
        std::cout << "Weapon Capacity: " << weaponCapacity << " units" << std::endl;
    }
    void setMissionType(const string mission) {
        missionType = mission;
    }
};
#endif //UNTITLED2_PLANE_H
