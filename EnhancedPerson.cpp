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
	char **i = ePerson.addresses;

	while (*i != NULL) {
		stream << *i << endl;
		i++;
	}

	return stream;
}

void EnhancedPerson::show() {
	EnhancedPerson::Person::show();
	cout << "All Adresses:" << *this << endl;
}

char** EnhancedPerson::getAdresses() const {
	return addresses;
}
