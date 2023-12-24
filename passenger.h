#include <vector>
#include "Ticket.h"
#include <iostream>
using namespace std;

class Passenger{
	private:
		string name;
		string gender;
		int age;
		string currentLocation;
		string arrivalLocation;
		vector<Ticket> purchasedTickets;
		
	public:
		 /*string getName() { return name;}
        tring getGender() { return gender;}
        int getAge() { return age;}
        vector<Ticket> getPurchasedTickets() {return purchasedTickets;}
        void setName() {
			cout << "Enter your name: ";
			cin>>name;
		} // strcpy kaldır
        void setGender(string& g) {strcpy(gender, g);} // strcpy kaldır
        void getAge(int a) {age = a;} kaldırdık */ 
        void addTicket(Ticket& ticket) {purchasedTickets.push_back(ticket);}
		Passenger(string n, string g, int a) : name{n}, gender{g}, age{a} {
		}
		void addTicket(const Ticket& ticket) 
		{
        purchasedTickets.push_back(ticket);
        }
		void enterPassengerInfo(){
			cout << "Enter your current location: ";
			cin >> currentLocation;
			cout << "Enter where you want to go: ";
			cin >> arrivalLocation;
			cout << "Enter your name: ";
			getline(name);
			cout << "Enter your gender (M/F) :";
			cin >> gender;
			cout << "Enter your age: ";
			cin >> age; // 18 yaşından büyük küçük olma durumuna sonra bak.	
		}    	
    
};
