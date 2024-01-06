#include <iostream>
#include <vector>
#include "plane.h"
#include "staff.h"
#include "airports.h"
#include "meteorology.h"
#include "passenger.h"
#include "ticket.h"
#include <string>

using namespace std;

int main() {
    int choice=0, choice2;
    Meteorology todaysWeather;
    Airport istanbul("ISTANBUL");
    Airport newyork("NEWYORK");
    Airport paris("PARİS");
    vector<Ticket> dynamicTicket;
    do {
        cout <<"---------AIR TRAFFIC CONTROL SYSTEM----------"<<endl;
        cout << "choose one:" << endl << "1-> Staff" << endl << "2-> Passenger" << endl<<endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                Staff staff;
                string planeType;
                todaysWeather.printWeatherInfo();
                planeType = staff.takeFlightInfo();
                if (planeType == "commercialPlane") {
                    if(todaysWeather.checkWeather()) {
                        static CommercialPlane commercialPlane;
                        staff.enterFlight(commercialPlane);
                        if ((commercialPlane.getArrivalCity() == "newyork" ||
                             commercialPlane.getDepartureCity() == "newyork")) {
                            newyork.CommercialPlanes.push_back(commercialPlane);
                        }
                        if ((commercialPlane.getDepartureCity() == "istanbul") ||
                            (commercialPlane.getArrivalCity() == "istanbul")) {
                            istanbul.CommercialPlanes.push_back(commercialPlane);
                        }
                        if ((commercialPlane.getDepartureCity() == "paris") ||
                            (commercialPlane.getArrivalCity() == "paris")) {
                            paris.CommercialPlanes.push_back(commercialPlane);
                        }

                    }
                } else if (planeType == "cargoPlane") {
                    if(todaysWeather.checkWeather()) {
                        static CargoPlane cargoPlane;
                        staff.enterFlight(cargoPlane);
                        if ((cargoPlane.getArrivalCity() == "newyork" || cargoPlane.getDepartureCity() == "newyork")) {
                            newyork.CargoPlanes.push_back(cargoPlane);
                        }
                        if ((cargoPlane.getDepartureCity() == "istanbul") ||
                            (cargoPlane.getArrivalCity() == "istanbul")) {
                            istanbul.CargoPlanes.push_back(cargoPlane);
                        }
                        if ((cargoPlane.getDepartureCity() == "paris") || (cargoPlane.getArrivalCity() == "paris")) {
                            paris.CargoPlanes.push_back(cargoPlane);
                        }
                    }
                }
                cout << "Press 3 to go back menu, 4 to exit" << endl;
                cin >> choice2;
                if (choice2 == 3)
                    break;
                else if (choice2 == 4)
                    return 0;
                break;
            }
            case 2: {
                int rowNum = 0;
                int planeChoice = 0;
                while (true) {
                    cout << "What type of ticket do you want to buy?" << endl;
                    cout << "1. commertial / cargo ticket" << endl;
                    cout << "2. rent private plane" << endl;
                    cin>>planeChoice;
                    if (planeChoice == 1) {
                        Passenger passenger;
                        passenger.enterPassengerInfo();
                        if (passenger.getCurrentLocation() == "istanbul") {
                            rowNum = 0;
                            istanbul.printWelcomeAirport(todaysWeather);
                            istanbul.printAirportInfo();
                            cout << "Choose the flight number to buy a ticket:";
                            while (rowNum == 0) {
                                cin >> rowNum;
                                if (rowNum > 0 && rowNum <= istanbul.CommercialPlanes.size()) {
                                    CommercialTicket *ticket = new CommercialTicket;
                                    int totalPrice = ticket->sellTicket(istanbul.CommercialPlanes[rowNum - 1]);
                                    Ticket ticket1;
                                    CommercialTicket commercialticket1;
                                    Ticket *ptrPlane = &ticket1;
                                    Ticket *ptrCommertialTicket = &commercialticket1;
                                    ptrPlane->showBill(totalPrice);
                                    ptrCommertialTicket->showBill(totalPrice);
                                    Plane *p;
                                    p = &istanbul.CommercialPlanes[rowNum - 1];
                                    p->displayInfo();
                                    passenger.displayInfo();
                                    dynamicTicket.push_back(CommercialTicket(*ticket));

                                } else if (rowNum > istanbul.CommercialPlanes.size() &&
                                           rowNum <= istanbul.CargoPlanes.size() + istanbul.CommercialPlanes.size()) {
                                    CargoTicket *ticket = new CargoTicket;
                                    int totalPrice = ticket->sellTicket(istanbul.CargoPlanes[rowNum - istanbul.CommercialPlanes.size() - 1]);
                                    Ticket ticket1;
                                    CargoTicket cargoticket1;
                                    Ticket *ptrPlane = &ticket1;
                                    Ticket *ptrCargoTicket = &cargoticket1;
                                    ptrPlane->showBill(totalPrice);
                                    ptrCargoTicket->showBill(totalPrice);
                                    Plane *p;
                                    p = &istanbul.CargoPlanes[rowNum - 1];
                                    p->displayInfo();
                                    passenger.displayInfo();
                                    dynamicTicket.push_back(CargoTicket(*ticket));
                                }
                            }
                        }
                        else if (passenger.getCurrentLocation() == "paris") {
                            rowNum = 0;
                            paris.printWelcomeAirport(todaysWeather);
                            paris.printAirportInfo();
                            cout << "Choose the flight number to buy a ticket:";
                            while (rowNum == 0) {
                                cin >> rowNum;
                                if (rowNum > 0 && rowNum <= paris.CommercialPlanes.size()) {
                                    CommercialTicket *ticket = new CommercialTicket;
                                    int totalPrice = ticket->sellTicket(paris.CommercialPlanes[rowNum - 1]);
                                    Ticket ticket1;
                                    CommercialTicket commercialticket1;
                                    Ticket *ptrPlane = &ticket1;
                                    Ticket *ptrCommertialTicket = &commercialticket1;
                                    ptrPlane->showBill(totalPrice);
                                    ptrCommertialTicket->showBill(totalPrice);
                                    Plane *p;
                                    p = &paris.CommercialPlanes[rowNum - 1];
                                    p->displayInfo();
                                    passenger.displayInfo();
                                    dynamicTicket.push_back(CommercialTicket(*ticket));
                                } else if (rowNum > paris.CommercialPlanes.size() &&
                                           rowNum <= paris.CargoPlanes.size() + paris.CommercialPlanes.size()) {
                                    CargoTicket *ticket = new CargoTicket;
                                    int totalPrice = ticket->sellTicket( paris.CargoPlanes[rowNum - paris.CommercialPlanes.size() - 1]);
                                    Ticket ticket1;
                                    CargoTicket cargoticket1;
                                    Ticket *ptrPlane = &ticket1;
                                    Ticket *ptrCargoTicket = &cargoticket1;
                                    ptrPlane->showBill(totalPrice);
                                    ptrCargoTicket->showBill(totalPrice);
                                    Plane *p;
                                    p = &paris.CargoPlanes[rowNum - 1];
                                    p->displayInfo();
                                    passenger.displayInfo();
                                    dynamicTicket.push_back(CargoTicket(*ticket));
                                }
                            }

                        } else if (passenger.getCurrentLocation() == "newyork") {
                            rowNum = 0;
                            newyork.printWelcomeAirport(todaysWeather);
                            newyork.printAirportInfo();
                            cout << "Choose the flight number to buy a ticket:";
                            while (rowNum == 0) {
                                cin >> rowNum;
                                if (rowNum > 0 && rowNum <= newyork.CommercialPlanes.size()) {
                                    CommercialTicket *ticket = new CommercialTicket;
                                    int totalPrice = ticket->sellTicket(newyork.CommercialPlanes[rowNum - 1]);
                                    Ticket ticket1;
                                    CommercialTicket commercialticket1;
                                    Ticket *ptrPlane = &ticket1;
                                    Ticket *ptrCommertialTicket = &commercialticket1;
                                    ptrPlane->showBill(totalPrice);
                                    ptrCommertialTicket->showBill(totalPrice);
                                    Plane *p;
                                    p = &newyork.CommercialPlanes[rowNum - 1];
                                    p->displayInfo();
                                    passenger.displayInfo();
                                    dynamicTicket.push_back(CommercialTicket(*ticket));

                                } else if (rowNum > newyork.CommercialPlanes.size() &&
                                           rowNum <= newyork.CargoPlanes.size() + newyork.CommercialPlanes.size()) {
                                    CargoTicket *ticket = new CargoTicket;
                                    int totalPrice = ticket->sellTicket(newyork.CargoPlanes[rowNum -newyork.CommercialPlanes.size() - 1]);
                                    Ticket ticket1;
                                    CargoTicket cargoticket1;
                                    Ticket *ptrPlane = &ticket1;
                                    Ticket *ptrCargoTicket = &cargoticket1;
                                    ptrPlane->showBill(totalPrice);
                                    ptrCargoTicket->showBill(totalPrice);
                                    Plane *p;
                                    p = &newyork.CargoPlanes[rowNum - 1];
                                    p->displayInfo();
                                    passenger.displayInfo();
                                    dynamicTicket.push_back(CargoTicket(*ticket));
                                }
                            }
                        } else
                            cout << "location not found.." << endl;
                        cout << "Press 3 to go back menu, 4 to exit" << endl;
                        cin >> choice2;
                        if (choice2 == 3)
                            break;
                        else if (choice2 == 4)
                            return 0;

                    } else if (planeChoice == 2) {
                        Staff richPassenger;
                        if (todaysWeather.checkWeather()) {
                            static PrivatePlane privatePlane;
                            richPassenger.enterFlight(privatePlane);

                            if ((privatePlane.getArrivalCity() == "newyork" ||
                                 privatePlane.getDepartureCity() == "newyork")) {
                                newyork.PrivatePlanes.push_back(privatePlane);
                            }
                            if ((privatePlane.getDepartureCity() == "istanbul") ||
                                (privatePlane.getArrivalCity() == "istanbul")) {
                                istanbul.PrivatePlanes.push_back(privatePlane);
                            }
                            if ((privatePlane.getDepartureCity() == "paris") ||
                                (privatePlane.getArrivalCity() == "paris")) {
                                paris.PrivatePlanes.push_back(privatePlane);
                            }
                            PrivateTicket *ticket = new PrivateTicket;
                            int totalPrice = 5000;
                            privatePlane.pilotList();
                            Ticket ticket1;
                            PrivateTicket privateTicket1;
                            Ticket *ptrPlane = &ticket1;
                            Ticket *ptrPrivateTicket = &privateTicket1;
                            ptrPlane->showBill(totalPrice);
                            ptrPrivateTicket->showBill(totalPrice);
                            privatePlane.displayInfo();
                            dynamicTicket.push_back(PrivateTicket(*ticket));
                        }
                    }
                    cout << "Press 3 to go back menu, 4 to exit" << endl;
                    cin >> choice2;
                    if (choice2 == 3)
                        break;
                    else if (choice2 == 4)
                        return 0;
                }
                break;
            }
            case 3:
                return 0;
            default:
                cout<<"invalid choice please try again..."<<endl;
                break;
        }
    }while(true);

dynamicTicket.clear();

    return 0;
}
