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
		char** p = people.at(i).getAdresses();
		while(*p != NULL) {
			if(address.compare(*p)) {
				retval.push_back(people.at(i));
			}
			p++;
		}
	}
	if(retval.empty()) {
		throw PersonException("No people were found at that address");
	}
	return retval;
}

void showByAddress(const string &address, const vector<EnhancedPerson> &people) {
	for(long i=0; i<(long) people.size(); ++i) {
		char** p = people.at(i).getAdresses();
		while(*p != NULL) {
			if(address.compare(*p)) {
				cout<< people.at(i);
			}
		}
	}
}

void showByEGN(const string &egn, const vector<EnhancedPerson> &people) {
	for(long i=0; i<(long) people.size(); ++i) { 
		if(egn.compare(people.at(i).getEGN()) == 0) {
			cout<< people.at(i);
		}
	}
}

void saveInFile(const string &fileName, vector<EnhancedPerson> &people) {
	ofstream file;
	file.open(fileName.c_str());

	for(int i=0; i<(int) people.size(); ++i) {
		file << people.at(i);
	}

	file.close();
}
