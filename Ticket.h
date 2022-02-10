#pragma once
#include "Flight.h"
class Ticket : public Flight
{
	friend ostream& operator<<(ostream& os, Ticket& t);
	friend istream& operator>>(istream& is, Ticket& t);
	friend Flight* admin(string pass, Flight* flights, int* nf, Ticket* tickets, int* nt);
	friend Ticket* book(Flight* flights, int* nf, Ticket* tickets, int* nt);
public:
	Ticket(Flight f = Flight{}, string pass_n = "\0", string type = "Economic", int seat = 0);
	~Ticket();
	static int newticketid;
	void display(int x = 0);
	int getid() { return id; }
private:
	string pass_name, type;
	int id, seat, price;
};


