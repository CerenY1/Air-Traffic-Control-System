#include <vector>
#include "Ticket.h"
using namespace std;

class Passenger{
	private:
		string name;
		string gender;
		int age;
		vector<Ticket> purchasedTickets;
		
	public:
		string getName() { return name;}
        string getGender() { return gender;}
        int getAge() { return age;}
        vector<Ticket> getPurchasedTickets() {return purchasedTickets;}
        void setName(string& n) { strcpy(name, n);}
        void setGender(string& g) {strcpy(gender, g);}
        void getAge(int a) {age = a;}
        void addTicket(Ticket& ticket) {purchasedTickets.push_back(ticket);}
		Passenger(string n, string g, int a) : name{n}, gender{g}, age{a} {
		}
		void addTicket(const Ticket& ticket) 
		{
        purchasedTickets.push_back(ticket);
        }

};
