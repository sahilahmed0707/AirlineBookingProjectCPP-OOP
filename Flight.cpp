#include "Flight.h"

Flight::Flight(string boarding, string destination, string deptime, string depdate, string arrtime, string flytime, string airline, int totalBseats, int totalEseats, int availableBseats, int availableEseats, int flightnumber, int cost)
	:boarding{ boarding },
	destination{ destination },
	deptime{ deptime },
	depdate{ depdate },
	arrtime{ arrtime },
	flytime{ flytime },
	airline{ airline },
	totalBseats{ totalBseats },
	totalEseats{ totalEseats },
	availableBseats{ availableBseats },
	availableEseats{ availableEseats },
	flightnumber{ newflightnumber },
	cost{ cost } {
}

Flight::~Flight()
{
}

int Flight::newflightnumber = 100000;
string Flight::pass = "This is the password";

ostream& operator<<(ostream& os, Flight& f) {
	os << f.boarding << endl;
	os << f.destination << endl;
	os << f.deptime << endl;
	os << f.depdate << endl;
	os << f.arrtime << endl;
	os << f.flytime << endl;
	os << f.airline << endl;
	os << f.totalBseats << " " << f.totalEseats << " " << f.availableBseats << " " << f.availableEseats << " " << f.flightnumber << " " << f.cost << endl;
	return os;
}

istream& operator>>(istream& is, Flight& f) {
	is >> ws;
	getline(is, f.boarding);
	is >> ws;
	getline(is, f.destination);
	is >> ws;
	getline(is, f.deptime);
	is >> ws;
	getline(is, f.depdate);
	is >> ws;
	getline(is, f.arrtime);
	is >> ws;
	getline(is, f.flytime);
	is >> ws;
	getline(is, f.airline);
	is >> f.totalBseats >> f.totalEseats >> f.availableBseats >> f.availableEseats >> f.flightnumber >> f.cost;
	return is;
}

void Flight::display() {
	cout << "____________________________________________________________________________________________________________________________________________" << endl;
	cout << "Flight number : " << flightnumber << endl;
	cout << boarding << " to " << destination << " at " << deptime << " on " << depdate << ", arrives at destination at " << arrtime << ", after flying for " << flytime << " hours" << endl;
	cout << availableBseats << " out of " << totalBseats << " Bussiness class seats available and " << availableEseats << " out of " << totalEseats << " Economic class seats available " << endl;
	cout << "Airlines : " << airline << "  Bussiness class Price: " << cost * 1.5 << "    Economic class Price: " << cost << endl;
	cout << "____________________________________________________________________________________________________________________________________________" << endl;
}