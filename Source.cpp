#include <iostream>
#include <vector>

#include "PersonException.h"
#include "EnhancedPerson.h"
#include "PeopleUtil.h"

using namespace std;

int main() {
	try {
		vector<EnhancedPerson> them;
		vector<EnhancedPerson> test;
		EnhancedPerson me(Person("Az", "1234567890", "bau"));
		EnhancedPerson you(Person("Ti", "1234567891", "mqu"));
		
		EnhancedPerson he(Person("Toi", "1234567892", "tau"));
		
		EnhancedPerson she(Person("Tq", "1234567893", "hau"));
		
		EnhancedPerson it(Person("To", "1234567894", "uau"));
		

		me.addAddress("Na baba ti meca");
		me.addAddress("kkk");
		me.addAddress("aaa");
		you.addAddress("bau");
		he.addAddress("kkk");
		them.push_back(me);
		them.push_back(you);
		them.push_back(he);
		them.push_back(she);
		them.push_back(it);

		// showByAddress("bau", them);
		// showByEGN("1234567893", them);
		me.show();

		saveInFile("delme.txt", them);

		
	} catch (PersonException &e) {
	 cout << e.what() << endl;
	}



	return 0;
}
