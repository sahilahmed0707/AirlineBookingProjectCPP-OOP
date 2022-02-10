#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <climits>
#include "Ticket.h"
using namespace std;

Flight* admin(string pass, Flight* flights, int* nf, Ticket* tickets, int* nt) {
	if (pass != Flight::pass)
	{
		cout << "Wrong password" << endl;
		return flights;
	}
	int men = 0, i;
	do
	{
		cout << "Admin Menu:" << endl
			<< "1. Display All Flights" << endl
			<< "2. Add a new Flight" << endl
			<< "3. Edit a Flight" << endl
			<< "4. Delete a Flight" << endl
			<< "5. Display All Occupants in a Flight" << endl
			<< "0. Exit from Admin Menu" << endl << "Input: " << endl;
		cin >> men;
		cout << "_______________________________________________________" << endl;
		if (men == 1) {
			for (i = 0; i < *nf; i++)
				flights[i].display();
		}
		else if (men == 2) {
			Flight f{};
			cout << "Flight number will be generated automatically" << endl;
			cout << "Enter Boarding Location: ";
			cin >> ws;
			getline(cin, f.boarding);
			cout << "Enter Destination: ";
			cin >> ws;
			getline(cin, f.destination);
			cout << "Enter Departure Time: ";
			cin >> ws;
			getline(cin, f.deptime);
			cout << "Enter Departure Date: ";
			cin >> ws;
			getline(cin, f.depdate);
			cout << "Enter Arrival Time: ";
			cin >> ws;
			getline(cin, f.arrtime);
			cout << "Enter Flying Time: ";
			cin >> ws;
			getline(cin, f.flytime);
			cout << "Enter Airline: ";
			cin >> ws;
			getline(cin, f.airline);
			cout << "Enter Total number of Bussiness class seats: ";
			cin >> f.totalBseats;
			cout << "Enter Total number of Economic class seats: ";
			cin >> f.totalEseats;
			f.availableBseats = f.totalBseats;
			f.availableEseats = f.totalEseats;
			cout << "Enter Economic class cost(Bussiness class cost will with 1.5 times Economic): ";
			cin >> f.cost;
			f.flightnumber = Flight::newflightnumber++;
			Flight* temp = new Flight[*nf + 1];
			for (i = 0; i < *nf; i++) {
				temp[i] = flights[i];
			}
			temp[*nf] = f;
			delete[] flights;
			flights = temp;
			temp = nullptr;
			delete[] temp;
			(*nf)++;
			cout << "Flight added:" << endl;
			flights[*nf - 1].display();
		}
		else if (men == 3) {
			cout << "Enter Flight number of the flight to be edited: ";
			int fn;
			cin >> fn;
			for (i = 0; i < *nf; i++)
				if (flights[i].flightnumber == fn)
					break;
			if (i == *nf) cout << "Flight not found" << endl;
			else {
				cout << "Flight found, Flight number cannot be changed" << endl;
				flights[i].display();
				cout << "Enter new Boarding Location: ";
				cin >> ws;
				getline(cin, flights[i].boarding);
				cout << "Enter new Destination: ";
				cin >> ws;
				getline(cin, flights[i].destination);
				cout << "Enter new Departure Time: ";
				cin >> ws;
				getline(cin, flights[i].deptime);
				cout << "Enter new Departure Date: ";
				cin >> ws;
				getline(cin, flights[i].depdate);
				cout << "Enter new Arrival Time: ";
				cin >> ws;
				getline(cin, flights[i].arrtime);
				cout << "Enter new Flying Time: ";
				cin >> ws;
				getline(cin, flights[i].flytime);
				cout << "Enter new Airline: ";
				cin >> ws;
				getline(cin, flights[i].airline);
				cout << "Enter new Total number of Bussiness class seats: ";
				cin >> flights[i].totalBseats;
				cout << "Enter new Total number of Economic class seats: ";
				cin >> flights[i].totalEseats;
				cout << "Enter new Available number of Bussiness class seats: ";
				cin >> flights[i].availableBseats;
				cout << "Enter new Available number of Economic class seats: ";
				cin >> flights[i].availableEseats;
				cout << "Enter new Economic class cost(Bussiness class cost will with 1.5 times Economic): ";
				cin >> flights[i].cost;
				cout << "Flight details edited" << endl;
				flights[i].display();
			}
		}
		else if (men == 4) {
			cout << "Enter Flight number of the flight to be deleted : ";
			int temp;
			cin >> temp;
			for (i = 0; i < *nf; i++) {
				if (temp == flights[i].flightnumber)
					break;
			}
			if (i == *nf) {
				cout << "Flight not found" << endl;
			}
			else {
				cout << "Flight :" << flights[i].flightnumber << " deleted" << endl;
				int j = 0, f = i;
				Flight* temp = new Flight[*nf - 1];
				for (j = 0, i = 0; j < *nf; j++, i++) {
					if (j == f)
					{
						if (j == (*nf) - 1) {
							break;
						}
						i--;
					}
					else {
						temp[i] = flights[j];
					}
				}
				delete[] flights;
				flights = temp;
				temp = nullptr;
				delete[] temp;
				(*nf)--;
			}
		}
		else if (men == 5) {
			cout << "Enter Flight number of the flight of which occupants are to be displayed : ";
			int temp;
			cin >> temp;
			for (i = 0; i < *nf; i++) {
				if (temp == flights[i].flightnumber)
					break;
			}
			for (int j = 0; j < *nt; j++)
				if (tickets[j].flightnumber == temp)
					tickets[j].display(1);
		}
	} while (men != 0);
	return flights;
}


Flight* loadflight(Flight flights[], int* nf) {
	ifstream flightdb{ "./flights.txt" };
	if (!flightdb.is_open()) {
		cout << "Failed to load flights file, no data has been loaded" << endl;
		return flights;
	}
	else {
		int i, tidmax = INT_MIN, fidmax = INT_MIN;
		string s;
		if (!getline(flightdb, s)) {
			fidmax = 99999;
		}
		flightdb >> *nf;
		flights = new Flight[*nf];
		for (i = 0; i < *nf; i++) {
			flightdb >> flights[i];
			if (flights[i].getid() > fidmax) fidmax = flights[i].getid();
		}
		Flight::newflightnumber = fidmax + 1;
	}
	flightdb.close();
	cout << "Flight Data loaded" << endl;
	return flights;
}

Ticket* loadtickets(int* nt, Ticket tickets[]) {
	ifstream ticketdb{ "./tickets.txt" };
	if (!ticketdb.is_open()) {
		cout << "Failed to load tickets file, no data has been loaded" << endl;
		return tickets;
	}
	else {
		int i, tidmax = INT_MIN;
		string s;
		if (!getline(ticketdb, s)) {
			tidmax = 999999;
		}
		ticketdb >> *nt;
		tickets = new Ticket[*nt];
		for (i = 0; i < *nt; i++) {
			ticketdb >> tickets[i];
			if (tickets[i].getid() > tidmax) tidmax = tickets[i].getid();
		}
		Ticket::newticketid = tidmax + 1;
	}
	ticketdb.close();
	cout << "Ticket Data loaded" << endl;
	return tickets;
}

void save(Flight* flights, int* nf, Ticket* tickets, int* nt) {
	ofstream flightdb{ "./flights.txt" }, ticketdb{ "./tickets.txt" };
	if (!flightdb.is_open()) {
		cout << "Failed to create flights file, no data has been saved" << endl;
		return;
	}
	else if (!ticketdb.is_open()) {
		cout << "Failed to create tickets file, no data has been saved" << endl;
		return;
	}
	else {
		int i;
		if ((*nf != 0) || (*nt) != 0) {
			flightdb << endl;
			ticketdb << endl;
			flightdb << *nf << endl;
			ticketdb << *nt << endl;
			for (i = 0; i < *nf; i++) {
				flightdb << flights[i];
			}
			for (i = 0; i < *nt; i++) {
				ticketdb << tickets[i];
			}
		}
	}
	flightdb.close();
	ticketdb.close();
	cout << "Data saved" << endl;
}

Ticket* book(Flight* flights, int* nf, Ticket* tickets, int* nt) {
	cout << "Enter flight number of flight of which the ticket is to be booked: ";
	int fn, i;
	cin >> fn;
	for (i = 0; i < *nf; i++) {
		if (fn == flights[i].getid())
			break;
	}
	if (i == *nf)
	{
		cout << "Flight not found" << endl;
		return tickets;
	}
	else {
		int type;
		cout << "Flight found" << endl;
		flights[i].display();
		cout << "1. Book Bussiness class seat of this flight" << endl
			<< "2. Book Economic class seat of this flight" << endl;
		cin >> type;
		if (type == 1 && flights[i].availableBseats == 0) {
			cout << "No seats available of Bussiness class" << endl;
			return tickets;
		}
		else if (type == 2 && flights[i].availableEseats == 0) {
			cout << "No seats available of Economic class" << endl;
			return tickets;
		}
		else {
			Ticket t{ flights[i] };
			cout << "Ticket number will be generated automatically" << endl;
			cout << "Enter Passenger Name: ";
			cin >> ws;
			getline(cin, t.pass_name);
			flights[i].cost = t.price;
			if (type == 1) {
				t.price *= 1.5;
				t.type = "Bussiness";
				t.seat = t.totalBseats - t.availableBseats + 1;
				flights[i].availableBseats--;
			}
			else if (type == 2) {
				t.availableEseats--;
			}
			t.id = Ticket::newticketid++;
			Ticket* temp = new Ticket[*nt + 1];
			for (i = 0; i < *nt; i++) {
				temp[i] = tickets[i];
			}
			temp[*nt] = t;
			delete[] tickets;
			tickets = temp;
			temp = nullptr;
			delete[] temp;
			(*nt)++;
			cout << "Ticket Booked:" << endl;
			t.display();
			return tickets;
		}
	}
}

int main()
{
	int nf = 0, nt = 0, men, i, exit = 0;
	Flight* flights = nullptr;
	Ticket* tickets = nullptr;

	do
	{
		cout << endl << "Main Menu:" << endl
			<< "1. View Ticket" << endl
			<< "2. View Flights" << endl
			<< "3. Book a New Ticket" << endl
			<< "4. Admin Menu" << endl
			<< "5. Load Data" << endl
			<< "6. Save Data" << endl
			<< "7. Contact Us" << endl
			<< "0. Exit" << endl
			<< "Input: ";
		cin >> men;
		cout << endl;
		if (men == 1) {
			if (nt == 0) {
				cout << "No tickets booked yet" << endl;
			}
			else {
				int tn;
				cout << "Enter Ticket number to be viewed : ";
				cin >> tn;
				for (i = 0; i < nt; i++) {
					if (tn == tickets[i].getid())
					{
						tickets[i].display();
						break;
					}
				}
				if (i == nt) {
					cout << "Ticket not found" << endl;
				}
			}
		}
		else if (men == 2) {
			if (nf == 0) {
				cout << "No flights found" << endl;
			}
			cout << nf << endl;
			for (i = 0; i < nf; i++)
				flights[i].display();
		}
		else if (men == 3) {
			exit = 0;
			if (nf == 0) {
				cout << "No flights found to book tickets" << endl;
			}
			else {
				tickets = book(flights, &nf, tickets, &nt);
			}
		}
		else if (men == 4) {
			exit = 0;
			string pass;
			cout << "Enter admin password:" << endl;
			cin >> ws;
			getline(cin, pass);
			Flight* temp = admin(pass, flights, &nf, tickets, &nt);
			flights = temp;
		}
		else if (men == 5) {
			tickets = loadtickets(&nt, tickets);
			flights = loadflight(flights, &nf);
			exit = 0;
		}
		else if (men == 6) {
			save(flights, &nf, tickets, &nt);
			exit = 1;
		}
		else if (men == 7) {
			cout << "Email : thedevelopers@airline.com" << endl
				<< "Phone : 0744-2735193" << endl
				<< "The Airline" << endl;
		}
		else if (men == 0) {
			if (exit == 0) {
				char c;
				cout << "No data has been saved. Do you want to save now?" << endl << "Y/N  :  ";
				cin >> ws;
				cin >> c;
				if (c == 'y' || c == 'Y')
					save(flights, &nf, tickets, &nt);
			}
		}
	} while (men != 0);

	cout << "####################          Thank You           #################" << endl;

	return 0;
}

/*

#Add#

Indore
Mumbai
11:30
19/11/2020
16:30
5:00
Air India
200
300
10000

Bhopal
Jaipur
10:30
19/11/2020
13:30
3:00
Jet Airways
200
300
5000

#Edit#

Indore
Gwalior
12:30
20/11/2020
15:00
2:30
Air India
250
350
250
350
6000
*/

/*
4
This is the password
2
Delhi
Mumbai
11:30
19/11/2020
16:30
5:00
Air India
200
300
10000
2
Kota
Jaipur
10:30
19/11/2020
13:30
3:00
Jet Airways
200
300
5000
0
3
100001
1
Sahil
*/