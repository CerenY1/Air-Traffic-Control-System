#include "plane.h"
#include <string>
#include <iostream>

using namespace std;


int main(){
	CommercialPlane Pegasus1("Boeing-707",175,27.0,"a","b");
	Pegasus1.disPlayInfo();
	CommercialPlane Pegasus2("Boeing-707",300,65.0,"a","b");
	Pegasus2.disPlayInfo();
	CommercialPlane THY1("Boeing-707",250,30.0,"a","b");
	THY1.disPlayInfo();
	CommercialPlane THY2("Boeing-707",150,50.0,"a","b");
	THY2.disPlayInfo();
	PrivatePlane privatePlane( 4, "Cessna Citation", 8);
    CargoPlane cargo( 3, "Airbus A330", 200, 50.5);
    MilitaryPlane military( 4, "F-16", 1, 6);
	
	
	return 0; 
}
