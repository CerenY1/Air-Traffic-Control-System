#include <iostream>
#include <vector>
#include "plane.h"
#include "staff.h"
#include "airport.h"
#include "meteorology.h"
#include "passenger.h"
#include "ticket.h"
#include <ctime>
#include <string>

using namespace std;

int main() {

    int choice, choice2;
    Meteorology todaysWeather;
    Airport istanbul("istanbul");
    Airport newyork("newyork");
    Airport paris("paris");
    do {
        cout << "choose one:" << endl << "1. Staff" << endl << "2. Passenger" << endl;
        cin >> choice;
        while (choice == 1) {
            Staff staff;
            string planeType;
            planeType = staff.takeFlightInfo();

            if (planeType == "commercialPlane"){
                static CommercialPlane commercialPlane;
                staff.enterFlight(commercialPlane);
                if ((commercialPlane.getArrivalCity() == "newyork"|| commercialPlane.getDepartureCity() == "newyork")) {
                   newyork.CommercialPlanes.push_back(commercialPlane);
                }
                if ((commercialPlane.getDepartureCity() == "istanbul")||(commercialPlane.getArrivalCity() == "istanbul")) {
                    istanbul.CommercialPlanes.push_back(commercialPlane);
                }
                if ((commercialPlane.getDepartureCity() == "paris")||(commercialPlane.getArrivalCity() == "paris")) {
                    paris.CommercialPlanes.push_back(commercialPlane);
                }
            }
            else if (planeType =="cargoPlane") {
                static CargoPlane cargoPlane;
                staff.enterFlight(cargoPlane);
                if ((cargoPlane.getArrivalCity() == "newyork"|| cargoPlane.getDepartureCity() == "newyork")) {
                    newyork.CargoPlanes.push_back(cargoPlane);
                }
                if ((cargoPlane.getDepartureCity() == "istanbul")||(cargoPlane.getArrivalCity() == "istanbul")) {
                    istanbul.CargoPlanes.push_back(cargoPlane);
                }
                if ((cargoPlane.getDepartureCity() == "paris")||(cargoPlane.getArrivalCity() == "paris")) {
                    paris.CargoPlanes.push_back(cargoPlane);
                }
            }
            else if(planeType =="militaryPlane") {
                static MilitaryPlane militaryPlane;
                staff.enterFlight(militaryPlane);
                if ((militaryPlane.getArrivalCity() == "newyork"|| militaryPlane.getDepartureCity() == "newyork")) {
                    newyork.MilitaryPlanes.push_back(militaryPlane);
                }
                if ((militaryPlane.getDepartureCity() == "istanbul")||(militaryPlane.getArrivalCity() == "istanbul")) {
                    istanbul.MilitaryPlanes.push_back(militaryPlane);
                }
                if ((militaryPlane.getDepartureCity() == "paris")||(militaryPlane.getArrivalCity() == "paris")) {
                    paris.MilitaryPlanes.push_back(militaryPlane);
                }
            }
            cout<< "press 3 to go back"<<endl;
            cin>>choice;
        }
        while (choice == 2) {
            Passenger passenger;
            passenger.enterPassengerInfo();
            int rowNum = 0;
            if (passenger.getCurrentLocation() == "istanbul") {
                istanbul.printWelcomeAirport(todaysWeather);
                while (rowNum == 0) {
                    istanbul.printAirportInfo();
                    cout << "enter the plane number to buy a ticket:";
                    cin >> rowNum;
                    if (rowNum <= istanbul.CommercialPlanes.size()) {
                        CommercialTicket *ticket = new CommercialTicket;
                        ticket->sellTicket(istanbul.CommercialPlanes[rowNum]);
                    } else {
                        CargoTicket *ticket = new CargoTicket;
                        ticket->sellTicket(istanbul.CargoPlanes[rowNum - istanbul.CargoPlanes.size()]);
                    }
                    cout << "waiting for update..." << endl;
                    cin >> rowNum;
                    time_t start_time = time(NULL);
                    while (time(NULL) - start_time < 60) {}
                }
            } else if (passenger.getCurrentLocation() == "paris") {
                paris.printWelcomeAirport(todaysWeather);
                while (rowNum == 0) {
                    paris.printAirportInfo();
                    cout << "enter the plane number to buy a ticket:";
                    cin >> rowNum;
                    if (rowNum <= paris.CommercialPlanes.size()) {
                        CommercialTicket *ticket = new CommercialTicket;
                        ticket->sellTicket(paris.CommercialPlanes[rowNum]);
                    } else {
                        int a;
                        CargoTicket *ticket = new CargoTicket;
                        a = rowNum - paris.CommercialPlanes.size();
                        ticket->sellTicket(paris.CargoPlanes[a]);
                    }
                    cout << "waiting for update..." << endl;
                    cin >> rowNum;
                    time_t start_time = time(NULL);
                    while (time(NULL) - start_time < 60) {}
                }

            } else if (passenger.getCurrentLocation() == "newyork") {
                newyork.printWelcomeAirport(todaysWeather);
                while (rowNum == 0) {
                    newyork.printAirportInfo();
                    cout << "enter the plane number to buy a ticket:";
                    cin >> rowNum;
                    if (rowNum >= newyork.CommercialPlanes.size()) {
                        CommercialTicket *ticket = new CommercialTicket;
                        ticket->sellTicket(newyork.CommercialPlanes[rowNum]);
                    } else {
                        CargoTicket *ticket = new CargoTicket;
                        ticket->sellTicket(newyork.CargoPlanes[rowNum - newyork.CommercialPlanes.size()]);
                    }
                    cout << "waiting for update..." << endl;
                    cin >> rowNum;
                    time_t start_time = time(NULL);
                    while (time(NULL) - start_time < 60) {}
                }

            } else
                cout << "location not found.." << endl;
        }
    }while(choice==3);

    return 0;
}
