#ifndef __XX_PERSON_EXCEPTION__
#define __XX_PERSON_EXCEPTION__

#include <exception>
#include <string>

class PersonException: public std::exception {
private:
	std::string reason;

public:
	PersonException(): reason("") {
	};

	PersonException(const char *what): reason(what) {
	};

	~PersonException() throw() {
	};

	const char *what() const throw() {
		return reason.c_str();
	};
};

#endif
