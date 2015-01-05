#include <iostream>
#include <memory.h>

#include "EnhancedPerson.h"
#include "PersonException.h"

using namespace std;

EnhancedPerson::EnhancedPerson(const EnhancedPerson &ePerson): Person(ePerson) {	
	int count = ePerson.addressCount();
	char **temp = new char*[count + 2];

	char **p = ePerson.addresses;

	while (*p != NULL) {
		int length = strlen(*p) + 1;
		char* clone = new char[length];
		memcpy(clone, *p, length * sizeof(char));

		temp[p - ePerson.addresses] = clone;
		++p;
	}

	temp[p - ePerson.addresses] = NULL;
	addresses = temp;
}


EnhancedPerson::EnhancedPerson(const Person &p): Person(p) {
	addresses = new char*[2];

	int length = p.getAddress().length() + 1;
	addresses[0] = new char[length];
	memcpy(addresses[0], p.getAddress().c_str(), length * sizeof(char));

	addresses[1] = NULL;
}


EnhancedPerson::~EnhancedPerson() {
	char **p = addresses;
	
	while(*p != NULL) {
		delete[] *p;
		++p;
	}

	delete[] addresses;
}

void EnhancedPerson::addAddress(const char *address) {
	if (!isValidAddress(address)) {
		throw PersonException("Invalid address");
	}

	for(int i=0; i<addressCount(); ++i) {
		if(strcmp(getAddressByID(i), address) == 0 ) {
			throw PersonException("Address already exists");
		}
	}

	int length = strlen(address) + 1;
	char* clone = new char[length];
	memcpy(clone, address, length * sizeof(char));

	int count = addressCount();
	char **temp = new char*[count + 2];
	memcpy(temp, addresses, count * sizeof(char *));

	delete[] addresses;
	addresses = temp;

	addresses[count] = clone;
	addresses[count+1] = NULL;
}

int EnhancedPerson::addressCount() const {
	int count = 0;
	char **p = addresses;

	while (*p != NULL) {
		++count;
		++p;
	}

	return count;
}

ostream& operator<<(ostream &stream, const EnhancedPerson &ePerson) {
	stream << "Name: " << ePerson.getName() << endl;
	stream << "EGN: " << ePerson.getEGN() << endl;
	stream << "Main address: " << ePerson.getAddress() << endl;
	stream << "All addresses: " << endl;
	for(int i=0; i<ePerson.addressCount(); ++i) {

		stream << ePerson.getAddressByID(i) << endl;

	}
	return stream;
}

void EnhancedPerson::show() {
	cout  << *this << endl;
}

char** EnhancedPerson::getAdresses() const {
	return addresses;
}

char* EnhancedPerson::getAddressByID(const int &id) const {
	if(id > addressCount()){
		throw PersonException("Out of Bounds");
	}
	
	char** currP = addresses;	
	int count = 0;

	while(*currP != NULL) {
		if(count == id) {
			return *currP;
		}
		currP++;
		count++;
	}
	throw PersonException();
}
