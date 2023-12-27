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
            cout << "Choose plane type:" << endl;
            cout << "1.Commercial Plane" << endl;
            cout << "2.Private Plane" << endl;
            cout << "3.Military Plane" << endl;
            cout << "4.Cargo Plane" << endl;
            cin >> choice2;
            if (choice2 == 1) {
                CommercialPlane *commercialPlane = new CommercialPlane;
                if (commercialPlane->getDepartureCity() == "istanbul" ||
                    commercialPlane->getArrivalCity() == "istanbul") {
                    istanbul.addPlaneToAirport(*commercialPlane);
                }
                if (commercialPlane->getDepartureCity() == "paris" || commercialPlane->getArrivalCity() == "paris") {
                    paris.addPlaneToAirport(*commercialPlane);

                }
                if (commercialPlane->getDepartureCity() == "newyork" ||
                    commercialPlane->getArrivalCity() == "newyork") {
                    newyork.addPlaneToAirport(*commercialPlane);
                }
            }
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
                        CargoTicket *ticket = new CargoTicket;
                        ticket->sellTicket(paris.CommercialPlanes[rowNum - paris.CommercialPlanes.size()]);
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


    cout << "Press 3 to return to main menu." << endl;
    cin >> choice;

}while(choice==3);



    return 0;
}
