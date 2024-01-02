#ifndef UNTITLED2_METEOROLOGY_H
#define UNTITLED2_METEOROLOGY_H
#include <iostream>
#include <cstdlib>//for the random values
#include <ctime>
using namespace std;

//sicaklik, rüzgar hizini ve havanin sisli olup olmadigini "kendisi atar", kullanici degistiremez
//tüm hava sartlarının uygun olup olmadiğina karar verir ve chechWeather fonksiyonuyla return eder

class Meteorology{

protected:
    float temperature;
    float windSpeed;
public:
    Meteorology(){
        srand(static_cast<unsigned>(time(0)));
        temperature = rand()%60;
        windSpeed = rand()%60;
    }
    float getTemperature(){
        return temperature;
    }
    float getWindSpeed(){
        return windSpeed;
    }
    void printWeatherInfo(){

        cout<<"----today's weather info----"<<endl<<endl;
        cout<<"temperature: "<<temperature<<" C"<<endl;
        cout<<"wind speed: "<<windSpeed<<" km/h"<<endl<<endl;
    }
    bool checkWeather(){//havadaki sis durumuna ve rüzgar hızına göre uçus uygunluðuna kara verir.
        if(windSpeed<41) {
            cout << "weather is VALID for the flight." << endl;
            return 1;
        }
        else{
            cout << "weather is INVALID for the flight." << endl;
            return false;
        }
    }
};
#endif //UNTITLED2_METEOROLOGY_H
