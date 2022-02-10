#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <climits>

using namespace std;

class Ticket;
class Flight
{
	friend ostream& operator<<(ostream& os, Flight& f);
	friend istream& operator>>(istream& is, Flight& f);
	friend Flight* admin(string pass, Flight* flights, int* nf, Ticket* tickets, int* nt);
	friend Ticket* book(Flight* flights, int* nf, Ticket* tickets, int* nt);
public:
	Flight(string boarding = "\0", string destination = "\0", string deptime = "\0", string depdate = "\0", string arrtime = "\0", string flytime = "\0", string airline = "\0", int totalBseats = 0, int totalEseats = 0, int availableBseats = 0, int availableEseats = 0, int flightnumber = 0, int cost = 0);
	~Flight();
	static int newflightnumber;
	void display();
	int getid() { return flightnumber; }
protected:
	string boarding, destination, deptime, depdate, arrtime, flytime, airline;
	int totalBseats, totalEseats, availableBseats, availableEseats, flightnumber, cost;
	static string pass;
};
