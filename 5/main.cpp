#include <iostream>
#include <cstdlib>
#include "phone.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
using namespace phone;

void OutputVector(vector<Phone>);
bool Comparator (Phone p1, Phone p2);
void SortByAlphabet (vector<Phone> &vect);

int main() {
	ifstream ifs("input.txt");
	int n;
	ifs >> n;
	vector <Phone> DataList;
	for (int i = 0; i < n; ++i) {
		char fname[20];
		char lname[20];
		char sname[20];
		char number[20];
		char address[20];
		double ttown;
		double tinter;
		ifs >> number >> fname >> lname >> sname >> address;
		ifs >> ttown >> tinter;
		Phone p1(number, fname, sname, lname, address, ttown, tinter);
		DataList.push_back(p1);
	}
	ifs.close();
	// пункт а
	cout<< "_______________________Task a_________________________________\nEnter value: "; 
	double value;
	cin >> value;
	for (/*vector<Phone>::iterator */ auto it = DataList.begin(); it != DataList.end(); ++it) {
		if ( it -> IsTtownMore(value) ){
			it -> Show();
		}
			
	}

	// пункт б
	cout<<"__________________________________________Task b___________________________\n";
	for (auto it = DataList.begin(); it != DataList.end(); ++it) {
		if ( it -> IsUseTinter() ){
			it -> Show();
		}			
	}

	// пункт C
    cout<<"__________________________________________Task c____________________________\n";
    //sort(DataList.begin(), DataList.end(), Comparator);
	SortByAlphabet(DataList); 
	OutputVector(DataList);

	DataList.clear();
	return 0;		
}

