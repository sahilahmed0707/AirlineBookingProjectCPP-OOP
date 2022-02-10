#include "Ticket.h"
Ticket::Ticket(Flight f, string pass_n, string type, int seat)
	:Flight{ f }, pass_name{ pass_n }, type{ type }, id{ newticketid }, seat{ totalEseats - availableEseats + 1 }, price{ cost }
{
	if (type == "Bussiness") price *= 1.5;
}

Ticket::~Ticket()
{
}

int Ticket::newticketid = 1000000;

ostream& operator<<(ostream& os, Ticket& t) {
	os << t.boarding << endl << t.destination << endl << t.deptime << endl << t.depdate << endl << t.arrtime << endl << t.flytime << endl << t.airline << endl << t.pass_name << endl << t.type << endl;
	os << t.flightnumber << " " << t.id << " " << t.seat << " " << t.price << endl;
	return os;
}
istream& operator>>(istream& is, Ticket& t) {
	is >> ws;
	getline(is, t.boarding);
	is >> ws;
	getline(is, t.destination);
	is >> ws;
	getline(is, t.deptime);
	is >> ws;
	getline(is, t.depdate);
	is >> ws;
	getline(is, t.arrtime);
	is >> ws;
	getline(is, t.flytime);
	is >> ws;
	getline(is, t.airline);
	is >> ws;
	getline(is, t.pass_name);
	is >> ws;
	getline(is, t.type);
	is >> t.flightnumber >> t.id >> t.seat >> t.price;
	return is;
}

void Ticket::display(int x) {
	if (x == 0) {
		cout << "#################################################################################################################################" << endl;
		cout << "#                                                                                                                               #" << endl;
		cout << "#                                               " << left << setw(50) << airline << "                              #" << endl;
		cout << "#   Ticket Number : " << id << "                                                    Flight Number : " << flightnumber << "                           #" << endl;
		cout << "#   Passenger Name: " << setfill(' ') << setw(50) << pass_name << "         Seat Type : " << setw(9) << type << "      Seat Number : " << type.at(0) << setw(4) << seat << "   #" << endl;
		cout << "#   From : " << right << setw(20) << boarding << "      to      " << left << setw(20) << destination << "              Price: " << setw(7) << price << "                                   #" << endl;
		cout << "#   Departure :" << right << setw(10) << deptime << " " << left << setw(12) << depdate << "       Flying Time : " << setw(10) << flytime << "          Arrival Time : " << right << setw(10) << arrtime << "                        #";;
		cout << endl << "#                                                                                                                               #" << endl;
		cout << "#################################################################################################################################" << endl;
	}
	if (x == 1) {
		cout << "____________________________________________________________________________________________________" << endl;
		cout << "Ticket Number: " << id << "  Flight Number: " << flightnumber << "  Airline: " << airline << "  From " << boarding << " to " << destination << " " << endl;
		cout << " Departure: " << deptime << " " << depdate << "  Arrival: " << arrtime << " Flying time : " << flytime << endl;
		cout << "Passenger Name : " << pass_name << " Seat Type : " << type << " Seat Number : " << type.at(0) << seat << " Cost: " << price << endl;
		cout << "____________________________________________________________________________________________________" << endl;
	}
}