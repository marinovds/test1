#ifndef __XX_PERSON__
#define __XX_PERSON__

#include <string>
#include <iostream>

using namespace std;

class Person {
private:
	string name;
	string EGN;
	string address;

public:
	Person(const string&, const string&, const string&);
	virtual ~Person();

	void show();

	string getAddress() const;
	string getEGN() const;
	string getName() const;

	friend ostream& operator<<(ostream &stream, const Person &person);
	
public:
	static bool isValidEGN(const string &egn);
	static bool isValidName(const string &name);
	static bool isValidAddress(const string &address);
};

#endif
