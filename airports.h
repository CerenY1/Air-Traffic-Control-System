#include <iostream>
#include <string>
#include <vector>
#include "plane.h"
#include "meteorology.h"
using namespace std;

class irport{
	
	private:
			
		Meteorology todaysWeather;	
		string airportName;
		vector <Plane> arrivingPlanes;
		vector <Plane> leavingPlanes;
		const istToPar = 300;
		const istToNy = 200;
		const parToNy = 250;	
		Airport(const string name):airportName(name){}	
	public:
		
		void printAirportInfo(){
			time_t timeNow1 = time(NULL);
			cout << "TIME : " << ctime(&timeNow1);
			cout<<todaysWeather.printWeatherInfo()<<endl;
			cout<<left<<setw(20) << "Flight"
                <<setw(20) << "Departure City"
                <<setw(20)<< "Landing City"
                <<setw(20) << "Departure Time"
                <<setw(20) << "Arrival Time" 
				<<setw(20)<<"    "<< endl;
        	for (const auto& plane : arrivingPlanes) {
            cout<<setw(20)<<plane.model
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
		void addPlaneToAirport(Plane p1){
			arrivingPlanes.push_back(p1);
		}
		void deletePlaneFromAirport(Plane p1){
			Plane planeToDelete;
			auto planeToDelete = find(PlanesAtTheAirpot.begin(),PlanesAtTheAirpot.end(),p1);	
		}
		void checkFlights(vector <Plane>&arrivingPlanes, vector <Plane>&leavingPlanes){
			time_t timeNow = time(NULL);
			for (int i=0; i<arrivingPlanes.size(); i++){
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
	//while (true) {
    //    ucanUcuslariKontrolEt(ucuslar);
    //    cout << "Bir dakika bekleniyor..." <<endl;
    //    time_t start_time = time(NULL);
    //    while (time(NULL) - start_time < 5) {}  // 60 saniye bekleyin
    //}						 	
};
