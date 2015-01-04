#ifndef __XX_PEOPLE_UTIL__
#define __XX_PEOPLE_UTIL__

#include <iostream>
#include <vector>
#include <string>


#include "EnhancedPerson.h"

using namespace std;

vector<EnhancedPerson> getByAddress(const string &address, const vector<EnhancedPerson> &people);
EnhancedPerson getByEGN(const string &egn, const vector<EnhancedPerson> &people);
void showByAddress(const string &address, const vector<EnhancedPerson> &people);
void showByEGN(const string &egn, const vector<EnhancedPerson> &people);
void saveInFile(const string &fileName, vector<EnhancedPerson> &people);


#endif
