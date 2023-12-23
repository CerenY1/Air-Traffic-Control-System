#include <iostream>
#include <cstdlib>//for the random values
#include <ctime>
using namespace std;

//sýcaklýðý, rüzgar hýzýný ve havanýn sisli olup olmadýðýný "kendisi atar", kullanýcý deðiþtiremez
//tüm hava þartlarýnýnýn uygun olup olmadýðýna karar verir ve chechWeather fonksiyonuyla return eder

class Meteorology{
	
	protected:
		float temperature;
		float windSpeed;
		bool fog;
	public:
		Meteorology(){
	 		srand(static_cast<unsigned>(time(0)));
	 		temperature = rand()%60;
	 		windSpeed = rand()%60;
	 		fog = rand()%2;
		}
		float getTemperature(){
			return temperature;
		}
		float getWindSpeed(){
			return windSpeed;
		}
		bool getFog(){
			return fog;
		}
		void printWeatherInfo(){
			
			cout<<"----today's weather info----"<<endl<<endl;
			cout<<"temperature: "<<temperature<<" °C"<<endl;
			cout<<"wind speed: "<<windSpeed<<" km/h"<<endl;
			if(fog == 0)
			cout<<"not foggy"<<endl;
			else
			cout<<"foggy"<<endl;
		}
		bool checkWeather(){//havadaki sis durumuna ve rüzgar hýzýna göre uçuþ uygunluðuna kara verir.
			
			if(windSpeed<41){
				if(fog ==0){
					cout<<"weather is VALID for the flight."<<endl;
					return 1;
				}	
				else{
                	cout << "weather is INVALID for the flight." << endl;
                	return false;
				}
			}
			else{
			cout<<"weather is INVALID for the flight."<<endl;
			return 0;
		}
    }
};
