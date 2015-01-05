#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "PeopleUtil.h"
#include "PersonException.h"

using namespace std;

 EnhancedPerson getByEGN(const string &egn, const vector<EnhancedPerson> &people) {
		
	for(long i=0; i<(long) people.size(); ++i) {
		if(egn.compare(people.at(i).getEGN()) == 0) {
			return people.at(i);			 
		}
	}

	throw PersonException("No people were found having that EGN");	
}

vector<EnhancedPerson> getByAddress(const string &address, const vector<EnhancedPerson> &people) {
	vector<EnhancedPerson> retval;
	for(long i=0; i<(long) people.size(); ++i) {
		int count = people.at(i).addressCount();
		for(int j=0; j < count; ++j) {
			string test = people.at(i).getAddressByID(j);
			if(address.compare(test) == 0) {
				retval.push_back(people.at(i));
			}
		}
	}
	if(retval.empty()) {
		throw PersonException("No people were found at that address");
	}
	return retval;
}

void showByAddress(const string &address, const vector<EnhancedPerson> &people) {
	vector<EnhancedPerson> retval = getByAddress(address, people);
	for(long i=0; i<(long) retval.size(); ++i) {
		cout << retval.at(i);
	}
}

void showByEGN(const string &egn, const vector<EnhancedPerson> &people) {
	cout<< getByEGN(egn, people);
}

void saveInFile(const string &fileName, vector<EnhancedPerson> &people) {
	ofstream file;
	file.open(fileName.c_str(), ios::out | ios::app);
	if(file.is_open()) {
		for(int i=0; i<(int) people.size(); ++i) {
			file << people.at(i);

		}
	}
	else{
		throw PersonException("Could not open file");
	}

	file.close();
}
