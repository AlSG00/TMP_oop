#include <iostream>
#include "Fiction.h"

using namespace std;

void Fiction::InData(ifstream& ifst)
{
	string Line;
	getline(ifst, Line); //Строка заносится в Line
	if (Line.length() < 50) { //Проверка на переполнение - если длина Line < 50
		strcpy_s(this->mDirector, 50, Line.c_str());
	}
	else {
		Line.resize(49);
		strcpy_s(this->mDirector, 50, Line.c_str());
	}
	Line.clear();
}

void Fiction::Out(ofstream& ofst)
{
	ofst << "It is FICTION movie called ";
	OutCommon(ofst);
	ofst << ", Director's name = " << this->mDirector << endl;
	ofst << "Count of vowels = " << VowelsCount() << endl;
}