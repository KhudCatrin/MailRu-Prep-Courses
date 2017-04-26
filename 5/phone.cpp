#include <iostream>
#include <cstdlib>
#include "phone.h"
#include <cstring>
#include <cctype>
#include <vector>

using namespace phone;
using namespace std;

static bool IsCorrectString (const char *str) {
		while (*str != '\0' ) {
			if (!isdigit(*str)) {
			  return true;	
			}
			else return false;
			*str++;
		}
	}

//CONSTRUCTOR
Phone::Phone (const char* number, const char* fname, const char* sname, const char* lname, 
	const char* address, double ttown, double tinter) {

	number_ = new char[20];
	strncpy( number_, number, 20);

	fname_ = new char[20];
	strncpy( fname_, fname, 20); 
   
	sname_ = new char[20];
	strncpy (sname_ , sname, 20);

	lname_ = new char[20];
	strncpy (lname_ , lname, 20);

	address_ = new char[20];
	strncpy (address_ , address, 20);

	ttown_ = ttown;

	tinter_ = tinter;
} 
 
//COPY CONSTRUCTOR
Phone::Phone (const Phone &p) {
	number_ = new char[20];
	strncpy( number_, p.number_, 20);

	fname_ = new char[20];
	strncpy( fname_, p.fname_, 20);

	sname_ = new char[20];
	strncpy( sname_, p.sname_, 20);

	lname_ = new char[20];
	strncpy( lname_, p.lname_, 20);

	address_ = new char[20];
	strncpy( address_, p.address_, 20);
    
    ttown_ = p.ttown_;

	tinter_ = p.tinter_;
}

//DESTRUCTOR
Phone::~Phone() {
	delete[] number_;
	delete[] fname_;
	delete[] sname_;
	delete[] lname_;
	delete[] address_;
}

// GETTERS 
	char* Phone::GetFname() {
		if (*fname_ == '\0') {
			return nullptr;
		}
		return fname_;
	}

	char* Phone::GetSname() {
		if (*sname_ == '\0') {
			return nullptr;
		}
		return sname_;
	}

	char* Phone::GetLname() {
		if (*lname_ == '\0') {
			return nullptr;
		}
		return lname_;
	}

	char* Phone::GetAddress() {
		if (*address_ == '\0') {
			return nullptr;
		} 
		return address_;
	}

    double Phone::GetTtown() {
    	return ttown_;
    }

	double Phone::GetTinter() {
		return tinter_;
	}

//SETTERS
	void Phone::SetFname( char *val) {
		if (!IsCorrectString (val)) {
		 	return;
		 }
		 fname_ = strncpy(fname_, val, (strlen(val)+1));
	}

	void Phone::SetSname(char *val) {
		if (!IsCorrectString (val)) {
		 	return;
		 }
		 sname_ = strncpy(sname_, val, (strlen(val)+1));
	}

	void Phone::SetLname(char *val) {
		 if (!IsCorrectString (val)) {
		 	return;
		 }
		 lname_ = strncpy(lname_, val, (strlen(val)+1));
	}

	void Phone::SetAddress(char *val) {
		if (!IsCorrectString (val)) {
		 	return;
		 }
		 address_ = strncpy(address_, val, (strlen(val)+1));
	}

	void Phone::SetTtown(double val) {
		if (val < 0) {
			cout<<"Invalid value\n";
			return;
		}
		else
		 ttown_ = val;
		
	}

	void Phone::SetTinter(double val) {
		 if (val < 0) {
			cout<<"Invalid value\n";
			return;
		}
		else
		 tinter_ = val;
	}

// ADD THE TIME OF TALKINGS
	void Phone::AddTtown ( double val ) {
		ttown_ += val;
	}

	void Phone::AddTinter ( double val ) {
		tinter_ += val;
	}

//SHOW DATA
	void Phone::Show () {
		cout<<"\nNumber: "<<number_<<"\nLast name: "<<GetLname()<<"\nFirst name: "<<GetFname()<<
		"\nSecond name: "<<GetSname()<<"\nAddress: "<<GetAddress()<<"\nTime in town: "<<GetTtown()<<
		"\nTime between towns: "<<GetTinter()<<"\n\n";
	}

bool Phone::IsTtownMore(double val) {
	if (ttown_ > val) {
		return true;
	}
	else {
		return false;
	}
}

bool Phone::IsUseTinter() {
	if (tinter_ > 0 ) {
		return true;
	}
	else {
		return false;
    }
}

bool Comparator (Phone p1, Phone p2) {
	if (strcmp(p1.GetSname(), p2.GetSname()) > 0) {
		return false;
	}
	else if (strcmp(p1.GetSname(), p2.GetSname()) < 0) {
		return true;
	}
	else if (strcmp(p1.GetFname(), p2.GetFname()) > 0) {
		return false;
	}
	else if (strcmp(p1.GetFname(), p2.GetFname()) < 0) {
		return true;
	}
	else if (strcmp(p1.GetLname(), p2.GetLname()) > 0) {
		return false;
	}
	else return true;
}

void OutputVector(vector<Phone> p_v) {
	for (auto it = p_v.begin(); it != p_v.end(); ++it) {
		it -> Show();
	}
}

Phone& Phone::operator = (Phone& p1) {
	if (this == &p1) {
		return *this;
	}
	delete []number_;
	delete []fname_;
	delete []sname_;
	delete []lname_;
	delete []address_;
	number_ = new char[20];
	fname_ = new char[20];
	lname_ = new char[20];
	sname_ = new char[20];
	address_ = new char[20];
	strncpy(number_, p1.number_, 20);
	strncpy(fname_, p1.fname_, 20);
	strncpy(lname_, p1.lname_, 20);
	strncpy(sname_, p1.sname_, 20);
	strncpy(address_, p1.address_, 20);
	ttown_ = p1.ttown_;
	tinter_ = p1.tinter_;
	return *this;
}

// IT'S A BICYCLE! 
void SortByAlphabet (vector<Phone> &vect) {
	for (int i = 0; i < vect.size() - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < vect.size() - i - 1; j++) {
			if ( (strcmp(vect[j].GetLname(), vect[j + 1].GetLname()) > 0) || 
				( (strcmp(vect[j].GetLname(), vect[j + 1].GetLname()) == 0) && 
				  (strcmp(vect[j].GetFname(), vect[j + 1].GetFname()) > 0 ) ) 
				) {
				Phone temp(vect[j]);
				vect[j] = vect[j + 1];
				vect[j + 1] = temp;
				swapped = true;
			}		
		}
		if (!swapped) {
			break;
		}
	}
}