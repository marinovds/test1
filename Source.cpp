#include <iostream>
#include "PersonException.h"
#include "EnhancedPerson.h"

using namespace std;

int main() {
	try {
		EnhancedPerson me(Person("Az", "1234567890", "bau"));

		{
			EnhancedPerson me2 = me;
		}

		me.addAddress("Na baba ti meca");

		me.show();
	} catch (PersonException &e) {
	 cout << e.what() << endl;
	}



	return 0;
}
