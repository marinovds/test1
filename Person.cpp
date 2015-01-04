#include <iostream>
#include <string>

#include "PersonException.h"
#include "Person.h"

using namespace std;

bool Person::isValidEGN(const string &egn) {
	if (egn.length() != 10) {
		return false;
	}

	if (egn.find_first_not_of("0123456789") != string::npos) {
		return false;
	}
	
	return true;
}

bool Person::isValidAddress(const string &address) {
	return !address.empty();
}

bool Person::isValidName(const string &name) {
	return !name.empty();
}

void Person::show() {
	cout << *this;
}

Person::Person(const string &name, const string &EGN, const string &address) {
	if (!(isValidEGN(EGN) && isValidAddress(address) && isValidName(name))) {
		throw PersonException();
	}

	this->EGN = EGN;
	this->name = name;
	this->address = address;
}

Person::~Person() {

}

ostream& operator<<(ostream &stream, const Person &person) {
	stream << "Name: " << person.name << endl;
	stream << "EGN: " << person.EGN << endl;
	stream << "Main address: " << person.address << endl;

	return stream;
}

string Person::getAddress() const {
	return address;
}

string Person::getEGN() const {
	return EGN;
}