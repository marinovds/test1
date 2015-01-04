#ifndef __XX_ENHANCED_PERSON__
#define __XX_ENHANCED_PERSON__

#include <iostream>

#include "Person.h"

using namespace std;

class EnhancedPerson: public Person {
private:
	char** addresses;

public:
	EnhancedPerson(const Person &p);
	EnhancedPerson(const EnhancedPerson &ePerson);

	int addressCount() const;
	void addAddress(const char *address);
	char** getAdresses() const;
	~EnhancedPerson();
	void show();

	friend ostream& operator<<(ostream& stream, const EnhancedPerson &ePerson);
};

#endif
