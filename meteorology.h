#include <iostream>
#include <cstdlib>//for the random values
#include <ctime>
using namespace std;

//s�cakl���, r�zgar h�z�n� ve havan�n sisli olup olmad���n� "kendisi atar", kullan�c� de�i�tiremez
//t�m hava �artlar�n�n�n uygun olup olmad���na karar verir ve chechWeather fonksiyonuyla return eder

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
			cout<<"temperature: "<<temperature<<" �C"<<endl;
			cout<<"wind speed: "<<windSpeed<<" km/h"<<endl;
			if(fog == 0)
			cout<<"not foggy"<<endl;
			else
			cout<<"foggy"<<endl;
		}
		bool checkWeather(){//havadaki sis durumuna ve r�zgar h�z�na g�re u�u� uygunlu�una kara verir.
			
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
