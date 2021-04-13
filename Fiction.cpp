#include <iostream>
#include "Fiction.h"

using namespace std;

void Fiction::InData(ifstream& ifst)
{
	string Line;
	getline(ifst, Line);
	Line.resize(49);
	strcpy_s(this->mDirector, 50, Line.c_str());
	Line.clear();
}

void Fiction::Out(ofstream& ofst)
{
	ofst << "It is FICTION movie called ";
	OutCommon(ofst);
	ofst << ", Director's name = " << this->mDirector;
	OutCountry(ofst);
	ofst << ", Count of vowels = " << VowelsCount() << endl;
}