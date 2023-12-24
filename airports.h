#include <iostream>
#include <string>
#include <vector>
#include "plane.h"
#include "meteorology.h"
using namespace std;

class Airport{	
	private:			
		string airportName;
		vector <Plane> arrivingPlanes;
		vector <Plane> leavingPlanes;
		const istToPar = 300;
		const istToNy = 200;
		const parToNy = 250;	
		Airport(const string name):airportName(name){}	
	public:
		
		void printWelcomeAirport(Meteorology& todaysWeather){
			cout<<"-------------welcome to "<<this->airportName <<" airport--------------"<<endl<<endl<<endl;
			todaysWeather.printWeatherInfo();
			cout << "TIME : " << ctime(&timeNow1);
		}
		void setAirportName(string name){
			airportName = name;
		}
		void printAirportInfo(){
			time_t timeNow1 = time(NULL);
			int rowNum = 1;
			cout<<todaysWeather.printWeatherInfo()<<endl;
			cout<<left<<setw(20) <<"Flight Number"
				<<setw(20)	<< "Flight"
                <<setw(20) << "Departure City"
                <<setw(20)<< "Landing City"
                <<setw(20) << "Departure Time"
                <<setw(20) << "Arrival Time" 
				<<setw(20)<<"Status"<< endl;
        	for (const auto& plane : arrivingPlanes) {
            cout<< setw(5) << rowNumber++
				<<setw(20)<<plane.model
                <<setw(20)<<plane.departureCity
                <<setw(20)<<plane.landingCity
                <<setw(20)<<plane.departureTime
                <<setw(20)<<plane.estimatedArrivalTime
				<<setw(20)<<plane.planeSt<<endl;
        	}
        	for (const auto& plane : leavingPlanes) {
            cout<< setw(5) << rowNumber++
				<<setw(20)<<plane.model
                <<setw(20)<<plane.departureCity
                <<setw(20)<<plane.landingCity
                <<setw(20)<<plane.departureTime
                <<setw(20)<<plane.estimatedArrivalTime
				<<setw(20)<<plane.planeSt<<endl;
        	}
    	}
		vector <Plane> getArrivingPlanes(){
			return arrivingPlanes;
		}
		void addArrivingPlaneToAirport(Plane p1){
			arrivingPlanes.push_back(p1);
		}
		void addLeavingPlaneToAirport(Plane p1){
			leavingPlanes.push_back(p1);
		}
		void checkFlights(){
			time_t timeNow = time(NULL);
			for (int i=0; i<this->arrivingPlanes.size(); i++){
				if(timeNow == arrivingPlanes(i).estimatedArrivalTime || timeNow > arrivingPlanes(i).estimatedArrivalTime)
					deletePlaneFromAirport(arrivingPlanes(i));
			}
		}
		int findDistance(string city1, string city2){
			
			if((city1 == "istanbul" && city2 == "newyork")||(city1 == "newyork" && city2 == "istanbul"))
				return istToNy;
			else if ((city1 == "istanbul" && city2 == "paris")||(city1 == "paris" && city2 == "istanbul"))
				return istToPar;
			else if ((city1 == "paris" && city2 == "newyork")||(city1 == "newyork" && city2 == "paris"))
				return parToNy;
		}						 	
};
